//
//  NSString+Date.m
//  WenMingShuo
//
//  Created by Six on 16/4/11.
//  Copyright © 2016年 Six. All rights reserved.
//

#import "NSString+Date.h"
//#import "SIMGroupModel.h"
@implementation NSString (Date)

/**
 *  根据 毫秒数 返回 时间字符串
 *
 *  @param time 时间（毫秒数）
 *
 *  @return 时间字符串
 */
+ (NSString *)returnDateStrWithTime:(NSTimeInterval)time
{
    NSDate * date = [NSDate dateWithTimeIntervalSince1970:time / 1000];
    NSCalendarUnit unitFlags = NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitWeekOfYear | NSCalendarUnitWeekdayOrdinal | NSCalendarUnitWeekday | NSCalendarUnitDay | NSCalendarUnitHour | NSCalendarUnitMinute;
    NSCalendar * calendar = [NSCalendar currentCalendar];
    NSDateComponents * messageDateComponents = [calendar components:unitFlags fromDate:date];
    NSDateComponents * todayDateComponents = [calendar components:unitFlags fromDate:[NSDate date]];
    
    NSUInteger dayOfYearForMessage = [calendar ordinalityOfUnit:NSCalendarUnitDay inUnit:NSCalendarUnitYear forDate:date];
    NSUInteger dayOfYearForToday = [calendar ordinalityOfUnit:NSCalendarUnitDay inUnit:NSCalendarUnitYear forDate:[NSDate date]];

    NSString * dateStr = @"";
    if (messageDateComponents.year == todayDateComponents.year && messageDateComponents.month == todayDateComponents.month && messageDateComponents.day == todayDateComponents.day)
    {
        dateStr = [NSString stringWithFormat:@"%02zi:%02zi" , messageDateComponents.hour , messageDateComponents.minute];
    }
    else if (messageDateComponents.year == todayDateComponents.year && dayOfYearForMessage == (dayOfYearForToday - 1))
    {
        dateStr = [NSString stringWithFormat:@"%@ %02zi:%02zi" ,SIMLocalized(@"昨天"), messageDateComponents.hour , messageDateComponents.minute];
    }
    else
    {
        NSDateFormatter * dateFormatter = [[NSDateFormatter alloc] init];
        dateFormatter.timeZone = [NSTimeZone localTimeZone];
        dateFormatter.dateFormat = @"YYYY-MM-dd";
        dateStr = [dateFormatter stringFromDate:date];
    }
    return dateStr;
}
/**
 *  根据 毫秒数 返回 时间字符串
 *
 *  @param time 时间（毫秒数）
 *
 *  @param dateFormatStr 时间格式
 *
 *  @return 时间字符串
 */
+ (NSString *)returnDateStrWithTime:(NSTimeInterval)time dateFormatStr:(NSString *)dateFormatStr
{
    NSDate * date = [NSDate dateWithTimeIntervalSince1970:time / 1000];

    
    NSString * dateStr = @"";
    NSDateFormatter * dateFormatter = [[NSDateFormatter alloc] init];
    dateFormatter.timeZone = [NSTimeZone localTimeZone];
    dateFormatter.dateFormat = dateFormatStr;
    dateStr = [dateFormatter stringFromDate:date];
    
    return dateStr;
}

+ (NSString *)returnDateTimeWithTime:(NSTimeInterval)time
{
    if (time > 0) {
        return  [NSString stringWithFormat:@"%.0f",time/24.0/60.0/60.0];
    }
    return @"0";
}


+ (NSString *)XZGetTimeStringWithDate:(NSDate *)date dateFormatStr:(NSString *)dateFormatStr {
    NSDateFormatter *format = [[NSDateFormatter alloc] init];
    format.dateFormat = dateFormatStr;
    return [format stringFromDate:date];
}

