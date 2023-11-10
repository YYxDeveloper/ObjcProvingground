//
//  UIView+Radius.m
//  WenMingShuo
//
//  Created by Six on 15/12/30.
//  Copyright © 2015年 Six. All rights reserved.
//

#import "UIView+Radius.h"

@implementation UIView (Radius)

/**
 *  控件修圆
 *
 *  @param angle 修圆的弧度数
 */
- (void)radiusWithAngle:(CGFloat)angle
{
    if (@available(iOS 11.0, *)) {
        self.layer.cornerRadius = angle;
        self.layer.maskedCorners = kCALayerMinXMinYCorner | kCALayerMaxXMinYCorner | kCALayerMinXMaxYCorner | kCALayerMaxXMaxYCorner ; // 左上圆角
        self.layer.masksToBounds = YES;
    }
    else {
        self.layer.cornerRadius = angle;
        self.layer.masksToBounds = YES;
//        UIRectCorner corner = UIRectCornerAllCorners; // 圆角位置，全部位置
//
//        UIBezierPath * path = [UIBezierPath bezierPathWithRoundedRect:self.bounds byRoundingCorners:corner cornerRadii:CGSizeMake(angle, angle)];
//        CAShapeLayer *maskLayer = [[CAShapeLayer alloc] init];
//        maskLayer.frame = self.bounds;
//        maskLayer.path = path.CGPath;
//        self.layer.mask = maskLayer;
    }
}

- (void)cornerRadius:(CGFloat)cornerRadius
           lineColor:(UIColor *)lineColor {
    self.layer.cornerRadius = cornerRadius;
    self.layer.masksToBounds = YES;
    self.layer.borderWidth = 0.5;
    self.layer.borderColor = [lineColor CGColor];
}

- (void)cornerRadius:(CGFloat)cornerRadius
           lineColor:(UIColor *)lineColor
         borderWidth:(CGFloat)borderWidth {
    
    self.layer.cornerRadius = cornerRadius;
    self.layer.masksToBounds = YES;
    self.layer.borderWidth = borderWidth;
    self.layer.borderColor = [lineColor CGColor];
}

@end
