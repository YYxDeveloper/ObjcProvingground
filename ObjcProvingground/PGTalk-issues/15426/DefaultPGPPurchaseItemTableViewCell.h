//
//  DefaultPGPPurchaseItemTableViewCell.h
//  ObjcProvingground
//
//  Created by 呂子揚 on 2023/11/9.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef void (^ClickCallbackBlock)(NSInteger witchRow);
@interface DefaultPGPPurchaseItemTableViewCell : UITableViewCell
@property (weak, nonatomic) IBOutlet UIImageView *selectIcon;
@property (weak, nonatomic) IBOutlet UILabel *howMuchPGPLabel;

@end

NS_ASSUME_NONNULL_END
