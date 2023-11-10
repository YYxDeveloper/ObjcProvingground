//
//  NSString+Date.h
//  WenMingShuo
//
//  Created by Six on 16/4/11.
//  Copyright © 2016年 Six. All rights reserved.
//

#import <Foundation/Foundation.h>
@class SIMGroupModel;
@interface NSString (Date)

/**
 *  根据 毫秒数 返回 时间字符串
 *
 *  @param time 时间（毫秒数）
 *
 *  @return 时间字符串
 */
+ (NSString *)returnDateStrWithTime:(NSTimeInterval)time;
/**
 *  根据 毫秒数 返回 时间字符串
 *
 *  @param time 时间（毫秒数）
 *
 *  @param dateFormatStr 时间格式
 *
 *  @return 时间字符串
 */
+ (NSString *)returnDateStrWithTime:(NSTimeInterval)time dateFormatStr:(NSString *)dateFormatStr;

/**
 *  根据 毫秒数 返回 时间天
 *
 *  @param time 时间（毫秒数）
 *
 *  @return 时间字符串
 */
+ (NSString *)returnDateTimeWithTime:(NSTimeInterval)time;

+ (NSString *)XZGetTimeStringWithDate:(NSDate *)date dateFormatStr:(NSString *)dateFormatStr;

+ (NSDictionary *)LHGetStartTime;

/**
 *返回撤销消息是否可以撤回
 */
+(BOOL)compareTimeWithStartTime:(NSString *)startTime intValue:(int)timeValue;

//根据群聊过期时间获取当前时间戳
+ (BOOL)getCurrentTimestamp:(SIMGroupModel *)groupModel;
//根据时间戳显示刚刚 一小时前  一天前
+ (NSString *)stringWithTimeStamp:(NSNumber *)timeStamp;
//获取当前时间戳
+(NSString *)returnDateWithTimeIntervalSinceNow;
// life顯示時間
+ (NSString *)lifeStringWithTimeStamp:(NSNumber *)timeStamp;
// life詳情顯示時間
+ (NSString *)lifeDetailsStringWithTimeStamp:(NSNumber *)timeStamp;
// 訊息顯示時間
+ (NSString *)sessionStringWithTimeStamp:(NSNumber *)timeStamp;

@end
