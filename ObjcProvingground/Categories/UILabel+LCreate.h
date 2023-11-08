//
//  UILabel+LCreate.h
//  venusVip
//
//  Created by hfkj on 2019/4/22.
//  Copyright © 2019 com.jinXing. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UILabel (LCreate)

/**
 *  创建一个只有文本、颜色和字体的Label (适用于autolayout)
 *
 *  @param text      文本
 *  @param textColor 文本颜色
 *  @param font      字体
 *
 *  @return UILabel
 */
+ (UILabel *)labelWithText:(NSString *)text textColor:(UIColor *) textColor font:(UIFont *)font;

/**
 修改label内容距 `top` `left` `bottom` `right` 边距
 */
@property (nonatomic, assign) UIEdgeInsets yf_contentInsets;

@end

NS_ASSUME_NONNULL_END
