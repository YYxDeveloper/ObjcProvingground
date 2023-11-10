//
//  UIImage+Color.h
//  WenMingShuo
//
//  Created by Six on 16/1/4.
//  Copyright © 2016年 Six. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Color)

/**
 *  根据一个颜色值返回一张图片
 *
 *  @param color 颜色值
 *
 *  @return 一张图片
 */
+ (UIImage *)returnImageWithColor:(UIColor *)color;

@end
