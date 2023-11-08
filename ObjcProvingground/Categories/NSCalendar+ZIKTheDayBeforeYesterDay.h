//
//  NSCalendar+ZIKTheDayBeforeYesterDay.h
//  Mobileyx
//
//  Created by ZIKong on 2017/5/22.
//  Copyright © 2017年 youhui. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSCalendar (ZIKTheDayBeforeYesterDay)
/*
	This API reports if the date is within "the day before yesterday".
 */
- (BOOL)isDateInTheDayBeforeYesterDay:(NSDate *)date NS_AVAILABLE(10_9, 8_0);

@end