+ (NSDictionary *)LHGetStartTime {
    // 获取当前date
    NSDate *date = [NSDate date];
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDictionary *weekDict = @{@"2" : SIMLocalized(@"週一"), @"3" : SIMLocalized(@"週二"), @"4" : SIMLocalized(@"週三"), @"5" : SIMLocalized(@"週四"), @"6" : SIMLocalized(@"週五"), @"7" : SIMLocalized(@"週六"), @"1" : SIMLocalized(@"週日")};
    // 日期格式
    NSDateFormatter *fullFormatter = [[NSDateFormatter alloc] init];
    NSDateFormatter *fullFormatter1 = [[NSDateFormatter alloc] init];
    NSDateFormatter *fullFormatter2 = [[NSDateFormatter alloc] init];
    fullFormatter.dateFormat = @"yyyy-MM-dd HH:mm";
    fullFormatter1.dateFormat = @"dd";
    fullFormatter2.dateFormat = @"MM";
    
    //1.获取当月的总天数
    NSRange range = [calendar rangeOfUnit:NSDayCalendarUnit inUnit:NSMonthCalendarUnit forDate:[NSDate date]];
    
    NSUInteger numberOfDaysInMonth = range.length;
    //今天是几号
    NSString * dateStr=[fullFormatter1 stringFromDate:date];
    //这个月的天数
    int allMonthDay = (int)numberOfDaysInMonth-(int)dateStr.integerValue;
    
    //今年的月数
    int allMonth = 12 - (int)[fullFormatter2 stringFromDate:date].integerValue;
    NSLog(@"剩余多少%d天  剩余多少%d月", allMonthDay,allMonth);
    
    
    
    // 获取当前几时(晚上23点要把今天的时间做处理)
    NSInteger currentHour = [calendar component:NSCalendarUnitHour fromDate:date];
    // 存放周几和时间的
    NSMutableArray *weekStrArr = [NSMutableArray array];
    NSMutableArray *detailTimeArr = [NSMutableArray array];
    // 设置合适的时间
    for (int i = 0; i < allMonthDay + 1; i++) {
        NSDate *new = [calendar dateByAddingUnit:NSCalendarUnitDay value:i toDate:date options:NSCalendarMatchStrictly];
        NSInteger week = [calendar component:NSCalendarUnitWeekday fromDate:new];
        
        NSInteger year = [calendar component:NSCalendarUnitYear fromDate:new];
        NSInteger month = [calendar component:NSCalendarUnitMonth fromDate:new];
        NSInteger day = [calendar component:NSCalendarUnitDay fromDate:new];
        
        // 周几
        NSString *weekStr = weekDict[[NSString stringWithFormat:@"%ld",week]];
        NSString *todayOrOther = @"";
        NSString *resultWeekStr = @"";
        if (i == 0) {
            todayOrOther = SIMLocalized(@"今天");
            resultWeekStr = [NSString stringWithFormat:@"%@ %@",todayOrOther,weekStr];
        }else if (i == 1) {
            todayOrOther = SIMLocalized(@"明天");
            resultWeekStr = [NSString stringWithFormat:@"%@ %@",todayOrOther,weekStr];
        }else if (i == 2){
            todayOrOther = SIMLocalized(@"後天");
            resultWeekStr = [NSString stringWithFormat:@"%@ %@",todayOrOther,weekStr];
        }else{
            resultWeekStr = [NSString stringWithFormat:@"%ld%@%ld%@",month,SIMLocalized(@"月"),day,SIMLocalized(@"日")];
        }
        //        else{
        //            resultWeekStr = [NSString stringWithFormat:@"%ld月%ld月1日",year,month];
        //        }
        // 今天周几 明天周几 后天周几
        
        [weekStrArr addObject:resultWeekStr];
        // 把符合条件的时间筛选出来
        NSMutableArray *smallArr = [NSMutableArray array];
        for (int hour = 0; hour < 24; hour++) {
            for (int min = 0; min < 60; min ++) {
                if (min % 15 == 0) {
                    NSString *tempDateStr = [NSString stringWithFormat:@"%ld-%ld-%ld %d:%d",year,month,day,hour,min];
                    
                    NSDate *tempDate = [fullFormatter dateFromString:tempDateStr];
                    // 今天 之后的时间段
                    if (i == 0) {
                        if ([calendar compareDate:tempDate toDate:date toUnitGranularity:NSCalendarUnitHour] == 1) {
                            [smallArr addObject:tempDate];
                        }
                    }else{
                        [smallArr addObject:tempDate];
                    }
                }
            }
        }
        [detailTimeArr addObject:smallArr];
    }
    
    // 设置每个月的1号
    for (int i = 0; i < 11; i++) {
        NSCalendar* cal=[NSCalendar currentCalendar];
        NSDateComponents *dateComponents = [cal components:NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit fromDate:[NSDate date]];
        //设置日为1号
        dateComponents.day =1;
        //设置月份为后延1个月
        dateComponents.month +=i+1;
        NSDate * endDayOfNextMonth = [cal dateFromComponents:dateComponents];
        
        
        NSInteger year = [calendar component:NSCalendarUnitYear fromDate:endDayOfNextMonth];
        NSInteger month = [calendar component:NSCalendarUnitMonth fromDate:endDayOfNextMonth];
        NSInteger day = [calendar component:NSCalendarUnitDay fromDate:endDayOfNextMonth];
        
        // 周几
        NSString *resultWeekStr = @"";
        
        resultWeekStr = [NSString stringWithFormat:@"%ld年%ld月%ld日",year,month,day];
        
        [weekStrArr addObject:resultWeekStr];
        // 把符合条件的时间筛选出来
        NSMutableArray *smallArr = [NSMutableArray array];
        for (int hour = 0; hour < 24; hour++) {
            for (int min = 0; min < 60; min ++) {
                if (min % 15 == 0) {
                    NSString *tempDateStr = [NSString stringWithFormat:@"%ld-%ld-%ld %d:%d",year,month,day,hour,min];
                    
                    NSDate *tempDate = [fullFormatter dateFromString:tempDateStr];
                    // 今天 之后的时间段
                    if (i == 0) {
                        if ([calendar compareDate:tempDate toDate:date toUnitGranularity:NSCalendarUnitHour] == 1) {
                            [smallArr addObject:tempDate];
                        }
                    }else{
                        [smallArr addObject:tempDate];
                    }
                }
            }
        }
        [detailTimeArr addObject:smallArr];
        
        
    }
    
    
    
    // 晚上23点把今天对应的周几和今天的时间空数组去掉
    if (currentHour == 23) {
        [weekStrArr removeObjectAtIndex:0];
        [detailTimeArr removeObjectAtIndex:0];
    }
    NSDictionary *resultDic = @{@"week" : weekStrArr , @"time" : detailTimeArr};
    return resultDic;
}


