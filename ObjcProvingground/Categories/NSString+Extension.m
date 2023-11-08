//
//  NSString+Extension.m
//  WenMingShuo
//
//  Created by Six on 16/3/8.
//  Copyright © 2016年 Six. All rights reserved.
//

#import "NSString+Extension.h"
#import <CommonCrypto/CommonDigest.h>
//#import "SIMAccountModel.h"

@implementation NSString (Extension)

/**
 *  判断字符串是否为空
 *
 *  @param str 字符串
 *
 *  @return bool值
 */
+ (BOOL)isBlankWithStr:(NSString *)str
{
    if (str == nil || str == NULL)
    {
        return YES;
    }
    if ([str isKindOfClass:[NSNull class]])
    {
        return YES;
    }
    
    if (![str isKindOfClass:[NSString class]]) {
        return YES;
    }

    if ([[str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] length] == 0)
    {
        return YES;
    }
    return NO;
}

+ (NSString *)checkString:(NSString *)str {
    NSString *chString = @"";
    if ([str isKindOfClass:[NSString class]]) {
        NSCharacterSet *set = [NSCharacterSet whitespaceAndNewlineCharacterSet];
        chString = [str stringByTrimmingCharactersInSet:set];
    }
    else if ([str isKindOfClass:[NSNumber class]]) {
        NSNumber *number = (NSNumber *)str;
        chString = [number description];
    }
    else {
        chString = @"";
    }
    chString = [NSString stringWithFormat:@"%@",chString];
    return chString;
}

//汉字转化为拼音取首字母
+ (NSString *)firstCharactor:(NSString *)aString
{
    NSString *strFormat = [self checkString:aString];
    //转成了可变字符串
    NSMutableString *str = [NSMutableString stringWithString:strFormat];
    //先转换为带声调的拼音
    CFStringTransform((CFMutableStringRef)str, NULL, kCFStringTransformMandarinLatin, NO);
    //再转换为不带声调的拼音
    CFStringTransform((CFMutableStringRef)str, NULL, kCFStringTransformStripDiacritics, NO);
    //转化为大写拼音
    NSString *pinYin = [str capitalizedString];
    //获取并返回首字母
    return [pinYin substringToIndex:1];
}
//汉字转化为拼音
+(NSString *)PinYinToCharactor:(NSString *)astring
{
    NSString *strFormat = [self checkString:astring];
    //转成了可变字符串
    NSMutableString *str = [NSMutableString stringWithString:strFormat];
    //先转换为带声调的拼音
    CFStringTransform((CFMutableStringRef)str,NULL, kCFStringTransformMandarinLatin,NO);
    //再转换为不带声调的拼音
    CFStringTransform((CFMutableStringRef)str,NULL, kCFStringTransformStripDiacritics,NO);
    //转化为大写拼音
    NSString *pinYin = [str capitalizedString];
    return pinYin;
}
/// 汉字转化为拼音
/// @param chinese 字符串
+ (NSString *)pinyinChina:(NSString *)chinese {
    // 字符串為空 不做轉換
    if ([NSString isBlankWithStr:chinese]) return @" ";
    
    //将NSString装换成NSMutableString
    NSMutableString *pinyin = [[NSMutableString alloc] initWithString:chinese];
 
    //将汉字转换为拼音(带音标)
    CFStringTransform((__bridge CFMutableStringRef)pinyin, NULL, kCFStringTransformMandarinLatin, NO);
    //NSLog(@"%@", pinyin);
 
    //去掉拼音的音标
    CFStringTransform((__bridge CFMutableStringRef)pinyin, NULL, kCFStringTransformStripCombiningMarks, NO);
    
    NSString *str = [pinyin lowercaseString];
    pinyin = nil;
    return str;
}
//生成UUID
+ (NSString *)createUUID
{
    CFUUIDRef uuid_ref = CFUUIDCreate(NULL);
    CFStringRef uuid_string_ref = CFUUIDCreateString(NULL, uuid_ref);
    CFRelease(uuid_ref);
    NSString * uuid = (__bridge NSString *)uuid_string_ref;
    CFRelease(uuid_string_ref);
    return uuid;
}

