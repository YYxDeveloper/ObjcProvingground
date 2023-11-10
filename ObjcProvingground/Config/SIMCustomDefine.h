//
//  SIMCustomDefine.h
//  SAMIM
//
//  Created by   on 2018/9/29.
//  Copyright © 2018年  . All rights reserved.
//

#ifndef SIMCustomDefine_h
#define SIMCustomDefine_h

#define weakSelf(var)   __weak typeof(var) weakSelf = var

//屏幕的宽高
#define SIMScreenWidth                              [UIScreen mainScreen].bounds.size.width
#define SIMScreenHeight                             [UIScreen mainScreen].bounds.size.height

//SE 5 5s
#define SIMiPhoneSE (SIMScreenHeight == 568)
//6 6s 7 8
#define SIMiPhone6s (SIMScreenHeight == 667)
//6p 6sp 7p 8p
#define SIMiPhone6p (SIMScreenHeight == 736)
//X XS 11pro
#define SIMiPhoneX  (SIMScreenHeight == 812)
//12 12pro 13 13pro
#define SIMiPhoneXS  (SIMScreenHeight == 844)
//XR XS-Max 11 11proMax
#define SIMiPhoneXR (SIMScreenHeight == 896)
//12 13proMax
#define SIMiPhoneProMax (SIMScreenHeight == 926)
//14pro
#define SIMiPhone14Pro (SIMScreenHeight == 852)
//14proMax
#define SIMiPhone14ProMax (SIMScreenHeight == 932)

//竖屏状态
//iPhoneX状态栏的高度 44
#define SIMState_Height ((SIMiPhoneX || SIMiPhoneXR) ? 44.0 : 20.0)
#define SIMNoramlState_Height 20.0

//NavigationBar的高度 44
#define SIMNavigationBar_Height 44.0

#define SIMSafeAreaTopHeight ((SIMiPhoneX || SIMiPhoneXR) ? 88 : 64)
#define SafeAreaTopHeight  SIMSafeAreaTopHeight
#define kTopHeight (SIMState_Height + SIMNavigationBar_Height)

//底部非安全区域的高度 34
#define SIMBottomNOSafeArea_Height ((SIMiPhoneX || SIMiPhoneXR)? 34.0 :0.0)

#define SIMTabBarHeight ([[UIApplication sharedApplication] statusBarFrame].size.height>20?83:49)

//根据 UI效果图 获取 实际宽度
//width:UI效果图上 标注的宽度
//typeWidth:UI根据什么机型做的UI效果图，就取该机型的编程宽度
#define SIMAcquireRealityWidth(width , typeWidth) width * SIMScreenWidth / typeWidth

//根据 UI效果图 获取 实际高度
//height:UI效果图上 标注的高度
//typeHeight:UI根据什么机型做的UI效果图，就取该机型的编程高度
#define SIMAcquireRealityHeight(height , typeHeight) height * SIMScreenHeight / typeHeight

//实际编程值
#define SIMActualCodeValue(x) (x / 2)

#define SystemChatFontSetFloatValue ([NSString stringWithFormat:@"%@",[[NSUserDefaults standardUserDefaults] valueForKey:@"SystemChatFontSet"]].floatValue == 4.f ? 12.f : [NSString stringWithFormat:@"%@",[[NSUserDefaults standardUserDefaults] valueForKey:@"SystemChatFontSet"]].floatValue)

//设置聊天页系统字体大小
#define SIMSystemChatFont(x) [UIFont systemFontOfSize:x+SystemChatFontSetFloatValue]
//设置聊天页系统字体WeightMedium
#define SIMSystemChatFontWeightMedium(x) [UIFont systemFontOfSize:x+SystemChatFontSetFloatValue weight:UIFontWeightMedium]
#define SystemChatFontWeightMedium SIMSystemChatFontWeightMedium
//设置聊天页系统字体WeightRegular
#define SIMSystemChatFontWeightRegular(x) [UIFont systemFontOfSize:x+SystemChatFontSetFloatValue weight:UIFontWeightRegular]
#define SystemChatFontWeightRegular SIMSystemChatFontWeightRegular
//设置聊天页系统字体粗体
#define SIMBoldChatFont(x) [UIFont boldSystemFontOfSize:x+SystemChatFontSetFloatValue]
#define BoldChatFont SIMBoldChatFont
//设置聊天页其他字体
#define SIMOtherChatFont(fontName , x) [UIFont fontWithName:fontName size:x+SystemChatFontSetFloatValue]