+(BOOL)compareTimeWithStartTime:(NSString *)startTime intValue:(int)timeValue
{
    NSTimeInterval startInterval = [startTime longLongValue]/1000;
    
    NSDate* dat = [NSDate dateWithTimeIntervalSinceNow:0];
    NSTimeInterval now = [dat timeIntervalSince1970]*1;
    
    NSTimeInterval cha = now - startInterval;
    
    if (cha > timeValue) {
        return NO;
    }else{
        return YES;
    }
}

+ (BOOL)getCurrentTimestamp:(SIMGroupModel *)groupModel{
//    NSDate* dat = [NSDate dateWithTimeIntervalSinceNow:0];
//    NSTimeInterval a=[dat timeIntervalSince1970];
//    NSTimeInterval expire = groupModel.expire.longLongValue;
//    if (expire < a*1000 && expire > 0) {
//        return YES;
//    }
    return NO;
}

+ (NSString *)stringWithTimeStamp:(NSNumber *)timeStamp {
    //获取当前时间
    NSDate *currentDate = [NSDate date];
    //将当前时间转化为时间戳
    NSTimeInterval currentDateStamp = [currentDate timeIntervalSince1970] + 8 * 3600;
    //将传入的参数转化为时间戳
    double dateStamp = [timeStamp doubleValue]/1000 + 8 * 3600;
    //计算时间间隔，即当前时间减去传入的时间
    double interval = currentDateStamp - dateStamp;
    //获取当前时间的小时单位（24小时制）
    NSDateFormatter *formatter = [NSDateFormatter new];
    [formatter setDateFormat:@"H"];
    int nowHour = [[formatter stringFromDate:currentDate] intValue];
    //获取当前时间的分钟单位
    NSDateFormatter *minFormatter = [NSDateFormatter new];
    [minFormatter setDateFormat:@"m"];
    int nowMinute = [[minFormatter stringFromDate:currentDate] intValue];
    //今天0点的时间戳
    double todayZeroClock = currentDateStamp - 3600 * nowHour - 60 * nowMinute;
    //时间格式化，为输出做准备
    NSDateFormatter *outputFormat = [NSDateFormatter new];
    [outputFormat setDateFormat:@"M月d日"];
    //进行条件判断，满足不同的条件返回不同的结果
    if (interval < 1 * 60) {
        //在1分钟之内
        return SIMLocalized(@"刚刚");
    }
    else if (todayZeroClock - dateStamp > 24 * 3600) {
        //已经超过两天以上
        return [outputFormat stringFromDate:[NSDate dateWithTimeIntervalSince1970:dateStamp - 8*3600]];
    } else if (todayZeroClock - dateStamp > 0) {
        //已经超过一天（昨天）
        return SIMLocalized(@"昨天");
    } else if (interval < 3600) {
        //一个小时之内
        return [NSString stringWithFormat:@"%.0f %@", (currentDateStamp - dateStamp) / 60,SIMLocalized(@"分钟前")];
    } else {
        //今天之内
        return [NSString stringWithFormat:@"%.0f %@", (currentDateStamp - dateStamp) / 3600,SIMLocalized(@"小时前")];
    }
}
// 訊息顯示時間
+ (NSString *)sessionStringWithTimeStamp:(NSNumber *)timeStamp
{
    //获取当前时间
//    NSDate *currentDate = [NSDate date];
//    // 需要比较的时间
//    NSDate *newDate = [NSDate dateWithTimeIntervalSince1970:[timeStamp doubleValue] / 1000];
//
//    if ([newDate year] < [currentDate year]) {
//        // 不是本年度
//        NSDateFormatter *outputFormat = [NSDateFormatter new];
//        [outputFormat setDateFormat:@"yyyy/M/d"];
//        return [outputFormat stringFromDate:newDate];
//    }
//
//    //轉換成年月日進行比較  這樣比較精準
//    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
//    [dateFormatter setDateFormat:@"yyyy-MM-dd"];
//    NSDate *startDate = [dateFormatter dateFromString:[dateFormatter stringFromDate:newDate]];
//    NSDate *endDate = [dateFormatter dateFromString:[dateFormatter stringFromDate:currentDate]];
//    //利用NSCalendar比较日期的差异
//    NSCalendarUnit unit = NSCalendarUnitDay;
//    NSCalendar *calendar = [NSCalendar currentCalendar];
//    NSDateComponents *components = [calendar components:unit fromDate:startDate toDate:endDate options:0];
//    NSInteger days = components.day;
//
//    if (days < 0) {
//        // 未来
//        NSDateFormatter *outputFormat = [NSDateFormatter new];
//        [outputFormat setDateFormat:@"HH:mm"];
//        return [outputFormat stringFromDate:newDate];
//    }
//
//    if (days == 0) {
//        // 今天的
//        NSDateFormatter *outputFormat = [NSDateFormatter new];
//        [outputFormat setDateFormat:@"HH:mm"];
//        return [outputFormat stringFromDate:newDate];
//    }
//
//    if (days == 1) {
//        // 昨天的
//        return SIMLocalized(@"昨天");
//    }
//
//    if (days > 6) {
//        // 大於七天
//        NSDateFormatter *outputFormat = [NSDateFormatter new];
//        [outputFormat setDateFormat:@"M/d"];
//        return [outputFormat stringFromDate:newDate];
//    }
//
//    //七天内，排除今天與昨天的訊息（共5天）：
//    NSDictionary *weekDict = @{@"2" : SIMLocalized(@"星期一"), @"3" : SIMLocalized(@"星期二"), @"4" : SIMLocalized(@"星期三"), @"5" : SIMLocalized(@"星期四"), @"6" : SIMLocalized(@"星期五"), @"7" : SIMLocalized(@"星期六"), @"1" : SIMLocalized(@"星期日")};
//    NSInteger week = [[NSCalendar currentCalendar] component:NSCalendarUnitWeekday fromDate:newDate];
    return @"";
}

