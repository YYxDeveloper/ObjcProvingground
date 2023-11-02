//
//  SwitchLocationContentViewController.m
//  ObjcProvingground
//
//  Created by 呂子揚 on 2023/11/2.
//

#import "SIMSwitchLocationContentViewController.h"

@interface SIMSwitchLocationContentViewController ()
@property (strong, nonatomic) UIView*contentView;
@property (strong, nonatomic) UIButton* closeBtn;
@property (strong, nonatomic) UIButton* switchToOtherLocationBtn;
@property (strong, nonatomic) UIButton* keepThisLocationBtn;
@property (strong, nonatomic) UILabel* tipHeadlineLable;
@property (strong, nonatomic) UILabel* tipContentLable;




@end

@implementation SIMSwitchLocationContentViewController
-(UIView *)contentView{
    if (!_contentView) {
        _contentView = [UIView new];
        _contentView.backgroundColor = [UIColor whiteColor];
        _contentView.layer.cornerRadius = 8;
    }
    return _contentView;
}
-(UILabel *)tipHeadlineLable{
    if (!_tipHeadlineLable) {
        _tipHeadlineLable = [UILabel new];
        _tipHeadlineLable.text = @"定位提示";
        _tipContentLable.textColor = [UIColor blackColor];
        _tipHeadlineLable.font = [UIFont systemFontOfSize:14];
    }
    return _tipHeadlineLable;
}
-(UILabel *)tipContentLable{
    if (!_tipContentLable) {
        _tipContentLable = [UILabel new];
        _tipContentLable.text = @"您的位置與選擇的國家不一致，是否切換到選擇的國家？";
        _tipContentLable.textColor = [UIColor grayColor] ;
        _tipContentLable.font = [UIFont systemFontOfSize:14];
        _tipContentLable.numberOfLines = 0;
    }
    return _tipContentLable;
}
-(UIButton *)switchToOtherLocationBtn{
    if (!_switchToOtherLocationBtn) {
        _switchToOtherLocationBtn = [UIButton new];
        [_switchToOtherLocationBtn setTitle:@"切換" forState:UIControlStateNormal];
        [_switchToOtherLocationBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
        [_switchToOtherLocationBtn addTarget:self action:@selector(switchToOtherLocation) forControlEvents:UIControlEventTouchUpInside];
        [_switchToOtherLocationBtn setBackgroundColor:[UIColor redColor]];
    }
    return _switchToOtherLocationBtn;
}
-(UIButton *)keepThisLocationBtn{
    if (!_keepThisLocationBtn) {
        _keepThisLocationBtn = [UIButton new];
        [_keepThisLocationBtn setTitle:@"保持" forState:UIControlStateNormal];
        [_keepThisLocationBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
        [_keepThisLocationBtn addTarget:self action:@selector(closeThisView) forControlEvents:UIControlEventTouchUpInside];
        [_keepThisLocationBtn setBackgroundColor:[UIColor redColor]];
    }
    return _keepThisLocationBtn;
}
- (UIButton*)closeBtn

{
    
    if (!_closeBtn) {
        
        _closeBtn = [UIButton new];
        [_closeBtn addTarget:self action:@selector(closeThisView) forControlEvents:UIControlEventTouchUpInside];
        [_closeBtn setImage:[UIImage systemImageNamed:@"xmark"] forState:UIControlStateNormal];
        
    }
    
    return _closeBtn;
    
}
- (instancetype)initWithComparingLocation:(ComparingLocation) type
{
    self = [super init];
    if (self) {
        self.type = type;
        CGFloat colorValue = 153.0/255.0;
        self.view.backgroundColor = [UIColor colorWithRed:colorValue green:colorValue blue:colorValue alpha:0.5];

    }
    return self;
}
- (void)viewDidLoad {
    [super viewDidLoad];
    UITapGestureRecognizer* tap = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(closeThisView)];
    [self.view addGestureRecognizer:tap];
    [self timeToAddSubViews];
    [self timeToLayoutSubViews];
    
}
-(void)timeToAddSubViews{
    [self.view addSubview:self.contentView];
    [self.contentView addSubview:self.tipHeadlineLable];
    [self.contentView addSubview:self.tipContentLable];
    [self.contentView addSubview:self.closeBtn];
    [self.contentView addSubview:self.switchToOtherLocationBtn];
    [self.contentView addSubview:self.keepThisLocationBtn];

}
-(void)timeToLayoutSubViews{
    [self.contentView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.center.equalTo(self.view);
        make.width.equalTo(@(270));
        make.height.equalTo(@(277));
    }];
    [self.closeBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.top.equalTo(self.contentView).offset(10);
        make.width.height.equalTo(@(15));
    }];
    [self.tipHeadlineLable mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(_contentView).offset(20);
        make.centerX.equalTo(_contentView);
        make.height.equalTo(@16);
    }];
    [self.tipContentLable mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(_tipHeadlineLable.mas_bottom).offset(20);
        make.bottom.greaterThanOrEqualTo(_switchToOtherLocationBtn.mas_top).offset(-20);
        make.centerX.equalTo(_contentView);
        make.width.equalTo(@(230));
    }];
    [self.switchToOtherLocationBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(_tipContentLable.mas_bottom).offset(20);
        make.centerX.equalTo(_contentView);
        make.height.equalTo(@(40));
        make.leading.equalTo(_contentView).offset(40);
        make.trailing.equalTo(_contentView).offset(-40);
    }];
    [self.keepThisLocationBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(_switchToOtherLocationBtn.mas_bottom).offset(20);
        make.centerX.equalTo(_contentView);
        make.height.equalTo(@(40));

        make.bottom.equalTo(_contentView).offset(-20);
        make.leading.equalTo(_contentView).offset(40);
        make.trailing.equalTo(_contentView).offset(-40);

    }];
}
-(void)closeThisView{
    [self dismissViewControllerAnimated:NO completion:nil];
}
-(void)switchToOtherLocation{
    
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
