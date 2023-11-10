//
//  UIButton+SIMUIButton.h
//  SAMIM
//
//  Created by 121 on 2018/9/29.
//  Copyright © 2018年  . All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIButton (SIMUIButton)

+(instancetype)buttonWithType:(UIButtonType)buttonType frame:(CGRect)frame;

#pragma mark -- 设置按钮标题信息
-(void)buttonSetTitle:(NSString *)title;
-(void)buttonSetTitleColor:(UIColor *)color;
-(void)buttonSetAttributedTitle:(NSAttributedString *)title;

#pragma mark -- 设置图片
-(void)buttonSetImage:(UIImage *)image;
-(void)buttonSetBackgroundImage:(UIImage *)image;

#pragma mark -- 设置背景颜色
-(void)buttonAddTarget:(id)target action:(SEL)action;



@end
