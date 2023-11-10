//
//  NSString+md5.m
//  WenMingShuo
//
//  Created by Six on 16/1/13.
//  Copyright © 2016年 Six. All rights reserved.
//

#import "NSString+md5.h"
#import <CommonCrypto/CommonDigest.h>

//16位加密
#define BitNum 16

@implementation NSString (md5)

//md5 加密
- (NSString *)md5
{
    const char * cStr = [self UTF8String];
    unsigned char result[BitNum];
    CC_MD5(cStr, (CC_LONG)strlen(cStr), result);
    NSMutableString * mStr = [NSMutableString stringWithCapacity:BitNum];
    for (NSInteger i = 0; i < BitNum; i++)
    {
        [mStr appendFormat:@"%02X" , result[i]];
    }
    return mStr.lowercaseString;
}
//md5 大写
- (NSString *)uppercaseMD5
{
    const char * cStr = [self UTF8String];
    unsigned char result[BitNum];
    CC_MD5(cStr, (CC_LONG)strlen(cStr), result);
    NSMutableString * mStr = [NSMutableString stringWithCapacity:BitNum];
    for (NSInteger i = 0; i < BitNum; i++)
    {
        [mStr appendFormat:@"%02X" , result[i]];
    }
    return mStr.uppercaseString;
}

@end
