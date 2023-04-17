//
//  ViewController.m
//  ObjcProvingground
//
//  Created by 呂子揚 on 2022/7/21.
//

#import "ViewController.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIButton *btn1;
@property (weak, nonatomic) IBOutlet UIButton *btn2;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.btn1 setTitle:@"1" forState:UIControlStateNormal];
    [self.btn2 setTitle:@"2" forState:UIControlStateNormal];
    // Do any additional setup after loading the view.
}
- (IBAction)clickBtn1:(id)sender {
    [self.btn1 setTitleColor:[UIColor redColor] forState:UIControlStateNormal];
    [self.btn2 setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
//    [self.btn1 setTitle:@"3" forState:UIControlStateNormal];
//    [self.btn2 setTitle:@"4" forState:UIControlStateNormal];


}
- (IBAction)clickBtn2:(id)sender {
    [self.btn1 setTitleColor:[UIColor orangeColor] forState:UIControlStateNormal];
    [self.btn2 setTitleColor:[UIColor greenColor] forState:UIControlStateNormal];
//    [self.btn1 setTitle:@"1" forState:UIControlStateNormal];
//    [self.btn2 setTitle:@"2" forState:UIControlStateNormal];
}


@end
