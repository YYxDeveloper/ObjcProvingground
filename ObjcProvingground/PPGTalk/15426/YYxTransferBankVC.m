//
//  YYxTransferBankVC.m
//  ObjcProvingground
//
//  Created by 呂子揚 on 2023/11/8.
//

#import "YYxTransferBankVC.h"
#import "UIColor+FlatUI.h"
#import <YYKit/YYKit.h>
#import "SIMCustomDefine.h"
#import "UILabel+LCreate.h"
@interface YYxTransferBankVC ()
///标题
@property (nonatomic, strong) UILabel *headerTitleLabel;
///余额
@property (nonatomic, strong) UILabel *headerMoneyLabel;
///输入金额
@property (nonatomic, strong) UITextField *headerMoneyTextField;
///单位
@property (nonatomic, strong) UILabel *MoneyTypeLabel;

///尾部标题
@property (nonatomic, strong) UILabel *footerTitleLabel;
///输入的金额
@property (nonatomic, strong) UILabel *footerMoneyLabel;

///默认金额
@property (nonatomic, strong) UILabel *placeholderLabel;

//@property (nonatomic, strong) UICollectionView *bankView;
//@property (nonatomic, strong) UITableView *bankView;

@property (nonatomic, strong) NSMutableArray *dataArray;

@property (nonatomic, assign) NSInteger pageNo;

@property (nonatomic, strong) UIButton *confirmBtn;

//@property (nonatomic, strong) SIMTransferBankModel *bankModel;

@property(nonatomic,strong)UIButton *recordBtn;

@property (nonatomic, strong) NSString * highPGP;

@property (nonatomic, strong) NSString * topOnePGP;

@property (nonatomic, strong) NSString * topTwoPGP;

@property (nonatomic, strong) NSMutableArray * topOneArr;

@property (nonatomic, strong) NSMutableArray * topTwoArr;

///linepay
@property (nonatomic, strong) NSMutableArray * topThreeArr;

@property (nonatomic, strong) NSString * selectTipsString;

@property (nonatomic, assign) BOOL isOpenCredit;
//@property (nonatomic, strong) SIMBankDetailModel * model;
@property (nonatomic, strong) NSString * payType;
@property (nonatomic,strong) UIView * v;
@end

@implementation YYxTransferBankVC

- (void)viewDidLoad {
    [super viewDidLoad];
    [self configUI];
    // Do any additional setup after loading the view.
}
- (void)configUI {
    
    self.view.backgroundColor = [UIColor colorFromHexCode:@"#FCFCFF"];
    
    // 136
    UIView *topView = [[UIView alloc]initWithFrame:CGRectMake(0, 0, kScreenWidth, 136 + 6)];
    
    UIView *bgView = [[UIView alloc]initWithFrame:CGRectMake(0, 16, kScreenWidth, 124)];
    bgView.backgroundColor = UIColor.whiteColor;
    bgView.layer.cornerRadius = 18;
    bgView.layer.maskedCorners = kCALayerMinXMinYCorner | kCALayerMaxXMinYCorner;
    [topView addSubview:bgView];
    
    self.headerTitleLabel = [UILabel new];
    [bgView addSubview:self.headerTitleLabel];
    self.headerTitleLabel.text = SIMLocalized(@"輸入購買PGP數量");
    self.headerTitleLabel.font = SIMBoldFont(14);
    [self.headerTitleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.mas_equalTo(15);
        make.top.mas_equalTo(20);
    }];
    
    self.headerMoneyLabel = [UILabel new];
    [bgView addSubview:self.headerMoneyLabel];
    self.headerMoneyLabel.text = [NSString stringWithFormat:@"%@-",SIMLocalized(@"PGP餘額:")];
    self.headerMoneyLabel.textAlignment = NSTextAlignmentRight;
    self.headerMoneyLabel.font = SIMSystemFontWeightRegular(12);
    self.headerMoneyLabel.textColor = RGBA(153, 153, 153, 1);
    [self.headerMoneyLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerY.mas_equalTo(self.headerTitleLabel);
        make.trailing.mas_equalTo(-15);
    }];
    
    self.headerMoneyTextField = [UITextField new];
    [bgView addSubview:self.headerMoneyTextField];
    //    self.headerMoneyTextField.placeholder = @"0";
    self.headerMoneyTextField.delegate = self;
    self.headerMoneyTextField.keyboardType = UIKeyboardTypeNumberPad;
    self.headerMoneyTextField.borderStyle = UITextBorderStyleRoundedRect;
    [self.headerMoneyTextField addTarget:self action:@selector(onTextFieldEditChanged:) forControlEvents:UIControlEventEditingChanged];
    
    self.headerMoneyTextField.font = SIMBoldFont(28);
    [self.headerMoneyTextField mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.mas_equalTo(15);
        //        make.top.mas_equalTo(self.headerTitleLabel.mas_bottom);
        make.bottom.offset(-15);
        make.height.mas_equalTo(60);
        make.trailing.mas_equalTo(-21);
    }];
    
    self.placeholderLabel = [UILabel new];
    [bgView addSubview:self.placeholderLabel];
    self.placeholderLabel.textColor = RGBA(102, 102, 102, 1);
    self.placeholderLabel.font = SIMBoldFont(28);
    self.placeholderLabel.text = @"0";
    [self.placeholderLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.mas_equalTo(22);
        //        make.top.mas_equalTo(self.headerTitleLabel.mas_bottom);
        //        make.height.mas_equalTo(60);
        make.centerY.equalTo(self.headerMoneyTextField);
        make.trailing.mas_equalTo(-15);
    }];
    
    self.MoneyTypeLabel = [UILabel new];
    [bgView addSubview:self.MoneyTypeLabel];
    self.MoneyTypeLabel.text = SIMLocalized(@"PGP");
    self.MoneyTypeLabel.textAlignment = NSTextAlignmentRight;
    self.MoneyTypeLabel.font = SIMSystemFontWeightRegular(14);
    [self.MoneyTypeLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        //        make.top.mas_equalTo(self.headerTitleLabel.mas_bottom);
        //        make.height.mas_equalTo(60);
        make.centerY.equalTo(self.headerMoneyTextField);
        make.trailing.mas_equalTo(-30);
    }];
    
    UIView *bottomView = [[UIView alloc]init];
    bottomView.backgroundColor = RGBA(250, 250, 253, 1);
    [topView addSubview:bottomView];
    [bottomView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.bottom.offset(0);
        make.height.offset(6);
    }];
    
    [self.view addSubview:topView];
    [topView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.left.right.offset(0);
        make.height.offset(136 + 6);
    }];
    
