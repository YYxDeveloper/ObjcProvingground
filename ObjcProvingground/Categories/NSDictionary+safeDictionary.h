//
//  NSDictionary+safeDictionary.h
//  JSJJ_iPhone
//
//  Created by sky on 13-5-13.
//  Copyright (c) 2013年 magus. All rights reserved.
//

#import <Foundation/Foundation.h>
extern NSString * const kEmptyString;

@interface NSDictionary (safeDictionary)

// magus: return nil if the object is NSNull or not a NSNumber
- (NSNumber *)numberForKey:(id)key;

- (NSString *)stringForKey:(id)key;

// magus: return nil if the object is NSNull or not a NSDictionary
- (NSDictionary *)dictionaryForKey:(id)key;

// magus: return nil if the object is null or not a NSArray.
- (NSMutableArray *)arrayForKey:(id)key;

- (NSData *)dataForKey:(id)key;
@end
