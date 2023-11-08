//
//  NSString+Size.m
//  WenMingShuo
//
//  Created by Six on 16/1/4.
//  Copyright © 2016年 Six. All rights reserved.
//

#import "NSString+Size.h"

@implementation NSString (Size)

/**
 *  计算文字大小
 *
 *  @param font    文字字体大小
 *  @param maxSize 最大Size
 *
 *  @return 文字Size
 */
- (CGSize)returnStrSizeWithFont:(UIFont *)font maxSize:(CGSize)maxSize
{
    return [self boundingRectWithSize:maxSize options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName : font} context:nil].size;
}

//根据宽度求高度  content 计算的内容  width 计算的宽度 font字体大小
+ (CGFloat)getLabelHeightWithText:(NSString *)text width:(CGFloat)width font: (CGFloat)font
{
    CGRect rect = [text boundingRectWithSize:CGSizeMake(width, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName : [UIFont systemFontOfSize:font]} context:nil];
    
    return rect.size.height;
}
//根据高度度求宽度  text 计算的内容  Height 计算的高度 font字体大小
+ (CGFloat)getWidthWithText:(NSString *)text height:(CGFloat)height font:(CGFloat)font {
    
    CGRect rect = [text boundingRectWithSize:CGSizeMake(MAXFLOAT, height)
                                     options:NSStringDrawingUsesLineFragmentOrigin
                                  attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:font]}
                                     context:nil];
    return rect.size.width;
}


+ (CGSize)sizeOfString:(NSString *)str font:(UIFont *)font width:(CGFloat)width{
    
    
    NSDictionary * attributes = @{NSFontAttributeName :font};
    
    CGSize contentSize = [str boundingRectWithSize:CGSizeMake(width, MAXFLOAT)
                                           options:NSStringDrawingUsesLineFragmentOrigin
                                        attributes:attributes
                                           context:nil].size;
    return contentSize;
}

@end
