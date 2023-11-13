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
    self.enterPriceTextField.placeholder = SIMLocalized(@"enter_purchase_pgp_number");
    self.enterPriceTextField.textColor = [UIColor grayColor];
    self.selectionStyle = UITableViewCellSelectionStyleNone;
    self.enterPriceTextField.delegate = self;
    // Create a toolbar with a "Return" button
    UIToolbar *numberPadToolbar = [[UIToolbar alloc] initWithFrame:CGRectMake(0, 0, self.frame.size.width, 44)];
    UIBarButtonItem *doneButton = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(doneButtonTapped)];
    UIBarButtonItem *flexibleSpace = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace target:nil action:nil];
    
    numberPadToolbar.items = @[flexibleSpace, doneButton];
    self.enterPriceTextField.inputAccessoryView = numberPadToolbar;
    
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];
    
    // Configure the view for the selected state
}
-(void)textFieldDidBeginEditing:(UITextField *)textField{
    self.enterPriceTextField.text = @"";
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
-(BOOL)checkEnterPriceGreater10PGP:(NSString*)feildText{
    NSNumberFormatter *numberFormatter = [[NSNumberFormatter alloc] init];
    NSNumber *convertedNumber = [numberFormatter numberFromString:feildText];
    if (convertedNumber != nil) {
        return [convertedNumber integerValue] > 10 ? YES : NO;
    } else {
        return NO;;
    }
}
-(BOOL)checkEnterPriceCountLess8Length:(NSString*)feildText{
    NSNumberFormatter *numberFormatter = [[NSNumberFormatter alloc] init];
    NSNumber *convertedNumber = [numberFormatter numberFromString:feildText];
    if (convertedNumber != nil) {
        return feildText.length <= 8 ? YES : NO;
    } else {
        return NO;;
    }
}
-(void)doneButtonTapped{
    [self.enterPriceTextField resignFirstResponder]; // 關閉鍵盤
    
}
@end
