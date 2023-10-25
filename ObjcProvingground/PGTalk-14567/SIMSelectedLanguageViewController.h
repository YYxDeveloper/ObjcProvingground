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
+(SIMSelectedLanguageViewController*) createSIMSelectedLanguageViewControllerWith:(ExhibitionType)type;

@end

NS_ASSUME_NONNULL_END
