//
//  SIMBaseCheckoutTableViewCell.h
//  SAMIM
//
//  Created by 121 on 2018/10/15.
//  Copyright © 2018年  . All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    CheckoutTypeDefault,
    CheckoutTypeNone,
    CheckoutTypeSelect,
} CheckoutType;

@interface SIMBaseCheckoutTableViewCell : UITableViewCell
@property (nonatomic,strong) NSDictionary * model;
@property (nonatomic,strong) NSString * icon;
@end

NS_ASSUME_NONNULL_END