//    [self.view addSubview:self.bankView];
//    [self.bankView mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.leading.trailing.mas_equalTo(self.view);
//        make.top.equalTo(topView.mas_bottom);
//        make.bottom.mas_equalTo(- 34 - 44 - 44);
//    }];
    //    self.bankView.tableHeaderView = topView;
    
    UIView *footerView = [[UIView alloc]initWithFrame:CGRectMake(0, 0, 0, 300)];
    footerView.backgroundColor = UIColor.clearColor;
    UILabel *label = [UILabel labelWithText:@"" textColor:RGBA(102, 102, 102, 1) font:SystemFont(14)];
    label.numberOfLines = 0;
    NSString *str = [NSString stringWithFormat:@"%@\n\n%@\n%@",SIMLocalized(@"PGP消費點數用途及購買方式跟退款方式："),SIMLocalized(@"凡是購買PGP點數必礦任何合作關係商戶皆可使用！購買之PGP點數皆已交付『陽信銀行信託專戶』中予以承認擔保，如未使用完之點數，可參考隱私權及服務條例中第十一項條例，PGP返還方式規定予以申請退款。"),SIMLocalized(@"活動贈送的PT點數，僅限於消費抵扣使用，未使用之贈送點數，將無法兌換現金退款。")];
    NSMutableAttributedString *attributedString = [[NSMutableAttributedString alloc] initWithString:str];
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
    [paragraphStyle setLineSpacing:4];
    [attributedString addAttribute:NSParagraphStyleAttributeName value:paragraphStyle range:NSMakeRange(0, [str length])];
    label.attributedText = attributedString;
    
    CGFloat textHeight = [label sizeThatFits:CGSizeMake((kScreenWidth - 30) - 15 - 30, MAXFLOAT)].height;
    label.frame = CGRectMake(15, 17, (kScreenWidth - 30) - 15 - 35, textHeight + 44);
    
    UIView *labelBgView = [[UIView alloc]initWithFrame:CGRectMake(15, 20, kScreenWidth - 30, textHeight + 84)];
    labelBgView.backgroundColor = RGBA(245, 245, 248, 1);
    labelBgView.layer.cornerRadius = 4.f;
    labelBgView.layer.masksToBounds = YES;
    [labelBgView addSubview:label];
    
    [footerView addSubview:labelBgView];
    footerView.frame = CGRectMake(0, 0, 0, labelBgView.height + 40);
//    self.bankView.tableFooterView = footerView;
    
    UIView *confirmView = [[UIView alloc]init];
    confirmView.backgroundColor = UIColor.whiteColor;
    
    UIView *line = [[UIView alloc]initWithFrame:CGRectMake(0, 0, kScreenWidth, 0.5)];
    line.backgroundColor = RGBA(233, 237, 240, 1);
    [confirmView addSubview:line];
    
    [self.view addSubview:confirmView];
//    [confirmView mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.top.mas_equalTo(self.bankView.mas_bottom);
//        make.left.right.bottom.offset(0);
//    }];
    
    
    [confirmView addSubview:self.confirmBtn];
    [self.confirmBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.equalTo(confirmView);
        make.bottom.mas_equalTo(-32);
    }];
    
    self.footerTitleLabel = [UILabel new];
    [confirmView addSubview:self.footerTitleLabel];
    self.footerTitleLabel.text = [NSString stringWithFormat:@"%@ %@", SIMLocalized(@"支付NT $"),@"(1PGP=NT $1)"];
    self.footerTitleLabel.font = SIMSystemFontWeightRegular(14);
    self.footerTitleLabel.textColor = [UIColor colorFromHexCode:@"#999999"];
    [self.footerTitleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.mas_equalTo(15);
        make.top.offset(10);
    }];
    
    self.footerMoneyLabel = [UILabel new];
    [confirmView addSubview:self.footerMoneyLabel];
    self.footerMoneyLabel.text = @"0";
    self.footerMoneyLabel.textAlignment = NSTextAlignmentRight;
    self.footerMoneyLabel.font = SIMSystemFontWeightRegular(14);
    self.footerMoneyLabel.textColor = [UIColor colorFromHexCode:@"#999999"];
    
    [self.footerMoneyLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.offset(10);
        make.trailing.mas_equalTo(-15);
    }];
    
    
    
//    [self headerView];
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
