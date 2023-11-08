//
//  UIView+CustomCorner.h


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (CustomCorner)

-(void)setCornerRadius:(CGFloat)radius;

-(void)setCornerRadius:(CGFloat)radius corners:(UIRectCorner)corners;

@end

NS_ASSUME_NONNULL_END
