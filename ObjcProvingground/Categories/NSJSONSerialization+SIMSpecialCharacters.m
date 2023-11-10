//
//  NSJSONSerialization+SIMSpecialCharacters.m
//  PGTalk
//
//  Created by wdcx on 2020/9/9.
//  Copyright © 2020  . All rights reserved.
//

#import "NSJSONSerialization+SIMSpecialCharacters.h"
#import <objc/runtime.h> // This is where the Objective-C runtime functions are declared
@implementation NSJSONSerialization (SIMSpecialCharacters)

+ (void)load {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        Method originalMethod = class_getClassMethod(self, @selector(JSONObjectWithData:options:error:));
        Method swizlledMethod = class_getClassMethod(self, @selector(sc_JSONObjectWithData:options:error:));
        method_exchangeImplementations(originalMethod, swizlledMethod);
    });
}

+ (id)sc_JSONObjectWithData:(NSData *)data
                    options:(NSJSONReadingOptions)opt
                      error:(NSError * _Nullable __autoreleasing *)error
{
    if ([[data class] isMemberOfClass:[NSDictionary class]])
        return data;
 
    if (![data isKindOfClass:[NSData class]]) {
        return nil;
    }
    
    if ([data length] <= 0) {
        return nil;
    }
    id responseObject = nil;
    @try {
        NSError *serializationError = nil;
        responseObject = [self sc_JSONObjectWithData:data options:opt error:&serializationError];
        if (!responseObject) {
            if (error) {
                *error = serializationError;
            }
            
            if (serializationError && serializationError.code == 3840) {
                NSString *serializationString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
                if (!serializationString) {
                    return nil;
                }
                serializationString = [serializationString stringByReplacingOccurrencesOfString:@"(\\r\\n|\\r|\\n)" withString:@"\\\\r" options:NSRegularExpressionSearch range:NSMakeRange(0, serializationString.length)];
                
                NSData *serializationData = [serializationString dataUsingEncoding:NSUTF8StringEncoding];
                responseObject = [self sc_JSONObjectWithData:serializationData options:opt error:nil];
    #ifndef DEBUG
                if (responseObject && error) {
                    *error = nil;
                }
    #endif
            }
        }
    } @catch (NSException *exception) {
        responseObject = nil;
    } @finally {
        
    }
    
    return responseObject;
}

@end

