//
//  NSCalendar+ZIKTheDayBeforeYesterDay.m
//  Mobileyx
//
//  Created by ZIKong on 2017/5/22.
//  Copyright © 2017年 youhui. All rights reserved.

//  判断是否是前天

#import "NSCalendar+ZIKTheDayBeforeYesterDay.h"

@implementation NSCalendar (ZIKTheDayBeforeYesterDay)

- (BOOL)isDateInTheDayBeforeYesterDay:(NSDate *)date {
    //date 加上 60*60*24*2 (两天总共的秒数）就是今天
    NSDate *yesterDayPlusTwoDay = [NSDate dateWithTimeInterval:60*60*24*2 sinceDate:date];
    if ([self isDateInToday:yesterDayPlusTwoDay]) { //如果加上两天后的时间和今天相等，那么就是前天
        return YES;
    }
    return NO;
}

@end