+(NSString *)returnDateWithTimeIntervalSinceNow
{
    //当前时间戳
    NSDate* date = [NSDate dateWithTimeIntervalSinceNow:0];
    NSTimeInterval time=[date timeIntervalSince1970];
    NSString *timeString = [NSString stringWithFormat:@"%.0f", time];
    return timeString;
}
// life顯示時間
+ (NSString *)lifeStringWithTimeStamp:(NSNumber *)timeStamp
{
    //获取当前时间
    NSDate *currentDate = [NSDate date];
    //将当前时间转化为时间戳
    NSTimeInterval currentDateStamp = [currentDate timeIntervalSince1970] + 8 * 3600;
    //将传入的参数转化为时间戳
    double dateStamp = [timeStamp doubleValue] / 1000 + 8 * 3600;
    //计算时间间隔，即当前时间减去传入的时间
    double interval = currentDateStamp - dateStamp;
    if (interval < 60) {
        // 一分鐘內
        return SIMLocalized(@"刚刚");
    } else if (interval < 3600) {
        //一个小时之内
        return [NSString stringWithFormat:@"%.0f %@", interval / 60,SIMLocalized(@"分钟前")];
    } else if (interval < 24 * 3600) {
        //24小時內
        return [NSString stringWithFormat:@"%.0f %@", interval / 3600,SIMLocalized(@"小时前")];
    } else if (interval < 365 * 24 * 3600) {
        // 一年以內 日期+時分
        return [self returnDateStrWithTime:timeStamp.integerValue dateFormatStr:@"MM-dd HH:mm"];
    } else {
        // 滿365天 年份+日期+時分
        return [self returnDateStrWithTime:timeStamp.integerValue dateFormatStr:@"yyyy-MM-dd HH:mm"];
    }
}