//获取用户id
+ (NSString *)acquireUserId
{
    //获取当前用户id
//    NSString * userId = [SIMAccountModel sharedAccountModel].userId;
//    if (userId.length) {
//        return userId;
//    }
//    NSDictionary *userInfoDict = [[NSUserDefaults standardUserDefaults] objectForKey:@"userInfo"];
//    userId = userInfoDict[@"id"];
//    userId = [self checkString:userId];
//    return userId;
    return @"";
}

+ (NSString *)myUserId
{
    //获取当前用户id
    NSString *userId = [self acquireUserId];
    
    return userId;
}

//根据 图片名  返回 想要的url
+ (NSURL *)returnImageUrlWithImageName:(NSString *)imageName
{
    if ([NSString isBlankWithStr:imageName]) {
        return [NSURL new];
    }
    NSString * imageNameStr = @"";
    BOOL isExist;
    if ([imageName hasPrefix:@"http:"] || [imageName hasPrefix:@"https:"]) {
        isExist = YES;
    }
    else
    {
        isExist = NO;
    }
//    BOOL isExist = [imageName hasPrefix:@"http:"];
    if (isExist)
    {
        imageNameStr = imageName;
    }
    else
    {
        @try
        {
             imageNameStr = [@"" stringByAppendingString:@""];
        }
        @catch(NSException *exception) {

        }
    }
    return [NSURL URLWithString:imageNameStr];
}
+ (NSString *)returnImageStrWithImageName:(NSString *)imageName {
    NSString * imageNameStr = @"";
    BOOL isExist = [imageName hasPrefix:@"http:"] || [imageName hasPrefix:@"https:"];
    if (isExist)
    {
        imageNameStr = imageName;
    }
    else
    {
        imageNameStr = [@"" stringByAppendingString:@""];
    }
    return imageNameStr;
}
/// 获取当前版本号
+ (NSString *)acquireCurrentVersion {
    
    NSDictionary *infoDict = [[NSBundle mainBundle] infoDictionary];
    NSString *currentVersion = [infoDict objectForKey:@"CFBundleShortVersionString"];
    return currentVersion;
}

+(NSString *)interceptGroupSessionId:(NSString *)session
{
    if(session.length >= 7)
    {
        return [session substringFromIndex:6];
    }
    else
    {
        return session;
    }
}

+(NSString *)nullString:(NSString *)string
{
    string = [self checkString:string];
    
    if (string.length == 0 || [string isEqualToString:@"(null)"] || string == nil ) {
        return @"0";
    }
    if ([[string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] length] == 0)
    {
        return @"0";
    }
    else
    {
        return string;
    }
}

- (NSString *)trim {
    NSCharacterSet *set = [NSCharacterSet whitespaceAndNewlineCharacterSet];
    NSString *str = [self stringByTrimmingCharactersInSet:set];
    return str;
}

+(BOOL)isHaveIllegalChar:(NSString *)string
{
    NSInteger len = string.length;
    for(int i=0;i<len;i++)
    {
        unichar a=[string characterAtIndex:i];
        if(!((isalpha(a))
             ||(isalnum(a))
             ||((a=='-'))
             ||((a=='.'))
             ||((a >= 0x4e00 && a <= 0x9fa6))
             ))
            return YES;
    }
    return NO;
}

//验证手机
+ (BOOL)verificationIsValidWithPhoneNumberStr:(NSString *)phoneNumber_str
{
    NSString * regularExpression = @"^(((13[0-9]{1})|(15[0-9]{1})|(17[0-9]{1})|(18[0-9]{1})|(19[0-9]{1})|(14[0-9]{1}))+\\d{8})$";
    NSPredicate * predicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@" , regularExpression];
    return [predicate evaluateWithObject:phoneNumber_str];
}

//验证邮箱
+ (BOOL)verificationIsValidWithEmailStr:(NSString *)email_str
{
    NSString * regularExpression = @"^([a-zA-Z0-9]+[_|\\_|\\.]?)*[a-zA-Z0-9]+@([a-zA-Z0-9]+[_|\\_|\\.]?)*[a-zA-Z0-9]+\\.[a-zA-Z]{2,3}$";
    NSPredicate * predicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@" , regularExpression];
    return [predicate evaluateWithObject:email_str];
}


