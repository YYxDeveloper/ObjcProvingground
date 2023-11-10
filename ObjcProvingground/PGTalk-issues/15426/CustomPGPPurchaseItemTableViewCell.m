//
//  CustomPGPPurchaseItemTableViewCell.m
//  ObjcProvingground
//
//  Created by 呂子揚 on 2023/11/9.
//

#import "CustomPGPPurchaseItemTableViewCell.h"

@implementation CustomPGPPurchaseItemTableViewCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
    self.textField.placeholder = SIMLocalized(@"enter_purchase_pgp_number");
    self.textField.textColor = [UIColor grayColor];
    self.selectionStyle = UITableViewCellSelectionStyleNone;
    self.textField.delegate = self;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}
-(void)textFieldDidBeginEditing:(UITextField *)textField{
    //callback
    if(self.textFieldDidEdit){
        self.textFieldDidEdit(YES);

    }
}
-(void)textFieldDidEndEditing:(UITextField *)textField{
    if(self.textFieldDidEdit){
        self.textFieldDidEdit(NO);
        
    }
}
- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    self.selectIcon.image = [UIImage imageNamed:@"complaints_unselected"];

    [textField resignFirstResponder]; // 關閉鍵盤
    return YES;
}

@end
