//
//  LangPlaygroundVC.m
//  ObjcProvingground
//
//  Created by 呂子揚 on 2023/10/23.
//

#import "LangPlaygroundVC.h"
typedef NS_ENUM(NSInteger, ExhibitionType) {
    ForLanguag,
    ForLocation,
};
@interface LocAndLangExhibitionVeiw:UIView
@property (strong, nonatomic, nullable) UIImageView *witchFlag;
@property (strong, nonatomic) UILabel *exhibitonLabel;
@property (assign, nonatomic) ExhibitionType exhibitionType;

+(instancetype)initWithForLanguagType;
+(instancetype)initWithForLocationType;
-(void)modfiyExhibitionText:(NSString *)conutryOrLangName;
@end

@implementation LocAndLangExhibitionVeiw
+(LocAndLangExhibitionVeiw*)initWithForLanguagType{
    
    LocAndLangExhibitionVeiw* theExhibitionVeiw = [LocAndLangExhibitionVeiw new];
    theExhibitionVeiw.exhibitionType = ForLanguag;
    theExhibitionVeiw.backgroundColor = [UIColor whiteColor];
    UILabel *witchLangLabel = [[UILabel alloc] init];
    theExhibitionVeiw.exhibitonLabel = witchLangLabel;
    //use userdefault appLanguage
    [LocAndLangExhibitionVeiw modifyFontWithLabel:witchLangLabel];
    
    [theExhibitionVeiw addSubview:witchLangLabel];
    
    UIImageView *arrowImageView = [LocAndLangExhibitionVeiw createArrowImageView];
    [theExhibitionVeiw addSubview:arrowImageView];

    [theExhibitionVeiw mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.height.greaterThanOrEqualTo(@(10));
    }];
    
    [witchLangLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.leading.bottom.centerY.equalTo(theExhibitionVeiw);
        
    }];
    [arrowImageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.bottom.centerY.equalTo(theExhibitionVeiw);
        make.trailing.equalTo(theExhibitionVeiw).mas_offset(-7);
    }];
    
    
    return  theExhibitionVeiw;
}


+(instancetype)initWithForLocationType{
    LocAndLangExhibitionVeiw* theExhibitionVeiw = [LocAndLangExhibitionVeiw new];
    theExhibitionVeiw.exhibitionType = ForLocation;
    theExhibitionVeiw.backgroundColor = [UIColor whiteColor];
    
    UILabel *exhibitonLabel = [[UILabel alloc] init];
    theExhibitionVeiw.exhibitonLabel = exhibitonLabel;

    //use userdefault appLanguage
    [LocAndLangExhibitionVeiw modifyFontWithLabel:exhibitonLabel];
    [theExhibitionVeiw addSubview:exhibitonLabel];
    
    UIImageView* witchFlagImageView = [[UIImageView alloc]initWithImage:[UIImage imageNamed:@"Taiwan"]];
    witchFlagImageView.layer.cornerRadius = 5;
    witchFlagImageView.layer.masksToBounds = YES;
    [theExhibitionVeiw addSubview:witchFlagImageView];
    
    UIImageView *arrowImageView = [LocAndLangExhibitionVeiw createArrowImageView];
    [theExhibitionVeiw addSubview:arrowImageView];
    
    [theExhibitionVeiw mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.height.greaterThanOrEqualTo(@(10));
    }];
    [witchFlagImageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.centerY.equalTo(theExhibitionVeiw);
        make.width.equalTo(@(36));
        make.height.equalTo(@(28));

    }];
    [exhibitonLabel mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.leading.centerY.equalTo(witchFlagImageView.mas_trailing).mas_offset(2);
        make.centerY.equalTo(theExhibitionVeiw);
        make.leading.equalTo(theExhibitionVeiw).mas_offset(38);

        make.height.equalTo(@(36));
    }];
    [arrowImageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.bottom.centerY.equalTo(theExhibitionVeiw);
        make.trailing.equalTo(theExhibitionVeiw).mas_offset(-7);
    }];
    
    return theExhibitionVeiw;
}
+(void)modifyFontWithLabel:(UILabel*) theLabel{
    UIFont *boldFont = [UIFont boldSystemFontOfSize:16.0];
    theLabel.textAlignment = NSTextAlignmentLeft;
    theLabel.font = boldFont;
}
+(UIImageView*)createArrowImageView{
    UIImageView *arrowImageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"right_arrow"]];
    arrowImageView.contentMode = UIViewContentModeScaleAspectFit;
    
    return arrowImageView;
}
+(UIStackView*)createStackView{
    UIStackView *stack = [[UIStackView alloc] init];
    stack.distribution = UIStackViewDistributionFillEqually;
    stack.axis = UILayoutConstraintAxisHorizontal;
    stack.backgroundColor = [UIColor whiteColor];
    return  stack;
}
-(void)modfiyExhibitionText:(NSString *)conutryOrLangName;
{
    self.exhibitonLabel.text = conutryOrLangName;
}