+ (BOOL)checkPassword:(NSString *)passwrod {
    BOOL flag = NO;
    NSString * regex = @"^(?=.*[0-9])(?=.*[a-zA-Z])[0-9A-Za-z!@#$%^*()_+\\-=\\[\\]{}|;':\",./?]{6,24}$";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    flag = [pred evaluateWithObject:passwrod];
    return flag;
    
//    NSRegularExpression *regularExpression;
//    regularExpression = [NSRegularExpression regularExpressionWithPattern:@"(^[a-zA-Z0-9]{6,24}$)"
//                                                                  options:NSRegularExpressionCaseInsensitive
//                                                                    error:nil];
//
//    NSPredicate * predicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@" , regularExpression];
//    flag = [predicate evaluateWithObject:passwrod];
//    return flag;
}

+ (BOOL)judgeIdentityStringValid:(NSString *)identityString {
    
    if (identityString.length != 18) return NO;
    // 正则表达式判断基本 身份证号是否满足格式
    NSString *regex2 = @"^(^[1-9]\\d{7}((0\\d)|(1[0-2]))(([0|1|2]\\d)|3[0-1])\\d{3}$)|(^[1-9]\\d{5}[1-9]\\d{3}((0\\d)|(1[0-2]))(([0|1|2]\\d)|3[0-1])((\\d{4})|\\d{3}[Xx])$)$";
    NSPredicate *identityStringPredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",regex2];
    //如果通过该验证，说明身份证格式正确，但准确性还需计算
    if(![identityStringPredicate evaluateWithObject:identityString]) return NO;
    
    //** 开始进行校验 *//
    
    //将前17位加权因子保存在数组里
    NSArray *idCardWiArray = @[@"7", @"9", @"10", @"5", @"8", @"4", @"2", @"1", @"6", @"3", @"7", @"9", @"10", @"5", @"8", @"4", @"2"];
    
    //这是除以11后，可能产生的11位余数、验证码，也保存成数组
    NSArray *idCardYArray = @[@"1", @"0", @"10", @"9", @"8", @"7", @"6", @"5", @"4", @"3", @"2"];
    
    //用来保存前17位各自乖以加权因子后的总和
    NSInteger idCardWiSum = 0;
    for(int i = 0;i < 17;i++) {
        NSInteger subStrIndex = [[identityString substringWithRange:NSMakeRange(i, 1)] integerValue];
        NSInteger idCardWiIndex = [[idCardWiArray objectAtIndex:i] integerValue];
        idCardWiSum+= subStrIndex * idCardWiIndex;
    }
    
    //计算出校验码所在数组的位置
    NSInteger idCardMod=idCardWiSum%11;
    //得到最后一位身份证号码
    NSString *idCardLast= [identityString substringWithRange:NSMakeRange(17, 1)];
    //如果等于2，则说明校验码是10，身份证号码最后一位应该是X
    if(idCardMod==2) {
        if ([idCardLast caseInsensitiveCompare:@"x"] != NSOrderedSame) {
            return NO;
        }
        
    }
    else{
        //用计算出的验证码与最后一位身份证号码匹配，如果一致，说明通过，否则是无效的身份证号码
        if(![idCardLast isEqualToString: [idCardYArray objectAtIndex:idCardMod]]) {
            return NO;
        }
    }
    return YES;
}
/// 验证数字
+ (BOOL)verificationIsValidWithNumber:(NSString *)str {

    NSRegularExpression *numberRegular = [NSRegularExpression regularExpressionWithPattern:@"[0-9]" options:NSRegularExpressionCaseInsensitive error:nil];

    NSInteger count = [numberRegular numberOfMatchesInString:str options:NSMatchingReportProgress range:NSMakeRange(0, str.length)];

    //count是str中包含[0-9]数字的个数，只要count>0，说明str数字

    if (count > 0) {
        return YES;
    }
    return NO;
}

- (CGSize)stringSizeWithFont:(UIFont *)font{
    return [self sizeWithAttributes:@{NSFontAttributeName:font}];
}

