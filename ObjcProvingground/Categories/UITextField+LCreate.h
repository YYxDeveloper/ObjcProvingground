//
//  UITextField+LCreate.h
//  venusVip
//
//  Created by hfkj on 2019/4/24.
//  Copyright © 2019 com.jinXing. All rights reserved.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface UITextField (LCreate) <UITextFieldDelegate>

/**
 快速创建textField

 @param placeholder 占位文本
 @param placeholderFont 占位文本大小
 @param placeholderColor 占位文本颜色
 @param borderStyle textField的样式
 @param textFont 字体大小
 @param textAlignment 字体对齐方式
 @return tf
 */
+ (UITextField *) textFieldPlaceholder:(NSString *) placeholder placeholderFont:(UIFont *) placeholderFont placeholderColor:(UIColor *) placeholderColor borderStyle:(UITextBorderStyle)borderStyle textFont:(UIFont *)textFont textAlignment:(NSTextAlignment) textAlignment maxTextLength:(NSString * __nullable)maxTextLength textColor:(UIColor *)textColor;

- (void) observeKeyBoard;

/**最多输入长度*/
@property(nonatomic,copy)NSString *maxTextLength;

/// 限制小数点个数
@property(nonatomic,copy) NSString *limitPointCountTF;

/// 限制只能输入数字
@property(nonatomic,copy) NSString *limitNumTF;

@property (nonatomic, copy) void(^clickChangeAction)(NSString *text);

@end

NS_ASSUME_NONNULL_END
