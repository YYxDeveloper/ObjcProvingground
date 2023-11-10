//
//  UIImage+Color.m
//  WenMingShuo
//
//  Created by Six on 16/1/4.
//  Copyright © 2016年 Six. All rights reserved.
//

#import "UIImage+Color.h"

@implementation UIImage (Color)

/**
 *  根据一个颜色值返回一张图片
 *
 *  @param color 颜色值
 *
 *  @return 一张图片
 */
+ (UIImage *)returnImageWithColor:(UIColor *)color
{
    CGRect rect = CGRectMake(0, 0, 1, 1);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef contextRef = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(contextRef, color.CGColor);
    CGContextFillRect(contextRef, rect);
    UIImage * image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return image;
}

@end
