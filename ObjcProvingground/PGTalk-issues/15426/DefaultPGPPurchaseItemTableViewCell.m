//
//  DefaultPGPPurchaseItemTableViewCell.m
//  ObjcProvingground
//
//  Created by 呂子揚 on 2023/11/9.
//

#import "DefaultPGPPurchaseItemTableViewCell.h"

@implementation DefaultPGPPurchaseItemTableViewCell

- (void)awakeFromNib {
    [super awakeFromNib];
    self.selectionStyle = UITableViewCellSelectionStyleNone;
//    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(gotClick)];
//    [self.selectIcon addGestureRecognizer:tap];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];
    
    // Configure the view for the selected state
}

@end
