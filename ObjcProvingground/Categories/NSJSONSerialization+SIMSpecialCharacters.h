//
//  NSJSONSerialization+SIMSpecialCharacters.h
//  PGTalk
//
//  Created by wdcx on 2020/9/9.
//  Copyright © 2020  . All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSJSONSerialization (SIMSpecialCharacters)

+ (id)sc_JSONObjectWithData:(NSData *)data options:(NSJSONReadingOptions)opt error:(NSError * _Nullable __autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
