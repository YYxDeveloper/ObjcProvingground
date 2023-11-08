//
//  UIView+CustomCorner.m


#import "UIView+CustomCorner.h"

@implementation UIView (CustomCorner)
-(void)setCornerRadius:(CGFloat)radius corners:(UIRectCorner)corners{
    
    [self layoutIfNeeded];
    
    //设置视图位置和大小
    UIView *myView = self;
    CGRect bounds = self.bounds;
    //绘制圆角 要设置的圆角 使用“|”来组合
    UIBezierPath *maskPath = [UIBezierPath bezierPathWithRoundedRect:myView.bounds byRoundingCorners:corners cornerRadii:CGSizeMake(radius, radius)];
    
    CAShapeLayer *maskLayer = [[CAShapeLayer alloc] init];
    
    //设置大小
    maskLayer.frame = bounds;
    
    //设置图形样子
    maskLayer.path = maskPath.CGPath;
    
    myView.layer.mask = maskLayer;
}
-(void)setCornerRadius:(CGFloat)radius{
    [self setCornerRadius:radius corners:UIRectCornerAllCorners];
}
@end
