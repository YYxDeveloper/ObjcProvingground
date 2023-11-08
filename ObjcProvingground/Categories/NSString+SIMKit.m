//
//  NSString+SIMKit.m
//  SAMIM
//
//  Created by ZIKong on 2018/11/16.
//  Copyright © 2018  . All rights reserved.
//

#import "NSString+SIMKit.h"
#import <Photos/Photos.h>

@implementation NSString (SIMKit)
+ (NSString *)getVideoInfoWithSourcePath:(NSURL *)path{
    
    NSDictionary *opts = [NSDictionary dictionaryWithObject:@(NO) forKey:AVURLAssetPreferPreciseDurationAndTimingKey];
    AVURLAsset *urlAsset = [AVURLAsset URLAssetWithURL:path options:opts]; // 初始化视频媒体文件
    double second = urlAsset.duration.value / urlAsset.duration.timescale; // 获取视频总时长,单位秒
    int secondM = second * 1000;
    
    return [NSString stringWithFormat:@"%d",secondM];
}


+ (NSString *)timeFormatted:(NSString *)totalSeconds
{
    int total = [totalSeconds intValue] /1000;
    
    int seconds = total % 60;
    int minutes = (total / 60) % 60;
    
    return [NSString stringWithFormat:@"%02d:%02d",minutes, seconds];
}
@end