//系统字体
#define SIMSystemFont(x) [UIFont systemFontOfSize:x+[NSString stringWithFormat:@"%@",[[NSUserDefaults standardUserDefaults] valueForKey:@"SystemFontSet"]].floatValue]
#define SystemFont SIMSystemFont
//系统字体WeightMedium
#define SIMSystemFontWeightMedium(x) [UIFont systemFontOfSize:x+[NSString stringWithFormat:@"%@",[[NSUserDefaults standardUserDefaults] valueForKey:@"SystemFontSet"]].floatValue weight:UIFontWeightMedium]
#define SystemFontWeightMedium SIMSystemFontWeightMedium
//系统字体WeightRegular
#define SIMSystemFontWeightRegular(x) [UIFont systemFontOfSize:x+[NSString stringWithFormat:@"%@",[[NSUserDefaults standardUserDefaults] valueForKey:@"SystemFontSet"]].floatValue weight:UIFontWeightRegular]
#define SystemFontWeightRegular SIMSystemFontWeightRegular
//系统字体粗体
#define SIMBoldFont(x) [UIFont boldSystemFontOfSize:x+[NSString stringWithFormat:@"%@",[[NSUserDefaults standardUserDefaults] valueForKey:@"SystemFontSet"]].floatValue]
#define BoldFont SIMBoldFont
//其他字体
#define SIMOtherFont(fontName , x) [UIFont fontWithName:fontName size:x+[NSString stringWithFormat:@"%@",[[NSUserDefaults standardUserDefaults] valueForKey:@"SystemFontSet"]].floatValue]
//字体比例
#define SIMFontScale (60.0 / 54.0)

//沙盒目录下Documents文件的路径
#define SIMDocumentsPath [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"]

//在block中需要弱引用，防止内存泄露
#define SIMWeakSelf typeof(self) __weak weakSelf = self;

#define SIMStrongSelf __strong typeof(weakSelf) strongSelf = weakSelf;

//windows对象
#define SIMKeyWindow [UIApplication sharedApplication].keyWindow

#define SIM_APP_DELEGATE ((AppDelegate *)[UIApplication sharedApplication].delegate)

//类的初始化
#define SIMInit(Class) [[Class alloc] init]

//带xib的控制器的初始化
#define SIMInitControllerWithXib(x) [[NSClassFromString(x) alloc] initWithNibName:x bundle:nil]

//故事版（storyBoard）控制器初始化
#define SIMInitControllerWithStoryBoard(storyBoardName , className) [[UIStoryboard storyboardWithName:storyBoardName bundle:nil] instantiateViewControllerWithIdentifier:className]

//读取单nib文件
#define SIMLoadNibName(name) [[NSBundle mainBundle] loadNibNamed:name owner:self options:nil][0]

//当前版本
#define SIMCurrentVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
//build版本
#define SIMBuildVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]

//系统版本
#define SIMSys_Version [[UIDevice currentDevice].systemVersion doubleValue]

//字符串安全取值
#define SIMSafeStr(a) ([(a) isKindOfClass:[NSString class]] && [(a) length] > 0) ? [(a) description] : @""

//十六进制颜色值转换
#define SIMColorFromRGBA(rgbValue , a) [UIColor colorWithRed:((CGFloat)((rgbValue & 0xFF0000) >> 16)) / 255.0 green:((CGFloat)((rgbValue & 0xFF00) >> 8)) / 255.0 blue:((CGFloat)(rgbValue & 0xFF)) / 255.0 alpha:a]
#define SIMColorFromRGB(rgbValue) SIMColorFromRGBA(rgbValue , 1.0)
#define UIColorFromRGBA SIMColorFromRGB
#define RGB(r, g, b)                    [UIColor colorWithRed:r / 255.0f green:g / 255.0f blue:b / 255.0f alpha:1.0f]
#define RGBA(r, g, b,a)                    [UIColor colorWithRed:r / 255.0f green:g / 255.0f blue:b / 255.0f alpha:a]

#define SIMUIColorBaseVC  [UIColor colorWithRed:245/255. green:247/255. blue:247/255. alpha:1]
#define SIMColorBlueNavigationBar [UIColor colorWithRed:17/255. green:183/255. blue:243/255. alpha:1]
#define SIMColorBlackNavigationBar [UIColor colorWithRed:51/255. green:51/255. blue:51/255. alpha:1]
#define SIMColorRedNavigationBar [UIColor colorWithRed:233/255. green:78/255. blue:70/255. alpha:1]
#define SIMColorGreenNavigationBar [UIColor colorWithRed:113/255. green:205/255. blue:111/255. alpha:1]

