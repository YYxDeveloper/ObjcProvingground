//
//  UIDevice+SIMDevice.h
//  SAMIM
//
//  Created by ZIKong on 2018/10/15.
//  Copyright © 2018  . All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIDevice (SIMDevice)
///*
// * 是否是刘海屏
// * */
//@property (nonatomic, assign, readonly) BOOL isHairHead;
- (BOOL)isHairHead;
@end

NS_ASSUME_NONNULL_END
