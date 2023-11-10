//
//  UIButton+LCreate.h
//  venusVip
//
//  Created by hfkj on 2019/4/22.
//  Copyright © 2019 com.jinXing. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIButton (LCreate)


/**
 创建一个通用的文字按钮
 */
+ (UIButton *)buttonWithTitle:(NSString *)title titleColor:(UIColor *)titleColor highlightedTitleColor:(UIColor * __nullable)highlightedTitleColor font:(UIFont *)font target:(id __nullable)target selector:(SEL __nullable)selector;


@end

NS_ASSUME_NONNULL_END
