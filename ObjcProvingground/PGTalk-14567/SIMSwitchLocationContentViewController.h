//
//  SwitchLocationContentViewController.h
//  ObjcProvingground
//
//  Created by 呂子揚 on 2023/11/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, ComparingLocation) {
    NowInVN,
    NowInTW,
    NotChange
};
@interface SIMSwitchLocationContentViewController : UIViewController
@property (assign, nonatomic)ComparingLocation type;
- (instancetype)initWithComparingLocation:(ComparingLocation) type;

@end

NS_ASSUME_NONNULL_END