#define SIMColorThemeNavigationBar [NSKeyedUnarchiver unarchiveObjectWithData:[[NSUserDefaults standardUserDefaults] valueForKey:@"UIColorThemeNavigationBar"]]

#define SIMColorGrayLine [UIColor colorWithRed:240/255. green:240/255. blue:240/255. alpha:1]

#define SIMColorFriendGray [UIColor colorWithRed:240/255. green:240/255. blue:240/255. alpha:1]

//加载cell
#define SIMLoadCell(cellClassStr) [[[NSBundle mainBundle] loadNibNamed:cellClassStr owner:self options:nil] lastObject]

//手机跳转至AppStore上
//appName: 将app名每个字的拼音全称用"-"链接，拼接成字符串
//appID: 将iTunes Connect 生成的appID，转成字符串
#define SIMAppStore(appName , appID) [NSString stringWithFormat:@"https://itunes.apple.com/cn/app/%@/id%@?mt=8" , appName , appID]

//网络请求超时
#define SIMTimeoutInterval 30
//聊天室录制时间限制
#define SIMVideoMaximumDurationForChat 60
#define SIMVideoMaximumDurationForShare 60
//朋友圈视频压缩
#define SIMShareVideoPresetName AVAssetExportPresetHighestQuality
//自定制导航条按钮
//图片
#define SIMCreateButtonOnNavigationBarWithImage(imageNameStr , aTarget , aAction) [[UIBarButtonItem alloc] initWithImage:[[UIImage imageNamed:imageNameStr] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal] style:UIBarButtonItemStylePlain target:aTarget action:aAction]

#define SIMCreateButtonOnNavigationBarWithImage(imageNameStr , aTarget , aAction) [[UIBarButtonItem alloc] initWithImage:[[UIImage imageNamed:imageNameStr] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal] style:UIBarButtonItemStylePlain target:aTarget action:aAction]

//文字
#define SIMCreateButtonOnNavigationBarWithTitle(titleStr , aTarget , aAction) [[UIBarButtonItem alloc] initWithTitle:titleStr style:UIBarButtonItemStylePlain target:aTarget action:aAction]

//图片占位符
#define SIMPlaceholderImage [UIImage imageNamed:@"Icon"]

//群组图片占位符
#define SIMPlaceholderGroupImage [UIImage imageNamed:@"group_image_n"]
//其他图片占位符
#define SIMPlaceholderOtherImage [UIImage imageNamed:@"other_icon_default"]

//加载图片 file
#define SIMLoadImageFile(file) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:@"png"]]
//加载图片 图片name
#define SIMLoadImageName(Name)   [UIImage imageNamed:Name]

//异步图片url
#define SIMImageUrl(imageName) [NSURL URLWithString:[DomainName stringByAppendingString:imageName]]
//图片url
#define SIMSDImageUrl(imageName) [NSURL URLWithString:imageName]


//根据当前语言版本字段对应的字段
#define SIMLocalized(key)  [[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%@",[[NSUserDefaults standardUserDefaults] objectForKey:@"appLanguage"]] ofType:@"lproj"]] localizedStringForKey:(key) value:nil table:@"SIMLocalizable"]

//默认uid 加密方式
#define SIMUidBase64(userId) [NSString stringWithFormat:@"9872a39e423e07f3578780085fc9028f%@",userId]

//默认sessionId 拼的字符串
#define SIMSESSIONID_MIDDLE @"00000"
//文件助手默认id
#define SIMFileAssistantID  @"21499"
//群聊机器人默认id
#define SIMGroupRobotID     @"21500"

//群显示群昵称
#define SIMUserDefaultsGroupShowMemberNickName @"SIMUserDefaultsGroupShowMemberNickName"
//聊天背景
#define SIMUserDefaultsUserChatBackground           @"SIMUserDefaultsUserChatBackground"

// 播放視頻tag值
#define kPlayerViewTag 9999

/*
 *第一次启动标志Key
 */
#define SIMIsNoFirstRun @"kIsNoFirstRuns"

#define SIMAPPNAME SIMLocalized(@"PGTalk")

#define SIMRootViewController [[[UIApplication sharedApplication] keyWindow] rootViewController]

