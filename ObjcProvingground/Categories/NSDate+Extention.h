//
//  NSDate+Extention.h
//  LLLM
//
//  Created by sam on 16/8/4.
//  Copyright © 2016年 clove. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    CountDownTimeTypeEmail,//绑定邮箱
    CountDownTimeTypeRegist,//注册
    CountDownTimeTypeRealName,//实名认证
    CountDownTimeTypeFindLostPwdByPhoneNumber,//通过手机号找回密码
    CountDownTimeTypeFindLostPwdByEmail,//通过邮箱找回密码
    CountDownTimeTypeSetPayPwd,//设置支付密码
    CountDownTimeTypeResetLoginPwdByPhoneNumber,//通过手机号修改密码
    CountDownTimeTypeResetLoginPwdByEmail,//通过邮箱修改密码
    CountDownTimeTypeRelieveEmail,//解绑邮箱
    CountDownTimeTypeChangePhone,//更换手机号

} CountDownTimeType;

@interface NSDate (Extention)

+ (NSString *)nowFromDateExchange:(NSString *)oldTime;
+ (NSString *)dateExchange:(NSInteger)time;

//返回绑定邮箱获取验证码剩余倒计时 如果有倒计时返回倒计时 如果没有 返回0 tag为1时存储当前时间戳
+ (NSInteger)returnEmailBindTime:(NSInteger)tag type:(CountDownTimeType)type;
+(int)compareDate:(NSString*)startTime withDate:(NSString*)endTime;

//时间---->时间戳
+(NSString *)transTotimeSp:(NSString *)time;
+(NSString *)transToDate:(NSString *)timsp;

+ (NSString *)dateChangeWihtStr:(NSString *)str;
@end
