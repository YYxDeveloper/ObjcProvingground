//
//  NSDate+Extention.m
//  LLLM
//
//  Created by sam on 16/8/4.
//  Copyright © 2016年 clove. All rights reserved.
//


#import "NSDate+Extention.h"
#define EmailBindCountDownTime 60
#define RegistCountDownTime 60
#define RealNameCountDownTime 60
#define FindLostPwdByPhoneCountDownTime 60
#define FindLostPwdByEmailCountDownTime 60
#define SetPayPwdCountDownTime 60
#define ResetLoginPwdByPhoneCountDownTime 60
#define ResetLoginPwdByEmailCountDownTime 60
#define RelieveEmailPwdByRelieveEmailCountDownTime 60

@implementation NSDate (Extention)

+ (NSString *)nowFromDateExchange:(NSString *)oldTime {//oldTime 为服务器返回的发布消息时间距离1970年多少秒
    
    //    计算现在距1970年多少秒
    NSDate *datenow = [NSDate date];
    //当前时间转时间戳
    NSString *currentTime = [NSString stringWithFormat:@"%ld", (long)[datenow timeIntervalSince1970]];
    //    计算现在的时间和发布消息的时间时间差
    double timeDiffence = [currentTime longLongValue] - [oldTime longLongValue];
    
    //    根据秒数的时间差的不同，返回不同的日期格式
    if (timeDiffence <= 60) {
//        return [NSString stringWithFormat:@"%.0f 秒前",timeDiffence];
        return SIMLocalized(@"刚刚");
    }else if (timeDiffence <= 3600){
        return [NSString stringWithFormat:@"%.0f %@",timeDiffence / 60,SIMLocalized(@"分钟前")];
    }else if (timeDiffence <= 86400){
        return [NSString stringWithFormat:@"%.0f %@",timeDiffence / 3600,SIMLocalized(@"小时前")];
    }else if (timeDiffence <= 604800){
        return [NSString stringWithFormat:@"%.0f %@",timeDiffence / 3600 /24,SIMLocalized(@"天前")];
    }else{
        //    返回具体日期
        NSDate *oldTimeDate = [NSDate dateWithTimeIntervalSince1970:[oldTime longLongValue]];
        
        NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
        [formatter setDateFormat:@"MM-dd"];
        return [formatter stringFromDate:oldTimeDate];
    }
}

+ (NSString *)dateExchange:(NSInteger)time
{
    if (time < 60) {
        return [NSString stringWithFormat:@"%ld %@",(long)time,SIMLocalized(@"秒")];
    }
    else if (time < 3600)
    {
        NSInteger minute = time/60;
        NSInteger second = time - minute * 60;
        return [NSString stringWithFormat:@"%ld %@ %ld %@",(long)minute,SIMLocalized(@"分"),(long)second,SIMLocalized(@"秒")];
    }
    else
    {
        NSInteger hour = time/3600;
        NSInteger minute = (time - hour*3600)/60;
        NSInteger second = (time - hour*3600) - minute*60;
        return [NSString stringWithFormat:@"%ld %@ %ld %@ %ld %@",(long)hour,SIMLocalized(@"时"),(long)minute,SIMLocalized(@"分"),(long)second,SIMLocalized(@"秒")];
    }
}

