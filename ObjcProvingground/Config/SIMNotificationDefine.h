//
//  SIMNotificationDefine.h
//  SAMIM
//
//  Created by 121 on 2018/9/29.
//  Copyright © 2018年  . All rights reserved.
//

#ifndef SIMNotificationDefine_h
#define SIMNotificationDefine_h

//删除所有通知
#define SIMRemoveAllNotifications [[NSNotificationCenter defaultCenter] removeObserver:self]
//删除某一通知
#define SIMRemoveANotification(observer , aName , anObject) [[NSNotificationCenter defaultCenter] removeObserver:observer name:aName object:anObject];
//注册通知
#define SIMAddNotification(observer , aSelector , aName , anObject) [[NSNotificationCenter defaultCenter] addObserver:observer selector:aSelector name:aName object:anObject]
//发送通知 anObject
#define SIMPostNotification(aName , anObject) [[NSNotificationCenter defaultCenter] postNotificationName:aName object:anObject]

//添加删除好友后，刷新好友详细资料页面
#define NOTIFICATION_REFRESH_ISFRIENDINFO    @"NOTIFICATION_REFRESH_ISFRIENDINFO"
//刷新好友详细资料页面
#define NOTIFICATION_REFRESH_FRIENDINFO    @"NOTIFICATION_REFRESH_FRIENDINFO"
//刷新好友列表
#define NOTIFICATION_REFRESH_FRIENDS         @"NOTIFICATION_REFRESH_FRIENDS"
//刷新群组列表
#define NOTIFICATION_REFRESH_GROUPS          @"NOTIFICATION_REFRESH_GROUPS"
//刷新群成员列表
#define NOTIFICATION_REFRESH_GROUPS_MEMBER   @"NOTIFICATION_REFRESH_GROUPS_MEMBER"
//退出群聊天界面
#define NOTIFICATION_REFRESH_GROUPS_DISSOLVE @"NOTIFICATION_REFRESH_GROUPS_DISSOLVE"
//刷新群详情
#define NOTIFICATION_REFRESH_GROUPSDETAIL    @"NOTIFICATION_REFRESH_GROUPSDETAIL"
//收到群禁言
#define NOTIFICATION_GROUPSLIENCE            @"NOTIFICATION_GROUPSLIENCE"
//收到群禁言取消
#define NOTIFICATION_GROUPSLIENCECANCEL      @"NOTIFICATION_GROUPSLIENCECANCEL"
//收到群到期
#define NOTIFICATION_GROUPSHASEXPIRED        @"NOTIFICATION_GROUPSHASEXPIRED"
//收到群公告
#define NOTIFICATION_NEWGROUPANNOUNCEMENT    @"NOTIFICATION_NEWGROUPANNOUNCEMENT"
//刷新群开启免打扰
#define NOTIFICATION_REFRESH_GROUPS_RECEIVETIP @"NOTIFICATION_REFRESH_GROUPS_RECEIVETIP"
////刷新群主消息插入消息
//#define NOTIFICATION_REFRESH_GROUPOWNERCHAT_APPENDINTOMESSAGE @"NOTIFICATION_REFRESH_GROUPOWNERCHAT_APPENDINTOMESSAGE"
////刷新群主消息撤回删除消息
//#define NOTIFICATION_REFRESH_GROUPOWNERCHAT_REMOVEMESSAGE @"NOTIFICATION_REFRESH_GROUPOWNERCHAT_REMOVEMESSAGE"
////刷新群主消息更新状态
//#define NOTIFICATION_REFRESH_GROUPOWNERCHAT_UPDATEESSAGE @"NOTIFICATION_REFRESH_GROUPOWNERCHAT_UPDATEESSAGE"
////刷新群主消息置顶页面
//#define NOTIFICATION_REFRESH_GROUPOWNERCHAT_REFRESHMESSAGE @"NOTIFICATION_REFRESH_GROUPOWNERCHAT_REFRESHMESSAGE"
////刷新群主消息置顶状态
//#define NOTIFICATION_REFRESH_GROUPS_MSGTOP @"NOTIFICATION_REFRESH_GROUPS_MSGTOP"


//退出群组列表通知
#define NOTIFICATION_REFRESH_QUITGROUPS      @"NOTIFICATION_REFRESH_QUITGROUPS"
//刷新群组title
#define NOTIFICATION_REFRESH_GROUPS_NAME     @"NOTIFICATION_REFRESH_GROUPS_NAME"
//刷新群组image
#define NOTIFICATION_REFRESH_GROUPS_IMAGE    @"NOTIFICATION_REFRESH_GROUPS_IMAGE"
//刷新群聊界面群成员个数
#define NOTIFICATION_REFRESH_GROUPS_CHATVIEWMEMBER @"NOTIFICATION_REFRESH_GROUPS_CHATVIEWMEMBER"
//刷新群组显示群昵称
#define NOTIFICATION_REFRESH_GROUPS_SHOWNAME     @"NOTIFICATION_REFRESH_GROUPS_SHOWNAME"