- (NSString *)MD5String {
    const char *cstr = [self UTF8String];
    unsigned char result[16];
    CC_MD5(cstr, (CC_LONG)strlen(cstr), result);
    return [NSString stringWithFormat:
            @"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
            result[0], result[1], result[2], result[3],
            result[4], result[5], result[6], result[7],
            result[8], result[9], result[10], result[11],
            result[12], result[13], result[14], result[15]
            ];
}


- (NSUInteger)getBytesLength
{
    NSStringEncoding enc = CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingGB_18030_2000);
    return [self lengthOfBytesUsingEncoding:enc];
}


- (NSString *)stringByDeletingPictureResolution{
    NSString *doubleResolution  = @"@2x";
    NSString *tribleResolution = @"@3x";
    NSString *fileName = self.stringByDeletingPathExtension;
    NSString *res = [self copy];
    if ([fileName hasSuffix:doubleResolution] || [fileName hasSuffix:tribleResolution]) {
        res = [fileName substringToIndex:fileName.length - 3];
        if (self.pathExtension.length) {
            res = [res stringByAppendingPathExtension:self.pathExtension];
        }
    }
    return res;
}

- (NSString *)iPhoneStandardFormat {
    NSString * originStr = [NSString stringWithFormat:@"%@",self];
    NSMutableString * strippedString = [NSMutableString stringWithCapacity:originStr.length];
    NSScanner * scanner = [NSScanner scannerWithString:originStr];
    NSCharacterSet * numbers = [NSCharacterSet characterSetWithCharactersInString:@"0123456789"];
    while ([scanner isAtEnd] == NO) {
        NSString * buffer;
        if ([scanner scanCharactersFromSet:numbers intoString:&buffer]) {
            [strippedString appendString:buffer];
        } else {
            [scanner setScanLocation:([scanner scanLocation] + 1)];
        }
    }
    return strippedString;
}


- (NSString *)tokenByPassword
{
    //接入应用开发需要根据自己的实际情况来获取 account和token
    //    return [[NIMSDK sharedSDK] isUsingDemoAppKey] ? [self MD5String] : self;
    return nil;
}

- (id)jsonObject
{
    NSData *data = [self dataUsingEncoding:NSUTF8StringEncoding];
    if (data) {
        id object = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
        return object;
    }
    return nil;
}

- (CGSize)sizeWithFont:(UIFont *)font maxWidth:(CGFloat)width maxNumberLines:(int)num {
    CGSize size = CGSizeZero;
    if (num > 0) {
        CGFloat tmpHeight = ceilf(font.lineHeight * num);
//        size = [self sizeWithFont:font constrainedToSize:CGSizeMake(width, tmpHeight) lineBreakMode:NSLineBreakByTruncatingTail];
        
        NSDictionary *attrs = @{NSFontAttributeName :font};
        CGSize maxSize = CGSizeMake(width, tmpHeight);

        NSStringDrawingOptions options = NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading;

        // 计算文字占据的宽高
        size = [self boundingRectWithSize:maxSize
                                  options:options
                               attributes:attrs context:nil].size;
        
    } else if (num == 0) {
        size = [self sizeWithFont:font maxWidth:width maxNumberLines:-10];
    } else if (num < 0) {
        num = num*-1;
        int i = 1;
        CGFloat h1, h2;
        do {
            size = [self sizeWithFont:font maxWidth:width maxNumberLines:num*i];
            h1 = size.height;
            h2 = ceilf(font.lineHeight*num*i++);
        } while (h1 >= h2);
    }
    size.width = ceilf(size.width);
    size.height = ceilf(size.height);
    return size;
}

+ (NSString *)languageStr{
    NSArray  * language    = [NSLocale preferredLanguages];
    NSString * languageStr = [language objectAtIndex:0];
    NSString * lang        = @"";
    if ([languageStr hasPrefix:@"zh-Hans"])
    {
        lang = @"zh-cn";
    }else if ([languageStr hasPrefix:@"en"]){
        lang = @"en-us";
    }else if ([languageStr hasPrefix:@"zh-Hant"]||[languageStr hasPrefix:@"yue-Hant-HK"]||[languageStr hasPrefix:@"yue-Hans-HK"]){
        lang = @"zh-tw";
    }else if ([languageStr hasPrefix:@"ja"]){
        lang = @"ja-jp";
    }else if ([languageStr hasPrefix:@"ko"]){
        lang = @"ko-kr";
    }else {
        lang = @"en-us";
    }
    return lang;
}

