//
//  DefaultPGPPurchaseItemView.h
//  ObjcProvingground
//
//  Created by 呂子揚 on 2023/11/8.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DefaultPGPPurchaseItemView : UIView
@property (strong, nonatomic) NSNumber *defaultHight;

-(instancetype)initForPGP;
-(void)setTOPCornerRadiusAtViewDidLoad;

@end

NS_ASSUME_NONNULL_END