//隐藏底部tabbar
#define NOTIFICATION_TABBAR_HIDDEN          @"NOTIFICATION_TABBAR_HIDDEN"

//刷新会话消息
#define NOTIFICATION_REFRESH_SESSION          @"refreshMsgData"
//阅后即焚状态改变
#define NOTIFICATION_SNAPSTATUSMESSAGECHANGE  @"NOTIFICATION_SnapStatusMessageChanged"

//接受到新消息
#define NOTIFICATION_ACQUIRE_MESSAGE          @"NOTIFICATION_ACQUIRE_MESSAGE"
#define kMessageAddToDatabaseNotify           @"MessageAddToDatabaseNotify"
#define NOTIFICATION_UpdataMessageSendStatus  @"UpdataMessageSendStatus"

//聊天界面接受到新消息
#define NOTIFICATION_ACQUIRE_MESSAGE_CHATVIEW          @"NOTIFICATION_ACQUIRE_MESSAGE_CHATVIEW"
// refreshVoiceChatData
//聊天界面接收新消息
#define NOTIFICATION_ACQUIRE_OFFLINEMESSAGECOUNTER_CHATVIEW      @"NOTIFICATION_ACQUIRE_OFFLINEMESSAGECOUNTER_CHATVIEW"
//消息列表接收新消息
#define NOTIFICATION_ACQUIRE_OFFLINEMESSAGECOUNTER      @"NOTIFICATION_ACQUIRE_OFFLINEMESSAGECOUNTER"
//刷新消息列表当前会话sessionId
#define NOTIFICATION_REFRESH_SESSIONLISTINCHATSESSIONID      @"NOTIFICATION_REFRESH_SESSIONLISTINCHATSESSIONID"
//web消息同步通知，更新sessionId对应的会话
#define NOTIFICATION_WEBSYNC_SESSIONLISTINCHATSESSIONID      @"NOTIFICATION_WEBSYNC_SESSIONLISTINCHATSESSIONID"
//刷新消息列表
#define NOTIFICATION_REFRESH_SESSIONLIST      @"NOTIFICATION_REFRESH_SESSIONLIST"
//刷新加好友申请列表
#define NOTIFICATION_REFRESH_ADDFRIENDLIST    @"NOTIFICATION_REFRESH_ADDFRIENDLIST"
//刷新钱包
#define NOTIFICATION_REFRESH_WALLETBALANCE    @"NOTIFICATION_REFRESH_WALLETBALANCE"
//刷新收付款 xx正在付款界面
#define NOTIFICATION_REFRESH_PAYMENTLOADING   @"NOTIFICATION_REFRESH_PAYMENTLOADING"
//刷新收付款 xx取消付款
#define NOTIFICATION_REFRESH_PAYMENTFAIL      @"NOTIFICATION_REFRESH_PAYMENTFAIL"

//注册成功
#define NOTIFICATION_REFRESH_REGISTERSUCCESS   @"NOTIFICATION_REFRESH_REGISTERSUCCESS"
//第一次设置支付密码成功
#define NOTIFICATION_REFRESH_SETPAYPWDSUCCESS  @"NOTIFICATION_REFRESH_SETPAYPWDSUCCESS"
//接受到解除好友消息
#define NOTIFICATION_DELETEFRIEND_MESSAGE      @"NOTIFICATION_DELETEFRIEND_MESSAGE"
//拍摄视频下载成功
#define NOTIFICATION_DELETEFRIEND_VIDEOSUCCESS @"NOTIFICATION_DELETEFRIEND_VIDEOSUCCESS"
//刷新公众号键盘
#define NOTIFICATION_REFRESH_PUBLICNOFUNCTION  @"NOTIFICATION_REFRESH_PUBLICNOFUNCTION"
//请求公众号菜单消息
#define NOTIFICATION_REQUST_PUBLICNOFUNCTIONMESSAGE @"NOTIFICATION_REQUST_PUBLICNOFUNCTIONMESSAGE"
//点击公众号消息
#define NOTIFICATION_CLICK_PUBLICNOMESSAGE     @"NOTIFICATION_CLICK_PUBLICNOMESSAGE"
//设置气泡
#define NOTIFICATION_REPLACEBUBBLESUCCESS      @"NOTIFICATION_REPLACEBUBBLESUCCESS"
//其他设备上线
#define NOTIFICATION_OTHEREQUIPMENT_ONLINE     @"NOTIFICATION_OTHEREQUIPMENT_ONLINE"
//其他设备下线
#define NOTIFICATION_OTHEREQUIPMENT_OFFLINE    @"NOTIFICATION_OTHEREQUIPMENT_OFFLINE"
//新的朋友已读
#define NOTIFICATION_NEWFRIEND_HAVEREAD   @"NOTIFICATION_NEWFRIEND_HAVEREAD"
//好朋在线状态变化
#define NOTIFICATION_FRIEND_ISONLINESTATE   @"NOTIFICATION_FRIEND_ISONLINESTATE"

