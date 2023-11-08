//
//  UITextField+LCreate.m
//  venusVip
//
//  Created by hfkj on 2019/4/24.
//  Copyright © 2019 com.jinXing. All rights reserved.
//

#import "UITextField+LCreate.h"

#import <objc/runtime.h>

static char *const kAction = "kAction";

static NSString *maxTextLengthKey = @"maxTextLengthKey"; //那么的key

static NSString *limitPointCountTFKey = @"limitPointCountTFKey";

static NSString *limitNumTFKey = @"limitNumTFKey";

@interface UITextField ()  

@end

@implementation UITextField (LCreate)

+ (UITextField *) textFieldPlaceholder:(NSString *) placeholder placeholderFont:(UIFont *) placeholderFont placeholderColor:(UIColor *) placeholderColor borderStyle:(UITextBorderStyle)borderStyle textFont:(UIFont *)textFont textAlignment:(NSTextAlignment) textAlignment maxTextLength:(NSString * __nullable)maxTextLength textColor:(UIColor *)textColor{
    
    UITextField *tf = [[UITextField alloc] init];
    tf.delegate = tf;
    tf.placeholder = placeholder;
    tf.borderStyle = borderStyle;
    tf.font = textFont;
    tf.textAlignment = textAlignment;
//    tf.attributedPlaceholder = [[NSAttributedString alloc] initWithString:CheckNilFromObj(placeholder) attributes:@{NSForegroundColorAttributeName: placeholderColor,NSFontAttributeName : placeholderFont}];
    
    if (maxTextLength && [maxTextLength intValue] == 0) {
        maxTextLength = @"10000000000";
    }
   
    tf.maxTextLength = maxTextLength;
    tf.textColor = textColor;
    [tf observeKeyBoard];
    
    return tf;
}


- (void) observeKeyBoard {
    //添加通知监听文本状态
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textBeginEditing:) name:UITextFieldTextDidBeginEditingNotification object:self];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textDidEndEditing:) name:UITextFieldTextDidEndEditingNotification object:self];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textDidChange:) name:UITextFieldTextDidChangeNotification object:self];
}


- (void)textBeginEditing:(NSNotification*)note {
    [self changBorderwithNote:note];
    
}

- (void)textDidEndEditing:(NSNotification*)note {
    [self changBorderwithNote:note];
    
    
}

-(void)textDidChange:(NSNotification*)note {
    [self changBorderwithNote:note];

}

-(void)changBorderwithNote:(NSNotification*)editing {
    if (![editing.object isEqual:self])return;
    if ([editing.name isEqualToString:UITextFieldTextDidChangeNotification]){
        if (self.maxTextLength!=0)
        {
            if (self.text.length > [self.maxTextLength intValue]) {
                [self judemaxText];
            }
            
            if (self.clickChangeAction) {
                self.clickChangeAction(self.text);
            }
        }
    }
    
}

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string {
    if ([self.limitPointCountTF integerValue] > 0) {
        NSMutableString *futureString = [NSMutableString stringWithString:textField.text];
        [futureString insertString:string atIndex:range.location];
        
        NSInteger flag = 0;
        const NSInteger limited = [self.limitPointCountTF integerValue];
        
        for (int i = futureString.length - 1; i >= 0; i--) {
            
            if ([futureString characterAtIndex:i] == '.') {
                // 如果大于了限制的就提示
                if (flag > limited) {
                    //                [MBProgressHUD showInfoWithText:@"只可以填写到小数点后两位"];
                    return NO;
                }
                break;
            }
            flag++;
        }
        return YES;
    } else if ([self.limitNumTF boolValue] == YES) {
        return [self validateNumber:string];
    }
    return YES;
}

