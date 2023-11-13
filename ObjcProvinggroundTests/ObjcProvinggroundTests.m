//
//  ObjcProvinggroundTests.m
//  ObjcProvinggroundTests
//
//  Created by 呂子揚 on 2022/7/21.
//

#import <XCTest/XCTest.h>
#import "CustomPGPPurchaseItemTableViewCell.h"

@interface ObjcProvinggroundTests : XCTestCase

@end

@implementation ObjcProvinggroundTests

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

-(void)testCheckEnterPriceGreater10PGP{
    UITableView *tableView = [UITableView new];
    [tableView registerNib:[UINib nibWithNibName:@"CustomPGPPurchaseItemTableViewCell" bundle:nil] forCellReuseIdentifier:@"CustomPGPPurchaseItemTableViewCell"];
    NSIndexPath*PurchaseItemCellIndexPath = [NSIndexPath indexPathForRow:5 inSection:0];
    CustomPGPPurchaseItemTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"CustomPGPPurchaseItemTableViewCell" forIndexPath:PurchaseItemCellIndexPath];
    
    //test  cell checkEnterPriceGreater10PGP
    assert([cell checkEnterPriceGreater10PGP:@""]==NO);
    assert([cell checkEnterPriceGreater10PGP:@"0001000"]==YES);
    assert([cell checkEnterPriceGreater10PGP:@"8"]==NO);
    assert([cell checkEnterPriceGreater10PGP:@"0008"]==NO);
}
-(void)testCheckEnterPriceCountLess8Length{
    UITableView *tableView = [UITableView new];
    [tableView registerNib:[UINib nibWithNibName:@"CustomPGPPurchaseItemTableViewCell" bundle:nil] forCellReuseIdentifier:@"CustomPGPPurchaseItemTableViewCell"];
    NSIndexPath*PurchaseItemCellIndexPath = [NSIndexPath indexPathForRow:5 inSection:0];
    CustomPGPPurchaseItemTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"CustomPGPPurchaseItemTableViewCell" forIndexPath:PurchaseItemCellIndexPath];
    
    assert([cell checkEnterPriceCountLess8Length:@"1234567"] == YES);
    assert([cell checkEnterPriceCountLess8Length:@"12345678"] == YES);
    assert([cell checkEnterPriceCountLess8Length:@"123456789"] == NO);

}
@end
