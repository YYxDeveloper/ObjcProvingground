//
//  SIMBaseCheckoutTableViewCell.m
//  SAMIM
//
//  Created by 121 on 2018/10/15.
//  Copyright © 2018年  . All rights reserved.
//

#import "SIMBaseCheckoutTableViewCell.h"
#import "SIMCustomDefine.h"
#import "NSDictionary+safeDictionary.h"
@interface SIMBaseCheckoutTableViewCell ()
@property (nonatomic,strong) UILabel * titleLabel;
@property (nonatomic,strong) UIImageView * checkoutImgView;
@property (nonatomic,strong) UIImageView *iconImageView;
@end

@implementation SIMBaseCheckoutTableViewCell

-(instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier{
    
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        
        [self.contentView addSubview:self.iconImageView];
        [self.contentView addSubview:self.titleLabel];
        [self.contentView addSubview:self.checkoutImgView];
        
        [self.iconImageView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.centerY.equalTo(self.contentView);
            make.left.equalTo(self.contentView).mas_offset(15);
            make.size.mas_equalTo(CGSizeMake(30, 20));
        }];
        [self.checkoutImgView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.centerY.equalTo(self.contentView);
            make.right.equalTo(self.contentView).mas_offset(-15);
            make.size.mas_equalTo(CGSizeMake(22, 22));
        }];
        
        [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.centerY.equalTo(self.contentView);
            make.left.equalTo(self.contentView).mas_offset(15);
            make.right.equalTo(self.checkoutImgView.mas_left).mas_offset(-15);
//            make.height.mas_equalTo(30);
        }];
    }
    return self;
}

-(void)setModel:(NSDictionary *)model
{
    _model = model;
    self.titleLabel.text = [model stringForKey:@"title"];
    NSString * value = [model stringForKey:@"value"];
    if (value.integerValue == CheckoutTypeNone) {
        self.checkoutImgView.image = SIMLoadImageName(@"icon_checkout_unselect");
    }
    else if (value.integerValue == CheckoutTypeSelect)
    {
        self.checkoutImgView.image = SIMLoadImageName(@"complaints_selected");
    }
    else if (value.integerValue == CheckoutTypeDefault)
    {
        self.checkoutImgView.image = SIMLoadImageName(@"icon_checkout_default");
    }
}

- (void)setIcon:(NSString *)icon
{
    _icon = icon;
    self.iconImageView.image = SIMLoadImageName(icon);
    [self.titleLabel mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.iconImageView).mas_offset(45);
        make.centerY.equalTo(self.contentView);
        make.right.equalTo(self.checkoutImgView).mas_offset(15);
        make.height.mas_equalTo(30);
    }];
}

#pragma mark -- 懒
-(UILabel *)titleLabel
{
    if (!_titleLabel) {
        _titleLabel = [[UILabel alloc]init];
        _titleLabel.font = SIMSystemFont(15);
        _titleLabel.textColor = RGB(0, 0, 0);
        _titleLabel.numberOfLines = 0;
    }
    return _titleLabel;
}

-(UIImageView *)checkoutImgView
{
    if (!_checkoutImgView) {
        _checkoutImgView = [[UIImageView alloc]init];
        UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapCheckOut)];
        [self.checkoutImgView addGestureRecognizer:tap];
    }
    return _checkoutImgView;
}

- (UIImageView *)iconImageView
{
    if (!_iconImageView) {
        _iconImageView = [[UIImageView alloc] init];
    }
    return _iconImageView;;
}
-(void)tapCheckOut{

}
@end