//限制最大输入字数
-(void)judemaxText
{
    if ([self.maxTextLength intValue] > 0)
    {
        // 键盘输入模式
        NSString *lang=[[UIApplication sharedApplication]textInputMode].primaryLanguage;
        if ([lang isEqualToString:@"zh-Hans"] || [lang isEqualToString:@"zh-Hant"]) { // 简体中文输入，包括简体拼音，健体五笔，简体手写
            UITextRange *selectedRange = [self markedTextRange];
            //获取高亮部分
            UITextPosition *position = [self positionFromPosition:selectedRange.start offset:0];
            // 没有高亮选择的字，则对已输入的文字进行字数统计和限制
            if (!position) {
                if (self.text.length >= [self.maxTextLength intValue]) {
                    if (self.text.length > [self.maxTextLength intValue]) {
                        [self addShakeAnimation];
                    }
                    NSString *newText = [self.text substringToIndex:[self.maxTextLength intValue]];
                    if (![self.text isEqualToString:newText])
                    {
                        self.text = newText;
                    }
                    NSLog(@"还在走呢 : %@",newText);
                }
            }
            // 有高亮选择的字符串，则暂不对文字进行统计和限制
            else{
                
            }
        }
        // 中文输入法以外的直接对其统计限制即可，不考虑其他语种情况
        else{
            if (self.text.length >= [self.maxTextLength intValue]) {
                if (self.text.length>[self.maxTextLength intValue])
                {
                    [self addShakeAnimation];
                }
                NSString *newText=[self.text substringToIndex:[self.maxTextLength intValue]];
                if (![self.text isEqualToString:newText])
                {
                    self.text = newText;
                }
                return;
            }
        }
        
    }
    
}

//限制只输入数字
- (BOOL)validateNumber:(NSString*)number {
    BOOL res = YES;
    NSCharacterSet* tmpSet = [NSCharacterSet characterSetWithCharactersInString:@"0123456789"];
    int i = 0;
    while (i < number.length) {
        NSString * string = [number substringWithRange:NSMakeRange(i, 1)];
        NSRange range = [string rangeOfCharacterFromSet:tmpSet];
        if (range.length == 0) {
            res = NO;
            break;
        }
        i++;
    }
    return res;
}

//添加抖动动画
-(void)addShakeAnimation
{
    CAKeyframeAnimation * animation = [CAKeyframeAnimation animationWithKeyPath:@"transform.translation.x"];
    CGFloat currentTx = self.transform.tx;
    
    //    animation.delegate = self;
    animation.duration = 0.5;
    animation.values = @[ @(currentTx), @(currentTx + 10), @(currentTx-8), @(currentTx + 8), @(currentTx -5), @(currentTx + 5), @(currentTx) ];
    animation.keyTimes = @[ @(0), @(0.225), @(0.425), @(0.6), @(0.75), @(0.875), @(1) ];
    animation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
    [self.layer addAnimation:animation forKey:@"kAFViewShakerAnimationKey"];
}

- (void)setMaxTextLength:(NSString *)maxTextLength {
    objc_setAssociatedObject(self, &maxTextLengthKey, maxTextLength, OBJC_ASSOCIATION_COPY);
}

- (NSString *)maxTextLength {
    return objc_getAssociatedObject(self, &maxTextLengthKey);
}

- (void)setClickChangeAction:(void (^)(NSString * _Nonnull))clickChangeAction {
    objc_setAssociatedObject(self, kAction, clickChangeAction, OBJC_ASSOCIATION_COPY_NONATOMIC);
}

- (void (^)(NSString * _Nonnull))clickChangeAction {
    return objc_getAssociatedObject(self, kAction);
}

- (void)setLimitPointCountTF:(NSString *)limitPointCountTF {
     objc_setAssociatedObject(self, &limitPointCountTFKey, limitPointCountTF, OBJC_ASSOCIATION_COPY);
}

- (NSString *)limitPointCountTF {
    return objc_getAssociatedObject(self, &limitPointCountTFKey);
}


- (void)setLimitNumTF:(NSString *)limitNumTF {
    objc_setAssociatedObject(self, &limitNumTFKey, limitNumTF, OBJC_ASSOCIATION_COPY);
}

- (NSString *)limitNumTF {
    return objc_getAssociatedObject(self, &limitNumTFKey);
}

@end
