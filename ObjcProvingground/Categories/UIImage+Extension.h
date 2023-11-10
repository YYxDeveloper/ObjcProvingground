//
//  UIImage+Extension.h
//  SAMIM
//
//  Created by 121 on 2018/10/9.
//  Copyright © 2018年  . All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Extension)
+ (UIImage *)imageWithColor:(UIColor *)color;
- (UIImage *)fixOrientation;
/**
 *  根据图片名 返回一张可伸缩的图片
 *
 *  @param imageName 图片名
 *
 *  @return 可伸缩的图片
 */
+ (UIImage *)returnResizableImageWithImageName:(NSString *)imageName;

// 给图片添加文字水印：
+ (UIImage *)jx_WaterImageWithImage:(UIImage *)image text:(NSString *)text textPoint:(CGPoint)point attributedString:(NSDictionary * )attributed;
+ (UIImage *)jx_WaterImageWithImage:(UIImage *)image waterImg:(UIImage*)waterImg;
- (UIImage*)rotate:(UIImageOrientation)orient;
//返回当前屏幕截屏图片
+(UIImage *)imageFromView:(UIView *)view;
@end
