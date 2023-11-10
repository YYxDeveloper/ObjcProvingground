//
//  UIView+Border.h
//  WenMingShuo
//
//  Created by Six on 16/1/4.
//  Copyright © 2016年 Six. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (Border)

/**
 *  给视图四周加边框
 *
 *  @param width 边框粗细值
 *  @param color 颜色值
 */
- (void)setBorderWithWidth:(CGFloat)width color:(UIColor *)color;

@end
