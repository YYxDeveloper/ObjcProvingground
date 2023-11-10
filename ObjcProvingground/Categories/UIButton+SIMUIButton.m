//
//  UIButton+SIMUIButton.m
//  SAMIM
//
//  Created by 121 on 2018/9/29.
//  Copyright © 2018年  . All rights reserved.
//

#import "UIButton+SIMUIButton.h"

@implementation UIButton (SIMUIButton)

+(instancetype)buttonWithType:(UIButtonType)buttonType frame:(CGRect)frame
{
    UIButton * button = [UIButton buttonWithType:buttonType];
    button.frame = frame;
    return button;
}

#pragma mark -- 设置按钮标题信息
-(void)buttonSetTitle:(NSString *)title
{
    [self setTitle:title forState:UIControlStateNormal];
}

-(void)buttonSetTitleColor:(UIColor *)color
{
    [self setTitleColor:color forState:UIControlStateNormal];
}

- (void)buttonSetAttributedTitle:(NSAttributedString *)title
{
    [self setAttributedTitle:title forState:UIControlStateNormal];
}

#pragma mark -- 设置图片
-(void)buttonSetImage:(UIImage *)image
{
    [self setImage:image forState:UIControlStateNormal];
}

-(void)buttonSetBackgroundImage:(UIImage *)image
{
    [self setBackgroundImage:image forState:UIControlStateNormal];
}

#pragma mark -- 设置背景颜色
-(void)buttonAddTarget:(id)target action:(SEL)action
{
    [self addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
}

@end