#define SIMNULLString(str) [[NSString nullString:str] isEqualToString:@"0"]
//#define SIMNULLString(str) [NSString isBlankWithStr:str]

//开发阶段 解决打印不全的问题 发布提交后 屏蔽
#ifdef DEBUG
#define NSLog(formatter,...) NSLog(formatter,## __VA_ARGS__)
//#define NSLog(format,...) printf("NSLog [File:%s]\n [Function:%s]\n [Line:%d]\n%s\n",__FILE__,__FUNCTION__,__LINE__,[[NSString stringWithFormat:(format), ##__VA_ARGS__] UTF8String])

//# define NSLog(fmt, ...) printf((@"\n[File:%s]\n" "[Function:%s]\n" "[Line:%d] \n" fmt), __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define NSLog(...) nil
#endif

#define NIMKit_Dispatch_Sync_Main(block)\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_sync(dispatch_get_main_queue(), block);\
}

#define NIMKit_Dispatch_Async_Main(block)\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_async(dispatch_get_main_queue(), block);\
}

#define NIMKit_SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)


#define IMG(img)        [UIImage imageNamed:(img)]

#define ListEmpty(imageName,title) \
- (CGFloat)verticalOffsetForEmptyDataSet:(UIScrollView *)scrollView {return -80;}\
- (UIImage *)imageForEmptyDataSet:(UIScrollView *)scrollView{return IMG((imageName));}\
- (BOOL)emptyDataSetShouldAllowScroll:(UIScrollView *)scrollView{return YES;}\
- (NSAttributedString *)descriptionForEmptyDataSet:(UIScrollView *)scrollView{NSString *text = (title);NSDictionary *attributes = @{NSFontAttributeName: [UIFont systemFontOfSize:14.0f],NSForegroundColorAttributeName: [UIColor colorFromHexCode:@"#999999"]};return [[NSAttributedString alloc] initWithString:text attributes:attributes];}

#define ListLayoutEmpty(centerTopLayoutConstraint,imageName,title) \
- (CGFloat)verticalOffsetForEmptyDataSet:(UIScrollView *)scrollView {return centerTopLayoutConstraint;}\
- (UIImage *)imageForEmptyDataSet:(UIScrollView *)scrollView{return IMG((imageName));}\
- (BOOL)emptyDataSetShouldAllowScroll:(UIScrollView *)scrollView{return YES;}\
- (NSAttributedString *)descriptionForEmptyDataSet:(UIScrollView *)scrollView{NSString *text = (title);NSDictionary *attributes = @{NSFontAttributeName: [UIFont systemFontOfSize:14.0f],NSForegroundColorAttributeName: [UIColor colorFromHexCode:@"#999999"]};return [[NSAttributedString alloc] initWithString:text attributes:attributes];}

#define width(a) a.frame.size.width

#define height(a) a.frame.size.height
//是否iPhoneX YES:iPhoneX屏幕 NO:传统屏幕
#define kIs_iPhoneX ([UIScreen mainScreen].bounds.size.height == 812.0f ||[UIScreen mainScreen].bounds.size.height == 896.0f )
#define kStatusBarAndNavigationBarHeight (kIs_iPhoneX ? 88.f : 64.f)

#define pt(a) (NSInteger)(([UIScreen mainScreen].bounds.size.width / 375.0) * a)

#define bottom(a) (a.frame.origin.y + a.frame.size.height)

#define fontRegular(a) [UIFont fontWithName:@"PingFangSC-Regular" size:a]


//沙盒目录下Documents文件的路径
#define SIMDocumentsPathDefine [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"]

#define kPGTalkOfficialAnnouncementNotices @"21501"//pg官方
#define kSystemAnnouncementNotices @"21502"//系統公告
#define kMerchantsAnnouncementNotices @"21503"//商家公告
#define kPGNEWAnnouncementNotices @"21504"//新聞公告
#define kPGTourismAnnouncementNotices @"21505"//pg旅遊
#define kPGTVAnnouncementNotices @"21506"//PGTV
#define kPGTeaAnnouncementNotices @"21508"//PGPGTea 鴿子茶飲
#define kPGStoreAnnouncementNotices @"21509"//鴿子商城
#define kPGShoppingAnnouncementNotices @"21510"//鴿子購物

#define kPGLiveTipsAnnouncementNotices @"300"//開播提醒

#define kPGCurrentTimeInterval @"1640748503566"//時間戳用於處理文件名重複


#endif /* SIMCustomDefine_h */
