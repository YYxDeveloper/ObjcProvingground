//
//  DefaultPGPPurchaseItemView.m
//  ObjcProvingground
//
//  Created by 呂子揚 on 2023/11/8.
//
#import "UIView+CustomCorner.h"
#import "DefaultPGPPurchaseItemView.h"
#import "ObjcProvingground-Swift.h"
#import "DefaultPGPPurchaseItemTableViewCell.h"
#import "CustomPGPPurchaseItemTableViewCell.h"
@interface DefaultPGPPurchaseItemView()<UITableViewDelegate,UITableViewDataSource>
@property (strong, nonatomic) UILabel *topicLabel;
@property (strong, nonatomic) UILabel* pgpBalanceLabel;
@property (strong, nonatomic) UITableView* purchasePriceTableView;
@property (strong, nonatomic) NSArray<NSString*>* prices;
@property (nonatomic,assign) NSNumber* checkoutIndexPath;

@end
@implementation DefaultPGPPurchaseItemView
- (UILabel*)topicLabel
{
    if (!_topicLabel) {
        _topicLabel = [UILabel new];
        _topicLabel.text = SIMLocalized(@"select_purchase_pgp_number");
    }
    return _topicLabel;
}
- (UILabel*)pgpBalanceLabel
{
    if (!_pgpBalanceLabel) {
        _pgpBalanceLabel = [UILabel new];
        _pgpBalanceLabel.text = [NSString stringWithFormat:@"%@%@",SIMLocalized(@"pgp_balance_number"),@"0"];
        _pgpBalanceLabel.textColor = [UIColor lightGrayColor];
        _pgpBalanceLabel.font = [UIFont systemFontOfSize:12];
    }
    return _pgpBalanceLabel;
}
- (NSArray<NSString*>*)prices
{
    if (!_prices) {
        _prices = @[@"30 PGP",@"120 PGP",@"240 PGP",@"1200 PGP", @"3600 PGP",SIMLocalized(@"enter_purchase_pgp_number")];
    }
    return _prices;
}
- (UITableView*)purchasePriceTableView
{
    if (!_purchasePriceTableView) {
        _purchasePriceTableView = [UITableView new];
        _purchasePriceTableView.delegate = self;
        _purchasePriceTableView.dataSource = self;
        [_purchasePriceTableView registerNib:[UINib nibWithNibName:@"DefaultPGPPurchaseItemTableViewCell" bundle:nil] forCellReuseIdentifier:@"DefaultPGPPurchaseItemTableViewCell"];
        [_purchasePriceTableView registerNib:[UINib nibWithNibName:@"CustomPGPPurchaseItemTableViewCell" bundle:nil] forCellReuseIdentifier:@"CustomPGPPurchaseItemTableViewCell"];
        _purchasePriceTableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        _purchasePriceTableView.scrollEnabled = NO;


    }
    return _purchasePriceTableView;
}
-(instancetype)initForPGP{
    self = [super init];
    if (self) {
        self.defaultHight = @600;
        [self setupView];
        
    }
    return self;
}
-(void)setupView{
    self.backgroundColor = [UIColor whiteColor];
    [self addThisSubViews];
    [self layoutThisSubViews];
}
-(void)addThisSubViews{
    [self addSubview:self.topicLabel];
    [self addSubview:self.pgpBalanceLabel];
    [self addSubview:self.purchasePriceTableView];
}
-(void)layoutThisSubViews{
    [self.topicLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self).offset(10);
        make.leading.equalTo(self).offset(25);
        make.height.equalTo(@50);
        make.trailing.greaterThanOrEqualTo(self).offset(-100);
    }];
    [self.purchasePriceTableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.topicLabel.mas_bottom).offset(15);
        make.bottom.equalTo(self);
        make.leading.equalTo(self).offset(10);
        make.trailing.equalTo(self).offset(-10);
    }];
    [self.pgpBalanceLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerY.equalTo(self.topicLabel);
        make.trailing.equalTo(self).offset(-10);
        make.top.equalTo(self).offset(10);
        make.height.equalTo(@50);

    }];
        
}
-(void)setTOPCornerRadiusAtViewDidLoad{
    [self setCornerRadius:20 corners:UIRectCornerTopLeft| UIRectCornerTopRight];
}
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
   
   
    if(indexPath.row != 5){
        DefaultPGPPurchaseItemTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"DefaultPGPPurchaseItemTableViewCell" forIndexPath:indexPath];
        cell.howMuchPGPLabel.text = self.prices[indexPath.row];
        [self resetCellIndcatorAtIndexPath:indexPath andCell:cell];
        return  cell;
    }else{
        CustomPGPPurchaseItemTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"CustomPGPPurchaseItemTableViewCell" forIndexPath:indexPath];
        [self resetCellIndcatorAtIndexPath:indexPath andCell:cell];
        cell.textFieldDidEdit =  ^(BOOL didEdit) {
            if (didEdit) {
                self.checkoutIndexPath = @5;
                for (UITableViewCell*cell in self.purchasePriceTableView.visibleCells) {
                    if([cell class] == [DefaultPGPPurchaseItemTableViewCell class]){
                        [self resetCellIndcatorAtIndexPath:[self.purchasePriceTableView indexPathForCell:cell] andCell:cell];
                    }else{
                        CustomPGPPurchaseItemTableViewCell* customCell = (CustomPGPPurchaseItemTableViewCell*)cell;
                        [self resetCellIndcatorAtIndexPath:[self.purchasePriceTableView indexPathForCell:cell] andCell:cell];

                    }
                }
            }
        };
        return  cell;
    }
//    cell.model = @{@"title":self.prices[indexPath.row],@"value":[NSString stringWithFormat:@"%lu",(unsigned long)(indexPath.section == self.checkoutIndexPath?CheckoutTypeSelect:CheckoutTypeNone)]};
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.prices.count;
}
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 40;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
//    NSInteger oldIndex = self.checkoutIndexPath;
//    if (indexPath.section == self.checkoutIndexPath) {
//        return;
//    }else{
//        self.checkoutIndexPath = indexPath.section;
//    }
    self.checkoutIndexPath = [NSNumber numberWithFloat:indexPath.row];
    [self.purchasePriceTableView reloadData];

}
-(void)resetCellIndcatorAtIndexPath:(NSIndexPath *)indexPath andCell:(UITableViewCell*)cell{
    if(!self.checkoutIndexPath){return;};

    if ([cell class] == [CustomPGPPurchaseItemTableViewCell class]) {
        CustomPGPPurchaseItemTableViewCell* theCell = (CustomPGPPurchaseItemTableViewCell*)cell;
        theCell.selectIcon.image = [UIImage imageNamed:indexPath.row == [self.checkoutIndexPath integerValue] ?@"complaints_selected":@"complaints_unselected"];
    }else if ([cell class] == [DefaultPGPPurchaseItemTableViewCell class]){
        DefaultPGPPurchaseItemTableViewCell* theCell = (DefaultPGPPurchaseItemTableViewCell*)cell;
        theCell.selectIcon.image = [UIImage imageNamed:indexPath.row == [self.checkoutIndexPath integerValue]?@"complaints_selected":@"complaints_unselected"];
    }
}
@end