@end



@interface LangPlaygroundVC ()

@end

@implementation LangPlaygroundVC

- (void)viewDidLoad {
    [super viewDidLoad];
//    [self insertLanguagePanelUIWithHeight:@76];
    
}
-(void)insertLanguagePanelUIWithHeight:(NSNumber*) height{
    UIView *containerView = [[UIView alloc] init];
    containerView.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:containerView];
    
    [containerView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.view.mas_safeAreaLayoutGuideTop);
        make.trailing.equalTo(self.view);
        make.leading.equalTo(self.view);
        make.height.equalTo(height);
    }];
    [self insertPanelTitleUIInContainerView:containerView layoutHeight:@(38)];
    [self insertPanelSelectViewUIInContainerView:containerView layoutHeight:@(38)];
}
-(void)insertPanelTitleUIInContainerView:(UIView*)container layoutHeight:(NSNumber*) height{
    UIStackView *stack = [LocAndLangExhibitionVeiw createStackView];
    
    [container addSubview:stack];
    [stack mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.view.mas_safeAreaLayoutGuideTop);
        make.trailing.equalTo(self.view).mas_offset(-17);
        make.leading.equalTo(self.view).mas_offset(17);
        make.height.equalTo(height);
    }];
    
    UILabel *langTitle = [[UILabel alloc] init];
    langTitle.text = SIMLocalized(@"語言") ? SIMLocalized(@"語言") : @"Language";
    [LocAndLangExhibitionVeiw modifyFontWithLabel:langTitle];
    [stack addArrangedSubview:langTitle];
    
    UILabel *locationTitle = [[UILabel alloc] init];
    locationTitle.text = SIMLocalized(@"地区") ?  SIMLocalized(@"地区") : @"Location";
    [LocAndLangExhibitionVeiw modifyFontWithLabel:locationTitle];
    [stack addArrangedSubview:locationTitle];
    
    
}
-(void)insertPanelSelectViewUIInContainerView:(UIView*)container layoutHeight:(NSNumber*) height{
    UIStackView *stack = [LocAndLangExhibitionVeiw createStackView];

    [self.view addSubview:stack];

   
    
    [stack mas_makeConstraints:^(MASConstraintMaker *make) {
        make.bottom.equalTo(container);
        make.trailing.equalTo(self.view).mas_offset(-17);
        make.leading.equalTo(self.view).mas_offset(17);
        make.height.equalTo(height);
        
    }];

    LocAndLangExhibitionVeiw *witchLangView = [LocAndLangExhibitionVeiw initWithForLanguagType];
    [self settingExhibitionVeiw:ForLanguag toExhibitionVeiw:witchLangView];
  
   
    [stack addArrangedSubview:witchLangView];

    LocAndLangExhibitionVeiw *witchLocationView = [LocAndLangExhibitionVeiw initWithForLocationType];
    [self settingExhibitionVeiw:ForLocation toExhibitionVeiw:witchLocationView];

    [stack addArrangedSubview:witchLocationView];
    
    
}
-(void)settingExhibitionVeiw:(ExhibitionType) type toExhibitionVeiw:(LocAndLangExhibitionVeiw*) exhibitionVeiw{
    if(type == ForLanguag){
        [exhibitionVeiw modfiyExhibitionText:SIMLocalized(@"語言") ? SIMLocalized(@"語言") : @"繁體中文"];

        UITapGestureRecognizer* tap = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(tapLanguageExhibition)];
        [exhibitionVeiw addGestureRecognizer:tap];

    }else if (type == ForLocation){
        [exhibitionVeiw modfiyExhibitionText:@"traditional chinese"];

        UITapGestureRecognizer* tap = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(tapLocationExhibition)];
        [exhibitionVeiw addGestureRecognizer:tap];

    }

}
-(void)tapLanguageExhibition{
    NSLog(@"cccc");
}
-(void)tapLocationExhibition{
    NSLog(@"aaaaa");
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
