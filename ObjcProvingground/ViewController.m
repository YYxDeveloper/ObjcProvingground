//
//  ViewController.m
//  ObjcProvingground
//
//  Created by 呂子揚 on 2022/7/21.
//

#import "ViewController.h"
#import "SIMSelectedLanguageViewController.h"
#import "SIMSwitchLocationContentViewController.h"
@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIButton *btn1;
@property (weak, nonatomic) IBOutlet UIButton *btn2;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
  
    
//    [self writePlist];
    // Do any additional setup after loading the view.
}
-(void)viewDidAppear:(BOOL)animated{
   

}
- (IBAction)clickBtn1:(id)sender {
  
//    [self loadPlist];
    [self try14567View];

}
- (IBAction)clickBtn2:(id)sender {
   
}
+(NSString *)getFilePath{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *filePath = [documentsDirectory stringByAppendingPathComponent:@"pgtalkloginfo.plist"];
    NSLog(@"filePath:::%@",filePath);
    return filePath;
}
- (void)writePlist{
    NSArray *dataArray = @[@"John", @"Mary", @"Tom"];
    NSDictionary *dataDict = @{@"names": dataArray};
    BOOL success = [dataDict writeToFile:[ViewController getFilePath] atomically:YES];
    if (success) {
        NSLog(@"Data saved successfully.");
    } else {
        NSLog(@"Error saving data.");
    }


    
}
- (void) loadPlist{
    NSDictionary *loadedData = [NSDictionary dictionaryWithContentsOfFile:[ViewController getFilePath]];
    NSArray *loadedArray = [loadedData objectForKey:@"names"];
    NSLog(@"Loaded array: %@", loadedArray);
}
-(void)tryMasonry{
    UIView *view1 = [[UIView alloc] init];
    view1.backgroundColor = [UIColor greenColor];
    [self.view addSubview:view1];
    
    [view1 mas_makeConstraints:^(MASConstraintMaker *make) {
        make.size.width.equalTo([[NSNumber alloc]initWithFloat:(SIMScreenWidth/2)]);
        make.size.height.equalTo(@74);
    }];
}
-(void)try14567View{
    SIMSwitchLocationContentViewController* vc = [[SIMSwitchLocationContentViewController alloc] initWithComparingLocation:NotChange];
    vc.modalPresentationStyle = UIModalPresentationFullScreen;

//    [self.view addSubview:vc.view];
    [self presentViewController:vc animated:NO completion:nil];

}
@end