//公告弹窗 100
#define SIMMessageTypeAnnouncementAlertNot   @"SIMMessageTypeAnnouncementAlertNot"

//离线公告红点 101
#define SIMMessageTypeOfflineAnnouncementPointNot   @"SIMMessageTypeOfflineAnnouncementPointNot"

//未读消息刷新
#define SIMMessageAnnouncementNumChange   @"SIMMessageAnnouncementNumChange"
// 直播间数量
#define SIMMessageLiveNumChange   @"SIMMessageLiveNumChange"

//抽奖活动来了 111
#define SIMMessageTypeLuckyDrawActivityAlertNot   @"SIMMessageTypeLuckyDrawActivityAlertNot"

/**音视频通知**/
//TOMessageTypeVoiceRequest = 150,        //有人向你发起音频通话
#define NOTIFICATION_VoiceVideo_VoiceRequest @"NOTIFICATION_VoiceVideo_VoiceRequest"
//TOMessageTypeVideoRequest = 151,        //有人向你发起视频通话
#define NOTIFICATION_VoiceVideo_VideoRequest @"NOTIFICATION_VoiceVideo_VideoRequest"
//TOMessageTypeAgreeVoiceRequest = 152,        //同意对方音频通话
#define NOTIFICATION_VoiceVideo_AgreeVoiceRequest @"NOTIFICATION_VoiceVideo_AgreeVoiceRequest"
//TOMessageTypeAgreeVideoRequest = 153,        //同意对方视频通话
#define NOTIFICATION_VoiceVideo_AgreeVideoRequest @"NOTIFICATION_VoiceVideo_AgreeVideoRequest"
//TOMessageTypeRefuseVoiceRequest = 154,        //拒绝对方音频通话
#define NOTIFICATION_VoiceVideo_RefuseVoiceRequest @"NOTIFICATION_VoiceVideo_RefuseVoiceRequest"
//TOMessageTypeRefuseVideoRequest = 155,        //拒绝对方视频通话
#define NOTIFICATION_VoiceVideo_RefuseVideoRequest @"NOTIFICATION_VoiceVideo_RefuseVideoRequest"
//TOMessageTypeCancleVoiceVideo = 156,        //挂断对方音视频通话
#define NOTIFICATION_VoiceVideo_CancleVoiceVideo @"NOTIFICATION_VoiceVideo_CancleVoiceVideo"
//TOMessageTypeChangeVideoToVoiceRequest = 157,        //对方切换视频通话为音频
#define NOTIFICATION_VoiceVideo_ChangeVideoToVoiceRequest @"NOTIFICATION_VoiceVideo_ChangeVideoToVoiceRequest"
//TOMessageTypeChangeVoiceToVideoRequest = 158,        //对方请求切换音频通话为视频
#define NOTIFICATION_VoiceVideo_ChangeVoiceToVideoRequest @"NOTIFICATION_VoiceVideo_ChangeVoiceToVideoRequest"
//TOMessageTypeAgreeChangeVoiceToVideoRequest = 159,        //对方同意切换音频通话为视频
#define NOTIFICATION_VoiceVideo_AgreeChangeVoiceToVideoRequest @"NOTIFICATION_VoiceVideo_AgreeChangeVoiceToVideoRequest"
//TOMessageTypeRefuseChangeVoiceToVideoRequest = 160,        //对方拒绝切换音频通话为视频
#define NOTIFICATION_VoiceVideo_RefuseChangeVoiceToVideoRequest @"NOTIFICATION_VoiceVideo_RefuseChangeVoiceToVideoRequest"
//TOMessageTypeAbnormalCancleVoiceVideo = 161 //对方异常退出
#define NOTIFICATION_VoiceVideo_AbnormalCancleVoiceVideo @"NOTIFICATION_VoiceVideo_AbnormalCancleVoiceVideo"
//TOMessageTypeCancleMultiVideoRequest = 165 //提出者结束多对多音视频通话
#define NOTIFICATION_MultiVideo_CancleMultiVideoRequest @"NOTIFICATION_MultiVideo_CancleMultiVideoRequest"
//SIMMessageTypeMultiVoiceRequest == 163 群视频邀请
#define NOTIFICATION_VoiceVideo_MultiVideoRequest @"NOTIFICATION_VoiceVideo_MultiVideoRequest"
/// 同意对方音频通话(声聊)SIMMessageTypeAgreeVoiceChatRequest = 402
#define NOTIFICATION_VoiceVideo_VoiceChatRequest @"NOTIFICATION_VoiceVideo_VoiceChatRequest"
/// 同意对方音视频通话(声聊) SIMMessageTypeAgreeVideoChatRequest = 403
#define NOTIFICATION_VoiceVideo_VideoChatRequest @"NOTIFICATION_VoiceVideo_VideoChatRequest"
/// 拒绝对方音频通话(声聊) SIMMessageTypeRefuseVoiceChatRequest = 404
#define NOTIFICATION_VoiceVideo_RefuseVoiceChatRequest @"NOTIFICATION_VoiceVideo_RefuseVoiceChatRequest"
/// 拒绝对方音视频通话(声聊) SIMMessageTypeRefuseVideoChatRequest = 405
#define NOTIFICATION_VoiceVideo_RefuseVideoChatRequest @"NOTIFICATION_VoiceVideo_RefuseVideoChatRequest"
/// 对方挂断音频通话(声聊) SIMMessageTypeCancleVoiceChatVideo = 406
#define NOTIFICATION_VoiceVideo_CancleVoiceChatVideo @"NOTIFICATION_VoiceVideo_CancleVoiceChat"
/// 对方挂断音视频通话(声聊)SIMMessageTypeCancleVideoChatVideo = 407
#define NOTIFICATION_VoiceVideo_CancleVideoChatVideo @"NOTIFICATION_VoiceVideo_CancleVoiceChat"

