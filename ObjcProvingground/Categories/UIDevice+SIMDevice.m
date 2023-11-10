//
//  UIDevice+SIMDevice.m
//  SAMIM
//
//  Created by ZIKong on 2018/10/15.
//  Copyright © 2018  . All rights reserved.
//

#import "UIDevice+SIMDevice.h"

@implementation UIDevice (SIMDevice)
- (BOOL)isHairHead {
    if (UIInterfaceOrientationIsLandscape([UIApplication sharedApplication].statusBarOrientation)) {
        return self.safeAreaInset.left > 0.0f;
    }else {
        // ios12 非刘海屏状态栏 20.0f
        return self.safeAreaInset.top > 20.0f;
    }
}

- (UIWindow *)keyWindow {
    return [UIApplication sharedApplication].keyWindow;
}

- (UIEdgeInsets)safeAreaInset {
    if (@available(iOS 11.0, *)) {
        if (self.keyWindow) {
            return self.keyWindow.safeAreaInsets;
        }
    }
    return UIEdgeInsetsZero;
}
@end
