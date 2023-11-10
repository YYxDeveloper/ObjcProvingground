//
//  CustomPGPPurchaseItemTableViewCell.h
//  ObjcProvingground
//
//  Created by 呂子揚 on 2023/11/9.
//

#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

typedef void (^TextFieldDidEdit)(BOOL didEdit);
@interface CustomPGPPurchaseItemTableViewCell : UITableViewCell<UITextFieldDelegate>
@property (weak, nonatomic) IBOutlet UIImageView *selectIcon;
@property (weak, nonatomic) IBOutlet UITextField *textField;
@property (nonatomic, copy) TextFieldDidEdit textFieldDidEdit;
@end

NS_ASSUME_NONNULL_END
