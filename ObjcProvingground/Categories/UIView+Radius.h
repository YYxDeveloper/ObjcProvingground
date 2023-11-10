//
//  UIView+Radius.h
//  WenMingShuo
//
//  Created by Six on 15/12/30.
//  Copyright © 2015年 Six. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (Radius)

/**
 *  控件修圆
 *
 *  @param angle 修圆的弧度数
 */
- (void)radiusWithAngle:(CGFloat)angle;

- (void)cornerRadius:(CGFloat)cornerRadius
           lineColor:(UIColor *)lineColor;

- (void)cornerRadius:(CGFloat)cornerRadius
           lineColor:(UIColor *)lineColor
         borderWidth:(CGFloat)borderWidth;
@end
