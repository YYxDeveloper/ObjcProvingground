//
//  NSString+SIMKit.h
//  SAMIM
//
//  Created by ZIKong on 2018/11/16.
//  Copyright © 2018  . All rights reserved.
//



NS_ASSUME_NONNULL_BEGIN

@interface NSString (SIMKit)
+ (NSString *)getVideoInfoWithSourcePath:(NSURL *)path;
+ (NSString *)timeFormatted:(NSString *)totalSeconds;
@end

NS_ASSUME_NONNULL_END
