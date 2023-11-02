//
//  SIMSelectedLanguageViewController.h
//  ObjcProvingground
//
//  Created by 呂子揚 on 2023/10/25.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, ExhibitionType) {
    ForLanguag,
    ForLocation,
};
@interface SIMSelectedLanguageViewController : UIViewController
@property (strong, nonatomic) UIButton* btnConfirm;
@property (strong, nonatomic) UIButton* btnBack;

-(instancetype)initWitchExhibition:(ExhibitionType)type;

@end

NS_ASSUME_NONNULL_END
