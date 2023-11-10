//
//  NSString+Extension.h
//  WenMingShuo
//
//  Created by Six on 16/3/8.
//  Copyright © 2016年 Six. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Extension)

/**
 *  判断字符串是否为空
 *
 *  @param str 字符串
 *
 *  @return bool值
 */
+ (BOOL)isBlankWithStr:(NSString *)str;
- (NSString *)trim;
+ (NSString *)checkString:(NSString *)str;

//汉字转拼音，区首字母
+ (NSString *)firstCharactor:(NSString *)aString;

//汉字转化为拼音
+(NSString *)PinYinToCharactor:(NSString *)astring;

/// 汉字转化为拼音
/// @param chinese 字符串
+ (NSString *)pinyinChina:(NSString *)chinese;

//生成UUID
+ (NSString *)createUUID;

//获取用户id
+ (NSString *)acquireUserId;

/// 当前账号的用户id
+ (NSString *)myUserId;

//根据 图片名  返回 想要的url
+ (NSURL *)returnImageUrlWithImageName:(NSString *)imageName;

+ (NSString *)returnImageStrWithImageName:(NSString *)imageName;
/// 获取当前版本号
+ (NSString *)acquireCurrentVersion;

//群号为200000xxxx截取前面部分 只保留后四位
+(NSString *)interceptGroupSessionId:(NSString *)session;
//判空字符串如果为空返回@""
+(NSString *)nullString:(NSString *)string;

+(BOOL)isHaveIllegalChar:(NSString *)string;

//验证手机
+ (BOOL)verificationIsValidWithPhoneNumberStr:(NSString *)phoneNumber_str;

//验证邮箱
+ (BOOL)verificationIsValidWithEmailStr:(NSString *)email_str;
+ (BOOL)checkPassword:(NSString *)passwrod;
//验证身份证
+ (BOOL)judgeIdentityStringValid:(NSString *)identityString;
/// 验证数字
+ (BOOL)verificationIsValidWithNumber:(NSString *)str;

- (CGSize)stringSizeWithFont:(UIFont *)font;

- (NSString *)MD5String;

- (NSUInteger)getBytesLength;

- (NSString *)stringByDeletingPictureResolution;

- (NSString *)tokenByPassword;

- (NSString *)iPhoneStandardFormat;

- (id)jsonObject;

- (CGSize)sizeWithFont:(UIFont *)font maxWidth:(CGFloat)width maxNumberLines:(int)num;
+ (NSString *)languageStr;

+ (BOOL)JudgeTheillegalCharacter:(NSString *)content;

+(BOOL)moneyTextField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;

+(BOOL)countTextField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;
/// 更换oss
- (NSString *)ossUrlStr;


+ (NSMutableArray *)calculateSubStringCount:(NSString *)content str:(NSString *)tab;

@end
