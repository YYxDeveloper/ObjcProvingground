//
//  UIViewController+LNavigationBarHidden.m
//  venusVip
//
//  Created by hfkj on 2019/4/23.
//  Copyright © 2019 com.jinXing. All rights reserved.
//

#import "UIViewController+LNavigationBarHidden.h"
#import <objc/runtime.h>

@implementation UIViewController (LNavigationBarHidden)

- (BOOL)shouldNavigationBarHidden{
    return [objc_getAssociatedObject(self, @selector(shouldNavigationBarHidden)) boolValue];
}

- (void)setShouldNavigationBarHidden:(BOOL)shouldNavigationBarHidden{
    objc_setAssociatedObject(self, @selector(shouldNavigationBarHidden), @(shouldNavigationBarHidden), OBJC_ASSOCIATION_ASSIGN);
}


//恢复导航栏到默认状态，以防止某个界面的导航栏设置为透明之后会影响其它界面可以在需要的界面的 viewWillAppear 方法里面调用该方法
- (void)resetNavigationBg
{
//    UIView *barBackgroundView = [[UIView alloc] initWithFrame:CGRectMake(0, -SIMState_Height, [UIScreen mainScreen].bounds.size.width, SIMState_Height+44)];
//    //调用UIView 类扩展方法
//    [barBackgroundView addGradualLayerWithColors:nil];
//    UIImage *backImage = [barBackgroundView snapshotImage];
//    [self.navigationController.navigationBar setBackgroundImage:backImage forBarMetrics:UIBarMetricsDefault];
//    self.navigationController.navigationBar.translucent = NO;
//    self.navigationController.view.backgroundColor = [UIColor whiteColor];
//    self.navigationController.navigationBar.backgroundColor = [UIColor whiteColor];
//    if (@available(iOS 13.0, *)) {
//        UINavigationBarAppearance *appearance = [UINavigationBarAppearance new];
////        [appearance configureWithOpaqueBackground];
//
////        appearance.backgroundColor = [UIColor yellowColor];
//        appearance.titleTextAttributes = @{NSForegroundColorAttributeName : RGB(255, 255, 255) , NSFontAttributeName : SIMBoldFont(18)};
//        [appearance setBackgroundImage:backImage];
//        [appearance setShadowImage:[UIImage new]];
//
//        self.navigationController.navigationBar.standardAppearance = appearance;
//
//        self.navigationController.navigationBar.scrollEdgeAppearance=self.navigationController.navigationBar.standardAppearance;
//    } else {
//        // Fallback on earlier versions
//    }
}
// 设置导航栏透明
- (void)setTransparentNavigationBg
{
    //navigation标题文字颜色
    NSDictionary *dic = @{NSForegroundColorAttributeName : [UIColor whiteColor],
                          NSFontAttributeName : [UIFont systemFontOfSize:18]};
    if (@available(iOS 13.0, *)) {
        UINavigationBarAppearance *barApp = [UINavigationBarAppearance new];
        barApp.backgroundColor = [UIColor clearColor];
        barApp.titleTextAttributes = dic;
        barApp.backgroundEffect = nil;
        barApp.shadowColor = nil;
        self.navigationController.navigationBar.scrollEdgeAppearance = nil;
        self.navigationController.navigationBar.standardAppearance = barApp;
    }else{
        [self.navigationController.navigationBar setBackgroundImage:[UIImage new] forBarMetrics:UIBarMetricsDefault];
        self.navigationController.navigationBar.shadowImage = [UIImage new];
        self.navigationController.navigationBar.translucent = YES;
        self.navigationController.view.backgroundColor = [UIColor clearColor];

    }
    self.navigationController.navigationBar.backgroundColor = [UIColor clearColor];
    //透明
    self.navigationController.navigationBar.translucent = YES;
    //navigation控件颜色
    self.navigationController.navigationBar.tintColor = [UIColor whiteColor];
    
}

@end