+ (BOOL)JudgeTheillegalCharacter:(NSString *)content{
    
    NSString *str =@"^[A-Za-z0-9\\u4e00-\u9fa5]+$";
    
    NSPredicate* emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", str];
    
    if (![emailTest evaluateWithObject:content]) {
        return YES;
    }
    return NO;
    
}

+(BOOL)moneyTextField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string
{
    // 判断是否有小数点
    BOOL isHaveDian = NO;
    if ([textField.text containsString:@"."]) {
        isHaveDian = YES;
    }else{
        isHaveDian = NO;
    }

    if (string.length > 0) {
        //当前输入的字符
        unichar single = [string characterAtIndex:0];
        
        // 不能输入.0-9以外的字符
        if (!((single >= '0' && single <= '9') || single == '.'))
        {
            return NO;
        }
        
        // 只能有一个小数点
        if (isHaveDian && single == '.') {
            return NO;
        }
        
        // 如果第一位是.则前面加上0.
        if ((textField.text.length == 0) && (single == '.')) {
            textField.text = @"0";
        }
        
        // 如果第一位是0则后面必须输入点，否则不能输入。
        if ([textField.text hasPrefix:@"0"]) {
            if (textField.text.length > 1) {
                NSString *secondStr = [textField.text substringWithRange:NSMakeRange(1, 1)];
                if (![secondStr isEqualToString:@"."]) {
                    return NO;
                }
            }else{
                if (![string isEqualToString:@"."]) {
                    return NO;
                }
            }
        }
        
        // 小数点后最多能输入两位
        if (isHaveDian) {
            NSRange ran = [textField.text rangeOfString:@"."];
            // 由于range.location是NSUInteger类型的，所以这里不能通过(range.location - ran.location)>2来判断
            if (range.location > ran.location) {
                if ([textField.text pathExtension].length > 1) {
                    return NO;
                }
            }
        }
        
    }
    
    NSString *text = @"";
    if ([NSString isBlankWithStr:string]) {
        text = [textField.text substringToIndex:range.location];
    }
    else {
        text = [textField.text stringByAppendingString:string];
    }
    
    if ([text length] > 7) {
        return NO;
    }
    
    return YES;
}

+(BOOL)countTextField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string
{
    if (string.length > 0) {
        //当前输入的字符
        unichar single = [string characterAtIndex:0];

        if (!(single >= '0' && single <= '9'))
        {
            return NO;
        }
    }
    return YES;
}
/// 更换oss
- (NSString *)ossUrlStr
{
#if defined(SimProductEnvironment)
    if ([SIMAccountModel sharedAccountModel].isChina) {
        NSString *urlStr = [self stringByReplacingOccurrencesOfString:@"http://cdn.pgtalk.com" withString:@"http://fubishi.oss-ap-southeast-1.aliyuncs.com"];
        return urlStr;
    }
#endif
    return self;
}


+ (NSMutableArray *)calculateSubStringCount:(NSString *)content str:(NSString *)tab {
    
    NSMutableArray *locationArr = [NSMutableArray new];
    
    if ([NSString isBlankWithStr:content]) {
        return locationArr;
    }
    
    if ([NSString isBlankWithStr:tab]) {
        return locationArr;
    }
    
    NSInteger location = 0;
    NSRange range = [content rangeOfString:tab];
    if (range.location == NSNotFound){
        return locationArr;
    }
    //声明一个临时字符串,记录截取之后的字符串
    NSString *subStr = content;
    while (range.location != NSNotFound) {
        location += range.location;
        //记录位置
        NSNumber *number = [NSNumber numberWithUnsignedInteger:location];
        [locationArr addObject:number];

        //每次记录之后,把找到的字串截取掉
        subStr = [subStr substringFromIndex:range.location + range.length];
        if ([NSString isBlankWithStr:subStr]) {
            break;
        }
        location += range.length;
        range = [subStr rangeOfString:tab];
    }
    return locationArr;
}

@end