#define NOTIFICATION_MultiVideo_CreateMultiVideoRequest @"NOTIFICATION_MultiVideo_CreateMultiVideoRequest"
//有人进入或者有人退出发送的通知
#define NOTIFICATION_MultiVideo_SomeoneJoin @"NOTIFICATION_MultiVideo_SomeoneJoin"
#define NOTIFICATION_MultiVideo_SomeoneExit @"NOTIFICATION_MultiVideo_SomeoneExit"

//打电话对方正忙通知
#define NOTIFICATION_MultiVideo_OnThePhoneIsBusy @"NOTIFICATION_MultiVideo_OnThePhoneIsBusy"

#define NOTIFICATION_MultiVideo_EndMultiVideoRequest @"NOTIFICATION_MultiVideo_EndMultiVideoRequest"
//SIMMessageTypeMediaCameraControl = 169 //对方关闭开启摄像头
#define NOTIFICATION_VoiceVideo_MediaCameraControl @"NOTIFICATION_VoiceVideo_MediaCameraControl"


//第三方请求音频视频通话
#define NOTIFICATION_VoiceVideo_ThirdPartyVoiceToVideoRequest @"NOTIFICATION_VoiceVideo_ThirdPartyVoiceToVideoRequest"

//接收到1002的离线消息
#define NOTIFICATION_RECEIVEOFFLINEMESSAGEARRAY  @"NOTIFICATION_ReceiveOfflineMessageArray"

#define NOTIFICATION_clickLocalNotication_enter @"NOTIFICATION_clickLocalNotication_enter"
//直播公告 SIMMessageType
#define NOTIFICATION_LiveAnnouncementNotication_enter @"NOTIFICATION_clickLocalNotication_enter"

// 游戏入口隐藏通知
#define NOTIFICATION_GameEntranceHiddenNotication @"NOTIFICATION_GameEntranceHiddenNotication"
// 视频最小化回到最初状态
#define NOTIFICATION_AgoraViewControllerReturnNotication @"NOTIFICATION_AgoraViewControllerReturnNotication"
// 窗口最小化隐藏
#define NOTIFICATION_AgoraViewControllerHiddenNotication @"NOTIFICATION_AgoraViewControllerHiddenNotication"
// 异常状态隐藏
#define NOTIFICATION_AgoraViewControllerRemoveNotication @"NOTIFICATION_AgoraViewControllerRemoveNotication"

// 关注声聊主播通知
#define NOTIFICATION_FocusVoiceChatNotication @"NOTIFICATION_FocusNotication"
// 声聊提交主播资料成功
#define NOTIFICATION_VoiceChatInfoNotication @"NOTIFICATION_VoiceChatInfoNotication"
// 声聊禁播,开播通知
#define NOTIFICATION_VoiceChatStatusNotication @"NOTIFICATION_VoiceChatStatusNotication"
//声聊收付凭证
#define NOTIFICATION_VoiceChatPaySuccess @"NOTIFICATION_VoiceChatPaySuccess"

// firbaseStroage
#define NOTIFICATION_uploadCancel @"NOTIFICATION_uploadCancel"
#define NOTIFICATION_PauseUploadTask @"NOTIFICATION_PauseUploadTask"
#define NOTIFICATION_AppDeath @"AppDeath"
#endif /* SIMNotificationDefine_h */
