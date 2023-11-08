//
//  UIViewController+LNavigationBarHidden.h
//  venusVip
//
//  Created by hfkj on 2019/4/23.
//  Copyright © 2019 com.jinXing. All rights reserved.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (LNavigationBarHidden)

/// 是否隐藏导航栏。默认NO。
@property (nonatomic , assign) BOOL shouldNavigationBarHidden;

///恢复导航栏到默认状态 viewWillAppear
- (void)resetNavigationBg;

/// 设置导航栏透明 viewWillAppear
- (void)setTransparentNavigationBg;

@end


NS_ASSUME_NONNULL_END
