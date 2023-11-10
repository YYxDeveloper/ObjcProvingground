//
//  UIImage+SIMResize.h
//  SAMIM
//
//  Created by ZIKong on 2018/10/25.
//  Copyright © 2018  . All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (SIMResize)
//按形状切割图像
- (UIImage*)cutImageWithRadius:(int)radius;
+ (UIImage *)rotateImage:(UIImage *)aImage ;
@end

NS_ASSUME_NONNULL_END
