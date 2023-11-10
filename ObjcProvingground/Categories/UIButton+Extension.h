//
//  UIButton+Extension.h
//  WenMingShuo
//
//  Created by Six on 16/1/7.
//  Copyright © 2016年 Six. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIButton (Extension)

/**
 *  设置按钮
 *
 *  @param normalImageNameStr 正常状态下按钮图片名
 *  @param selectImageNameStr 选中状态下按钮图片名
 *  @param normalTitleColor   正常状态下按钮文字颜色
 *  @param selectTitleColor   选中状态下按钮文字颜色
 *  @param selected           按钮是否处于选中状态
 */
- (void)setButtonWithNormalImageNameStr:(NSString *)normalImageNameStr
                     selectImageNameStr:(NSString *)selectImageNameStr
                       normalTitleColor:(UIColor *)normalTitleColor
                       selectTitleColor:(UIColor *)selectTitleColor
                               selected:(BOOL)selected;
/**
 *  创建按钮 作为 textField 的 rightView
 *
 *  @param height             按钮的高度
 *  @param normalImageNameStr 正常状态下按钮图片名
 *
 *  @return UIButton
 */
+ (UIButton *)createTextFieldRightViewWithHeight:(CGFloat)height
                              normalImageNameStr:(NSString *)normalImageNameStr;
/**
 *  创建一个按钮
 *
 *  @param normalImageName      默认图片名
 *  @param highlightedImageName 高亮时 图片名
 *  @param selectedImageName    选中图片名
 *
 *  @return UIButton
 */
+ (UIButton *)createButtonWithNormalImageName:(NSString *)normalImageName
                         highlightedImageName:(NSString *)highlightedImageName
                            selectedImageName:(NSString *)selectedImageName;

@end
