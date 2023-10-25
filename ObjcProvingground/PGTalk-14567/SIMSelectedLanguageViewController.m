//
//  SIMSelectedLanguageViewController.m
//  ObjcProvingground
//
//  Created by 呂子揚 on 2023/10/25.
//

#import "SIMSelectedLanguageViewController.h"

@interface SIMSelectedLanguageViewController ()
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
               
                break;
     
            case ForLocation:
                self.countrys = @[@"Taiwan",@"Vietnam"];

                break;
        }
        self.type = type;
        self.contentView = [UIView new];
    }
    return self;
}

-(void)viewDidLoad{
    CGFloat colorValue = 153.0/255.0;
    self.view.backgroundColor = [UIColor colorWithRed:colorValue green:colorValue blue:colorValue alpha:0.5];
    
    [self.view addSubview:self.contentView];
    [self sttingContentViewWithArrayCount:self.countrys.count];
}
- (NSDictionary*)getViewControllerInfo{
    
    NSMutableDictionary* dic = [NSMutableDictionary new];
    dic[@"tableCellHeight"] = @50;
    dic[@"comfiredAreaBarHeight"] = @180;
    
    return [[NSDictionary alloc] initWithDictionary:dic];
}
-(void)sttingContentViewWithArrayCount:(NSInteger)count{
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

/*
 #pragma mark - Navigation
 
 // In a storyboard-based application, you will often want to do a little preparation before navigation
 - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
 // Get the new view controller using [segue destinationViewController].
 // Pass the selected object to the new view controller.
 }
 */

@end