// life詳情顯示時間
+ (NSString *)lifeDetailsStringWithTimeStamp:(NSNumber *)timeStamp
{
    //获取当前时间
    NSDate *currentDate = [NSDate date];
    //将当前时间转化为时间戳
    NSTimeInterval currentDateStamp = [currentDate timeIntervalSince1970] + 8 * 3600;
    //将传入的参数转化为时间戳
    double dateStamp = [timeStamp doubleValue] / 1000 + 8 * 3600;
    //计算时间间隔，即当前时间减去传入的时间
    double interval = currentDateStamp - dateStamp;
    if (interval < 60) {
        // 一分鐘內
        return SIMLocalized(@"刚刚");
    } else if (interval < 3600) {
        //一个小时之内
        return [NSString stringWithFormat:@"%.0f %@", interval / 60,SIMLocalized(@"分钟前")];
    } else if (interval < 24 * 3600) {
        //24小時內
        return [NSString stringWithFormat:@"%.0f %@", interval / 3600,SIMLocalized(@"小时前")];
    } else if (interval < 365 * 24 * 3600) {
        // 一年以內 日期+時分秒
        return [self returnDateStrWithTime:timeStamp.integerValue dateFormatStr:@"MM-dd HH:mm:ss"];
    } else {
        // 滿365天 年份+日期+時分秒
        return [self returnDateStrWithTime:timeStamp.integerValue dateFormatStr:@"yyyy-MM-dd HH:mm:ss"];
    }
}

@end
