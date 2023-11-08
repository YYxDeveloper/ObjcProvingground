//
//  UIImage+SIMKit.h
//  SAMIM
//
//  Created by ZIKong on 2018/11/16.
//  Copyright © 2018  . All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (SIMKit)
+ (UIImage*)getVideoPreViewImageWithvideoPath:(NSURL *)videoPath;
- (UIImage *)sim_imageForChatUpload;
- (UIImage *)sim_imageForChatThumbnailUpload;//缩略图
- (UIImage *)sim_scaleToSize:(CGSize)newSize;

-(NSData *)compressWithMaxLength:(NSUInteger)maxLength;

@end

NS_ASSUME_NONNULL_END
