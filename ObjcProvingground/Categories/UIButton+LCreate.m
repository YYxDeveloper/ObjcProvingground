//
//  UIButton+LCreate.m
//  venusVip
//
//  Created by hfkj on 2019/4/22.
//  Copyright © 2019 com.jinXing. All rights reserved.
//

#import "UIButton+LCreate.h"

@implementation UIButton (LCreate)

/**
 创建一个通用的文字按钮
 */
+ (UIButton *)buttonWithTitle:(NSString *)title titleColor:(UIColor *)titleColor highlightedTitleColor:(UIColor * __nullable)highlightedTitleColor font:(UIFont *)font target:(id __nullable)target selector:(SEL __nullable)selector {
    UIButton *btn = [[self alloc] initWithFrame:CGRectZero];
    [btn setTitle:title forState:UIControlStateNormal];
    [btn setTitleColor:titleColor forState:UIControlStateNormal];
    if (highlightedTitleColor) {
        [btn setTitleColor:highlightedTitleColor forState:UIControlStateHighlighted];
    }
    btn.titleLabel.font = font;
    if(selector) {
        [btn addTarget:target action:selector forControlEvents:UIControlEventTouchUpInside];
    }
    return btn;
}


@end