//返回绑定邮箱获取验证码剩余倒计时 如果有倒计时返回倒计时 如果没有 返回0
+ (NSInteger)returnEmailBindTime:(NSInteger)tag type:(CountDownTimeType)type
{
    NSString * userDefaultsStr;
    NSInteger  userDefaultsDefineTime = 0;
    switch (type) {
        case CountDownTimeTypeEmail:
            userDefaultsStr = @"TimeCountDown-EmailBind";
            userDefaultsDefineTime = EmailBindCountDownTime;
            break;
        case CountDownTimeTypeRegist:
            userDefaultsStr = @"TimeCountDown-Regist";
            userDefaultsDefineTime = RegistCountDownTime;
            break;
        case CountDownTimeTypeRealName:
            userDefaultsStr = @"TimeCountDown-RealName";
            userDefaultsDefineTime = RealNameCountDownTime;
            break;
        case CountDownTimeTypeFindLostPwdByPhoneNumber:
            userDefaultsStr = @"TimeCountDown-FindLostPwdByPhoneNumber";
            userDefaultsDefineTime = FindLostPwdByPhoneCountDownTime;
            break;
        case CountDownTimeTypeFindLostPwdByEmail:
            userDefaultsStr = @"TimeCountDown-FindLostPwdByEmail";
            userDefaultsDefineTime = FindLostPwdByEmailCountDownTime;
            break;
        case CountDownTimeTypeSetPayPwd:
            userDefaultsStr = @"TimeCountDown-SetPayPwd";
            userDefaultsDefineTime = SetPayPwdCountDownTime;
            break;
        case CountDownTimeTypeResetLoginPwdByPhoneNumber:
            userDefaultsStr = @"TimeCountDown-ResetLoginPwdByPhoneNumber";
            userDefaultsDefineTime = ResetLoginPwdByPhoneCountDownTime;
            break;
        case CountDownTimeTypeResetLoginPwdByEmail:
            userDefaultsStr = @"TimeCountDown-ResetLoginPwdByEmail";
            userDefaultsDefineTime = ResetLoginPwdByEmailCountDownTime;
            break;
        case CountDownTimeTypeRelieveEmail:
            userDefaultsStr = @"TimeCountDown-ResetLoginPwdByRelieveEmail";
            userDefaultsDefineTime = RelieveEmailPwdByRelieveEmailCountDownTime;
            break;
            
        default:
            break;
    }
    //存储时间戳
    NSString * dateSave = [[NSUserDefaults standardUserDefaults] valueForKey:userDefaultsStr];
    //当前时间戳
    NSDate* date = [NSDate dateWithTimeIntervalSinceNow:0];
    NSTimeInterval time=[date timeIntervalSince1970];
    NSString *timeString = [NSString stringWithFormat:@"%.0f", time];
    
    if(tag == 1)
    {
        [[NSUserDefaults standardUserDefaults] setValue:timeString forKey:userDefaultsStr];
        [[NSUserDefaults standardUserDefaults] synchronize];
        //返回 绑定邮箱倒计时60秒
        return userDefaultsDefineTime;
    }
    else
    {
        //当前绑定邮箱时间为空时 返回0
        if ([dateSave isEqualToString:@"0"]) {
            return 0;
        }
        else
        {
            //作对比 返回时间
            if((userDefaultsDefineTime - (timeString.doubleValue - dateSave.doubleValue)) <= userDefaultsDefineTime && (userDefaultsDefineTime - (timeString.doubleValue - dateSave.doubleValue)) >= 0)
            {
                return (userDefaultsDefineTime - (timeString.doubleValue - dateSave.doubleValue));
            }
            else
            {
                return 0;
            }
        }
    }

}

+(int)compareDate:(NSString*)startTime withDate:(NSString*)endTime{
    int ci;
    NSDateFormatter *df = [[NSDateFormatter alloc]init];
    [df setDateFormat:@"yyyy-MM-dd HH:mm"];
    NSDate *dt1;
    NSDate *dt2;
    dt1 = [df dateFromString:startTime];
    dt2 = [df dateFromString:endTime];
    NSComparisonResult result = [dt1 compare:dt2];
    switch (result)
    {
            //endTime > startTime
        case NSOrderedAscending: ci = 1;break;
            //endTime < startTime
        case NSOrderedDescending: ci = -1;break;
            //endTime = startTime
        case NSOrderedSame: ci = 0;break;
        default: NSLog(@"erorr dates %@, %@", dt2, dt1);break;
    }
    return ci;
}

//时间---->时间戳
+(NSString *)transTotimeSp:(NSString *)time{
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setTimeZone:[NSTimeZone localTimeZone]]; //设置本地时区
    [dateFormatter setDateFormat:@"yyyy-MM-dd"];
    NSDate *date = [dateFormatter dateFromString:time];
    NSString *timeSp = [NSString stringWithFormat:@"%ld", (long)[date timeIntervalSince1970]];//时间戳
    return timeSp;
}

+(NSString *)transToDate:(NSString *)timsp{
    
    NSTimeInterval time=[timsp doubleValue];//如果不使用本地时区,因为时差问题要加8小时 == 28800 sec
    NSDate *detaildate=[NSDate dateWithTimeIntervalSince1970:time];
    
    //实例化一个NSDateFormatter对象
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setTimeZone:[NSTimeZone localTimeZone]];//设置本地时区
    //设定时间格式,这里可以设置成自己需要的格式
    [dateFormatter setDateFormat:@"yyyy-MM-dd"];
    
    NSString *currentDateStr = [dateFormatter stringFromDate: detaildate];
    
    return currentDateStr;
}

+ (NSString *)dateChangeWihtStr:(NSString *)str
{
    NSDate * date = [[NSDate alloc] initWithTimeIntervalSince1970:str.longLongValue];
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    dateFormatter.dateFormat = @"yyyy-MM-dd HH:mm:ss";
    return [dateFormatter stringFromDate:date];
}
@end
