//
//  SIMSelectedLanguageViewController.m
//  ObjcProvingground
//
//  Created by 呂子揚 on 2023/10/25.
//

#import "SIMSelectedLanguageViewController.h"

@interface SIMSelectedLanguageViewController ()
@property (strong, nonatomic) UILabel* topTitle;
@property (strong, nonatomic) UIView* contentView;
@property (nonatomic,strong) NSArray<NSString *> *countrys;
@property (assign, nonatomic) ExhibitionType type;


@end

@implementation SIMSelectedLanguageViewController

-(instancetype)initWitchExhibition:(ExhibitionType)type {
    self = [super init]; // 調用父類的初始化方法
    if (self) {
        switch (type) {
            case ForLanguag:
            self.countrys = @[@"Taiwan",@"China",@"English",@"Japan",@"Korea",@"Thailand",@"Vietnam"];
                self.topTitle = [UILabel new];
                self.topTitle.text = SIMLocalized(@"語言");
                break;
     
            case ForLocation:
                self.countrys = @[@"Taiwan",@"Vietnam"];
                self.topTitle = [UILabel new];
                self.topTitle.text = SIMLocalized(@"服務地區");

                break;
        }
        [SIMSelectedLanguageViewController modifyFontWithLabel:self.topTitle];
        self.type = type;
        self.contentView = [UIView new];
        self.btnConfirm = [UIButton new];
        self.btnBack = [UIButton new];
    }
    return self;
}

-(void)viewDidLoad{
    CGFloat colorValue = 153.0/255.0;
    self.view.backgroundColor = [UIColor colorWithRed:colorValue green:colorValue blue:colorValue alpha:0.5];
    [self joinSunViews];
    [self designSubViewsLayout];
}
-(void)joinSunViews{
    [self.view addSubview:self.contentView];
    [self.contentView addSubview:self.topTitle];
    [self.contentView addSubview:self.btnConfirm];
    [self.contentView addSubview:self.btnBack];

}
-(void)designSubViewsLayout{
    [self designLayoutOfContentViewWithArrayCount:self.countrys.count];
    [self designLayoutOfTopTitle];
}

- (NSDictionary*)getViewControllerInfo{
    
    NSMutableDictionary* dic = [NSMutableDictionary new];
    dic[@"tableCellHeight"] = @50;
    dic[@"comfiredAreaBarHeight"] = @180;
    
    return [[NSDictionary alloc] initWithDictionary:dic];
}
-(void)designLayoutOfTopTitle{
//    lblTitle.text = SIMLocalized(@"设定Email");
//    lblTitle.textColor = RGB(51,51,51);
//    lblTitle.font = SIMBoldFont(18);
//    [contentView addSubview:lblTitle];
//    [lblTitle mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.top.offset(30);
//        make.centerX.offset(0);
//    }];
    [self.topTitle mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.offset(30);
        make.centerX.offset(0);
    }];
}
-(void)designLayoutOfContentViewWithArrayCount:(NSInteger)count{
    NSNumber *tableCellHeight = [[self getViewControllerInfo] objectForKey:@"tableCellHeight"];
    NSNumber *headerAndFootBarHeight = [[self getViewControllerInfo] objectForKey:@"comfiredAreaBarHeight"];
    
    NSInteger tableHeigh = [tableCellHeight integerValue] * count;
    NSInteger totalHeight = tableHeigh + [headerAndFootBarHeight integerValue];
    
//    NSNumber* tableHeighNum = [NSNumber numberWithInt:tableHeigh];
    
    
    
    self.contentView.backgroundColor = [UIColor whiteColor];
    [_contentView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.center.equalTo(self.view);
        make.height.equalTo(@(totalHeight));
        make.leading.equalTo(@50);
        make.trailing.equalTo(@-50);

    }];
}
+(void)modifyFontWithLabel:(UILabel*) theLabel{
    UIFont *boldFont = [UIFont boldSystemFontOfSize:18.0];
    theLabel.textAlignment = NSTextAlignmentLeft;
    theLabel.font = boldFont;
}

@end
