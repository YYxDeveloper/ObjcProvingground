//
//  YYxTransferBankVC.m
//  ObjcProvingground
//
//  Created by 呂子揚 on 2023/11/8.
//

#import "YYxTransferBankVC.h"
#import "UIView+CustomCorner.h"
#import <YYKit/YYKit.h>
#import "SIMCustomDefine.h"
#import "DefaultPGPPurchaseItemView.h"
@interface YYxTransferBankVC ()
@property (strong, nonatomic) DefaultPGPPurchaseItemView *pgpitemsView;

@end

@implementation YYxTransferBankVC
    
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self addThisSubViews];
    [self layoutThisSubViews];
    [self.pgpitemsView setTOPCornerRadiusAtViewDidLoad];
}
-(void)addThisSubViews{
    self.pgpitemsView = [[DefaultPGPPurchaseItemView alloc] initForPGP];
    [self.view addSubview:self.pgpitemsView];
}
-(void)layoutThisSubViews{
    [self.pgpitemsView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.trailing.bottom.equalTo(self.view);
        make.height.equalTo(self.pgpitemsView.defaultHight);
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
