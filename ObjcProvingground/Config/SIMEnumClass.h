//
//  SIMEnumClass.h
//  SAMIM
//
//  Created by   on 2018/9/29.
//  Copyright © 2018年  . All rights reserved.
//

#ifndef SIMEnumClass_h
#define SIMEnumClass_h

// 针对 注册时 用户类型，定义一个枚举
typedef NS_ENUM(NSInteger , SIMRegisterType)
{
    SIMRegisterTypeManage = 5, //管理员
    SIMRegisterTypeEmployee    //员工
};

typedef enum {
    SortTypeDown,//降序
    SortTypeUp//升序
}SortType;


//搜索类型
typedef enum : NSUInteger {
    SearchResultsTypeContacts,//好友列表搜索好友
    SearchResultsTypeGroups,//群列表搜索群
    SearchResultsTypeGroupMembersAT,//转让群组群成员列表搜索群成员
    SearchResultsTypeGroupMembersTRANSFER,//转让群组群成员列表搜索群成员
    SearchResultsTypePublicNum,//公众号
    SearchResultsTypeUserIDContacts,//好友列表ID搜索好友
} SearchResultsType;

// 消息类型
typedef NS_ENUM(NSInteger, SIMMessageType)
{
    SIMMessageTypeText = 2,                      //文字
    SIMMessageTypePhoto,                         //图片
    SIMMessageTypeDocument,                      //文件
    SIMMessageTypeFriendOnLine = 5,              //好友上线
    SIMMessageTypeFriendOffLine = 6,             //好友离线
    SIMMessageTypeDeleteFriend  = 7,             //解除好友
    SIMMessageTypePeopleJoinGroup = 8,           //有人加入群
    SIMMessageTypePeopleExitGroup = 9,           //有人退出群
    SIMMessageTypeGroupNotice = 10,              //处理群通知
    SIMMessageTypePeopleRequestAddFriend = 11,   //有人申请加好友
    SIMMessageTypePeopleAddFriendPass  = 12,     //申请加好友的请求被通过
    SIMMessageTypePeopleRequestAddGroup = 13,    //有人申请加入群
    SIMMessageTypePeopleAddGroupPass = 14,       //申请加入群的请求被通过
    SIMMessageTypePeopleOtherDeviceLogin = 15,   //其他设备登录
    SIMMessageTypeVoice = 16,                    //语音
    SIMMessageTypeRedPacket,                     //红包
    SIMMessageTypeTransfer,                      //转账
    SIMMessageTypeReceiveRedPacket,              //有人接收红包 领取红包
    SIMMessageTypeConfirmTransfer = 20,               //确认转帐收钱通知
    SIMMessageTypeTransferReturn,                //转帐退回通知
    SIMMessageTypeRedPacketReturn,               //红包过期退还通知
    SIMMessageTypeRedPacketNotHave = 23,         //自动加好友消息
    SIMMessageTypeRedPacketReceiveTime = 24,     //红包多少秒被领取完
    SIMMessageTypeSystem,                        //系统提示
    SIMMessageTypeFriendsChangeInfo = 26,        //好友修改了个人资料
    SIMMessageTypeGroupMemberChangeNickName = 27,//群成员修改了昵称
    SIMMessageTypeNameCard = 28,                 //名片
    SIMMessageTypePosition,                      //位置
    SIMMessageTypeVideo,                         //小视频
    SIMMessageTypeSnap = 31,                     //阅后即焚
    SIMMessageTypeWithdraw = 32,                 //消息撤回
    SIMMessageTypeRead,                          //消息已读
    SIMMessageTypeBQMM,                          //表情云
    SIMMessageTypeAt,                            //@
    SIMMessageTypeFriendsCircleUpdate,           //有好友发布了朋友圈动态
    SIMMessageTypeFriendsCircleNewComment,       //好友评论了你的动态，或者回复了你的评论
    SIMMessageTypeFriendsCircleNewPraise,        //好友赞了你的朋友圈，或者赞了你参与你的朋友圈
    SIMMessageTypeFriendsAccountNotify,          //转账到账通知(aa收款，二维码收付款到账)
    SIMMessageTypeAACollection = 40,             //AA收款
    SIMMessageTypePayRequest = 41,               //有人要求你付款,(如当别人扫了你的付款码时)
    SIMMessageTypePaymentLoading = 42,           //有人扫了你的收款码时，显示xxx正在付款
    SIMMessageTypePaymentFail = 43,              //有人扫了你的收款码后退出，显示支付失败
    
    SIMMessageTypeChangeGroupHead = 46,          //修改群头像
    SIMMessageTypeGroupNoticeAddNew = 47,        //群公告 发布新的
    SIMMessageTypeGroupNoticeChange = 48,        //群公告 修改编辑
    SIMMessageTypeCircleAtFriend    = 49,        //朋友圈@好友
    SIMMessageTypePasswordRedPacket = 50,        //口令红包领取通知
    SIMMessageTypeGroupDissolution = 51,         //群解散
    SIMMessageTypeGroupChangeMasterNotice = 52,  //转让群的通知（转让给当前用户）
    SIMMessageTypeGroupOwnerReciveChangeMasterPass = 53, //群主收到转让同意通知
    SIMMessageTypeGroupOwnerReciveChangeMasterNotPass = 54, //群主收到转让拒绝通知
    SIMMessageTypeGroupSetManager = 55,//设置管理员
    SIMMessageTypeReceiveGroupDescriptions = 56,//群介绍
    SIMMessageTypeGroupCancleSetManager = 57,   //取消设置管理员
    SIMMessageTypeGroupTimeExpire = 58,         //群到期提醒
    SIMMessageTypeRequestAddGroup = 59,         //申请加群
    SIMMessageTypeAgreeAddGroup = 60,           //同意加群
    SIMMessageTypeRefuseAddGroup = 61,          //拒绝加群
    SIMMessageTypeForbiddenWordsSuccess = 62,   //禁言成功
    SIMMessageTypeCancleForbiddenWords = 63,    //取消禁言
    SIMMessageTypeKickYouOutGroup = 64,         //被踢出群组
    SIMMessageTypeMyInGroupTimeExpire = 65,     //我所在的群到期
    SIMMessageTypeSendMessageRefused = 66,       //被对方加入黑名单后，给对方发消息被拒绝接受
    
    SIMMessageTypeSystemMsgNotice = 68, //系统消息提醒通知

    SIMMessageTypePublicMessage = 70,            //公众号消息
    SIMMessageTypeGroupRobotOpen = 71,           //群组开启聊天机器人（机器人加入）
    SIMMessageTypeGroupRobotClose = 72,          //群组关闭聊天机器人（机器人退出）
    SIMMessageTypeVipOvertime = 73,              //vip到期
    SIMMessageTypeGroupAllSilenceOpen = 74,      //全体群禁言开启
    SIMMessageTypeGroupAllSilenceClose = 75,     //全体群禁言关闭
    SIMMessageTypeGroupShake = 76,               //群震
    SIMMessageTypeGroupAllMsgTop = 77,           //群主消息置顶
    SIMMessageTypeGroupSnapChat = 81,            //群组阅后即焚开关更新
    SIMMessageTypeGroupScreenShot = 83,          //群组截屏通知开关更新
    SIMMessageTypeSomeBodyScreenMsg = 88 ,       //截屏消息
    SIMMessageTypeGroupInvite = 89,              //群链接邀请
    SIMMessageTypeFriendShake = 90,              //私聊戳一戳
    SIMMessageTypeFriendScreenShot = 91,         //私聊对方截屏通知开关更新
    SIMMessageTypeFriendLive = 92,         //聊天直播分享
    SIMMessageTypeLifeShare = 93,  /// life 分享消息
    SIMMessageTypeLiveReplayShare = 94,  /// 主播回放分享
    SIMMessageTypeConsumerCash = 95,  // 提现通知
    SIMMessageTypeThirdTradePGP = 96,// 第三方扣點
    SIMMessageTypeInviteJoinGroup = 97, // 邀請入群通知
    SIMMessageTypeJoinGroupPay = 98,  // 進群支付通知
    SIMMessageTypeAnnouncementAlert = 100,         //公告弹窗 不给红点
    SIMMessageTypeOfflineAnnouncementPoint = 101,         //离线公告红点 登陆后会有
    SIMMessageTypePaySuccess = 102,  //充值成功
    SIMMessageTypeIDAuthentication = 103,  //身份认证状态系统提醒消息
    SIMMessageTypeIDBank = 104,  //银行状态系统提醒消息
    SIMMessageTypeApplyLive = 105,  //申请开播
    SIMMessageTypeKickLive = 106,  //禁播
    SIMMessageTypeCancelMute = 107,  //取消禁言
    SIMMessageTypeLiveAnnouncement = 108,  //直播公告
    SIMMessageTypeTaiWanTaxiPaySuccess = 110,         // 台湾大车队支付凭证
    SIMMessageTypeLuckyDrawActivityAlert = 111,         //抽奖活动弹窗
    SIMMessageTypePayRefundSuccess = 112,// 商家退款
    SIMMessageTypePayVoiceChatReceiveSuccess = 113,// 声聊收款 
    SIMMessageTypePayVoiceChatPaySuccess = 114,// 声聊付款
    SIMMessageTypePayVoiceChatRecommend = 115,// 成为、取消推荐声聊主播
    SIMMessageTypePayVoiceChatStatus = 116,// 解禁、禁播 声聊
    SIMMessageTypeTalkMoneyTask = 117,// 每日任务奖励弹窗
    SIMMessageTypeQRCodePay = 118,// 扫码支付
    SIMMessageTypeLaLaMovePay = 119,// lalamove支付
    SIMMessageTypeLaLaMoveStatus = 120,// lalamove狀態變更
    SIMMessageTypeMoviePay = 121,// movie支付
    SIMMessageTypeTaxiStatus = 122,// 大車隊訂單狀態變更
    SIMMessageTypeBlessingPay = 124,// 宗教祭祀支付通知
    SIMMessageTypeConsumerGivePay = 123,// 購點滿贈通知
    SIMMessageTypeBlessing = 125,// 宗教祭祀點燈通知
    SIMMessageTypeConcert = 126,// 演唱會消費消息
    SIMMessageTypeDiamondPayRecord = 127,// 鑽石購買收付
    SIMMessageTypeConcertRefund = 128,// 演唱會退款通知
    SIMMessageTypeConcertAudit = 129,// 演唱會審核通知
    SIMMessageTypeConsumerPresentation = 130,// 消費滿額贈送
    SIMMessageTypeConsumerPGPay = 131,// PGPay付款凭证
    SIMMessageTypeCardBindRefund = 132,// 信用卡绑定退款
    SIMMessageTypeJoinGroupMsg = 133,// 加入群組
    SIMMessageTypeDeleteFriendsCircle = 134,// 刪除動態通知 content 內容為 動態ID
    SIMMessageTypeDeleteFriendsCircleComment = 135,// 刪除評論通知 content 內容為 評論ID
    SIMMessageTypeAgreeFriends = 136,//同意方需處理新增消息類型
    SIMMessageTypeRegisterGiving = 137,///註冊贈送通知
    SIMMessageTypeConsumerPGPosPay = 138,/// pos機確認支付
    SIMMessageTypeConsumerPGPosComplete = 139,/// pos機付款成功通知
    SIMMessageTypeConsumerPGPosRecharge = 140,/// 到店儲值成功
    SIMMessageTypeConsumerPGPosRechargeFailure = 141,/// 儲值失败
    SIMMessageTypeConsumerPGPosRechargeRefund = 142,/// pos机退款
    SIMMessageTypeDiamondBusinessBuy = 143,//// 幣商購買鑽石通知
    SIMMessageTypeDiamondBusinessTransfer = 144,//// 用戶向幣商購買鑽石通知
    SIMMessageTypeConsumerActivityRedPacket = 145,/// 活動红包通知
    SIMMessageTypeConsumerRedPacket = 146,/// 紅包通知
    SIMMessageTypeConsumerLive = 147,/// 直播消费通知
    SIMMessageTypeConsumerGame = 148,/// 遊戲奖励通知
    SIMMessageTypeDeductionPGP = 149,/// 系統扣點通知
    SIMMessageTypeVoiceRequest = 150,            //有人向你发起音频通话
    SIMMessageTypeVideoRequest = 151,            //有人向你发起视频通话
    SIMMessageTypeAgreeVoiceRequest = 152,       //同意对方音频通话
    SIMMessageTypeAgreeVideoRequest = 153,       //同意对方音频通话
    SIMMessageTypeRefuseVoiceRequest = 154,      //拒绝对方音频通话
    SIMMessageTypeRefuseVideoRequest = 155,      //拒绝对方视频通话
    SIMMessageTypeCancleVoiceVideo = 156,        //挂断对方音视频通话
    SIMMessageTypeChangeVideoToVoiceRequest = 157,        //对方切换视频通话为音频
    SIMMessageTypeChangeVoiceToVideoRequest = 158,        //对方请求切换音频通话为视频
    SIMMessageTypeAgreeChangeVoiceToVideoRequest = 159,   //对方同意切换音频通话为视频
    SIMMessageTypeRefuseChangeVoiceToVideoRequest = 160,  //对方拒绝切换音频通话为视频
    SIMMessageTypeAbnormalCancleVoiceVideo = 161,         //对方异常退出
    SIMMessageTypeAbnormalMessageNotify = 162,            //音视频结束通话消息类型
    SIMMessageTypeMultiVoiceRequest = 163,                //有人向你发起多人音频通话
    SIMMessageTypeMultiVideoRequest = 164,                //有人向你发起多人视频通话
    SIMMessageTypeCancleMultiVideoRequest = 165,          //提起人结束多人视频通话
    SIMMessageTypeEndMultiVideoRequest = 166,             //最终结束多人视频通话 多人通话销毁
    SIMMessageTypeCreateMultiVideoRequest = 167,          //有人创建了多人视频通话
    SIMMessageTypeSomeBodyExitMultiVideoRequest = 168,        //有人退出多人视频通话
    SIMMessageTypeMediaCameraControl = 169,        //单人音视频 摄像头开启关闭
    SIMMessageTypeMediaBusy= 170,        //音视频繁忙，告知对方稍后，己方提示
    SIMMessageTypeSomeBodyJoinMultiVideoRequest = 171,        //有人进入多人视频通话
    SIMMessageTypeRefusedFriend = 172,//拒绝好友通知
    SIMMessageTypeGroupMultiVideoInviteRefused = 173,//多人视频通话 邀请挂断
    SIMMessageTypeGroupMultiVideoMute = 174,//多人视频通话 群組語音禁言 content 內容 {“mute”:0,“userId”:用户id} 0 禁言 1 正常
    SIMMessageTypeGroupMultiVideoGetMember = 175,//多人视频通话 獲取群組語音成員列表
    SIMMessageTypeGroupMultiVideoKickMember = 176,//多人视频通话  踢出频道    content 內容  {“userId”: 被踢的用户id}
    
    SIMMessageTypeDailyTasksAward = 177,// 每日任務收付明細 title 標題 currencyType 0PGP 1PT 2鑽石 amt 金額
    SIMMessageTypeVipSubscribe = 179,// vip訂閲通知status 1 續費成功 2 續費失敗 3 會員過期 vipExpireTime 過期時間
    SIMMessageTypeVipPay = 180,// vip訂閲支付通知 amt  金額  payTime 支付時間
    SIMMessageTypeVipActivityLottery = 181,// 福袋獎勵  giftType 0 PGP  amt 金額
    SIMMessageTypeVipExpireNotification = 182,// eventType 事件類型 vipExpire 會員過期
    SIMMessageTypeOtherEquipmentOnline = 200,                //其他设备上线
    SIMMessageTypeOtherEquipmentOffline= 201,                //其他设备下线
    SIMMessageTypeOperationOtherEquipmentOffline = 202,       //操作其他设备下线
    SIMMessageTypeReadOffline = 203,       //离线已读消息
    ///直播提醒消息type
    SIMMessageTypeLiveRemind = 300,
    
//定义完消息枚举要在SIMSocketManager里面添加定义的消息判断
    
    SIMMessageTypeOfflineMessageCounter = 1000,            //离线消息计数器
    SIMMessageTypeOfflineMessageList = 1001,               //离线消息
    SIMMessageTypeOfflineMessageArray = 1002,              //离线消息（以数组的形式返回）
    SIMMessageTypeOfflineMessageArrayConfirm = 1003,        //离线消息确认
    SIMMessageTypeOfflineMessageRadio = 1004,        //公告新消息
    SIMMessageTypeOfflineMessageRadioWithdraw = 1005,        //收回公告
    SIMMessageTypeOfflineMessageLiveRemind = 1006,        //直播提醒消息 离线消息
    SIMMessageTypeOfflineMessageWithdraw = 1007,        //撤回消息 离线消息
    SIMMessageTypeMakeAPhoneCallBackToDialThe = 10000,        //打电话回拨
    SIMMessageTypeWebReadMessageSync = 20000,              //web消息已读消息
    SIMMessageTypeVoiceChatPhoneCall = 30000,        //声聊打电话回拨
    SIMMessageTypeVoiceChatPhoneBusy = 111140,        //对方忙线中，收到这条消息自己结束拨打发送170
    SIMMessageTypeMultiVoiceChatPhoneBusy = 111150,        //多人语音邀请对方忙线中，收到这条消息提示对方忙线
    /*
     有人向你发起音频通话(声聊)
     */
    SIMMessageTypeVoiceChatRequest = 400,
    /*
     有人向你发起视频通话(声聊)
    */
    SIMMessageTypeVideoVideoChatRequest = 401,
    /*
    * 同意对方音频通话(声聊)
    */
    SIMMessageTypeAgreeVoiceChatRequest = 402,
    /*
    * 同意对方音视频通话(声聊)
    */
    SIMMessageTypeAgreeVideoChatRequest = 403,
    /*
    * 拒绝对方音频通话(声聊)
    */
    SIMMessageTypeRefuseVoiceChatRequest = 404,
    /*
    * 拒绝对方音视频通话(声聊)
    */
    SIMMessageTypeRefuseVideoChatRequest = 405,
    /*
    * 挂断对方音频通话(声聊)
    **/
    SIMMessageTypeCancleVoiceChatVideo = 406,
    /**
    * 挂断对方音视频通话(声聊)
    */
    SIMMessageTypeCancleVideoChatVideo = 407,
    
    /**
         * 个人介绍
         */
    MSG_TYPE_VOICE_INTRODUCTION = 408,

    /**
     * 视频
     */
   MSG_TYPE_VOICE_VIDEO = 409,

    /**
     * 音频
     */
    MSG_TYPE_VOICE_AUDIO = 410,

    /**
     * 项目介绍
     */
    MSG_TYPE_VOICE_DESCRIPTION = 411,

    /**
     * 欢迎语
     */
     MSG_TYPE_VOICE_WELCOME = 412,

    /**
     * 消费结算
     */
    MSG_TYPE_VOICE_CONSUME = 413,

    /**
     * 结束语
     */
    MSG_TYPE_VOICE_FINISH  = 414,
    
    /**
     * 声聊未读消息
     */
    MSG_TYPE_VOICE_UNREAD_MSG  = 415,
    /**
     * 声聊文本消息
     */
    SIMMessageTypeVideoChatText  = 416,
    /**
     * 声聊图片消息
     */
    SIMMessageTypeVideoChatImage  = 417,
    /**
     * 声聊语音消息
     */
    SIMMessageTypeVideoChatVoice = 418,
};

// 此枚举 区分 自己还是别人 发的消息
typedef NS_ENUM(NSInteger , SIMMessageFrom)
{
    SIMMessageFromMe = 0, // 自己发的
    SIMMessageFromOther   // 别人发的
};

// 此枚举: 弹出哪个视图的一个状态值
typedef NS_ENUM(NSInteger , SIMShowViewState)
{
    SIMShowViewStateVoice = 0,    //录音
    SIMShowViewStateKeyBoard,     //键盘
    SIMShowViewStateEmojiFace,    //表情
    SIMShowViewStateChatTool      //其他
};
/*
 * messageType
 * 1、客户端确认收到ready回应，并且处理完好友列表时，发送给服务器
 * 2、文本及表情消息
 * 3、图片消息
 * 4、文件
 * 5、好友上线，这时fromId为上线人的Id，destId为自己
 * 6、好友离线，这时fromId为离线人的Id，destId为自己
 * 7、解除好友，这时fromId为主动解除人的Id，destId为自己
 * 8、有人加入了群，这时fromId为加入的人，destId为群Id
 * 9、有人退出了群，这时fromId为退出人，destId为群Id
 * 10、被邀请加入群，这时fromId为被邀请人，destId为群id--->类同8同。
 * 11、有人申请加好友，这时fromId为请求人
 * 12、申请加好友的请求被通过，这时fromId为对方id,  destId为自己
 * 13、有人申请加入群，这时fromId为申请人，destId为群id
 * 14、申请加入群的请求被通过，这时fromId为审核人id，destId为群id
 * 15、账户从其它地方登陆，踢下线
 */

//im新红包状态
typedef NS_ENUM(NSInteger, RedPacketStatus) {
    RedPacketStatusSingle,//个人红包
    RedPacketStatusGroup  //群组红包
};

//im新红包类型
typedef NS_ENUM(NSInteger, RedPacketType) {
    RedPacketTypeGroupSpellLuck, //拼手气红包
    RedPacketTypeGroupOrdinary,  //普通红包
    RedPacketTypeGroupCommand,   //口令红包
    RedPacketTypeSingleOrdinary,  //普通红包
    RedPacketTypeSingleCommand   //口令红包
};

//im新红包类型
typedef NS_ENUM(NSInteger, ReturnCheckPayPwdResultType) {
    ReturnCheckPayPwdResultTypeRecharge, //验证充值金额不足
    ReturnCheckPayPwdResultTypeCheckNoPayPwd,  //验证无支付密码
    ReturnCheckPayPwdResultTypeCheckPayPwdFaild,  //验证支付密码错误
    ReturnCheckPayPwdResultTypeCheckPayPwdSuccess  //验证支付密码成功
};

enum {
    SIMAgoraMediaStyleSingleplayerVoice_SendByMe,//实时语音 我发起的
    SIMAgoraMediaStyleSingleplayerVoice_SendByOther,//实时语音 他人起的
    SIMAgoraMediaStyleSingleplayerVideo_SendByMe,//实时视频 我发起的
    SIMAgoraMediaStyleSingleplayerVideo_SendByOther,//实时视频 他人起的
    SIMAgoraMediaStyleMultiplayerVoice,//多人语音
    SIMAgoraMediaStyleMultiplayerVideo,//多人视频
    //声聊增加
    ///声聊实时语音 我发起的
    SIMAgoraMediaStyleSingleplayerVoiceChat_SendByMe,
    ///声聊实时语音 他人起的
    SIMAgoraMediaStyleSingleplayerVoiceChat_SendByOther,
    ///声聊实时视频 我发起的
    SIMAgoraMediaStyleSingleplayerVideoChat_SendByMe,
    ///声聊实时视频 他人起的
    SIMAgoraMediaStyleSingleplayerVideoChat_SendByOther,
    
};
typedef NSInteger SIMAgoraMediaStyle;

// Session 类型
typedef NS_ENUM(NSInteger, SIMSessionType)
{
    SIMSessionTypeSingleChat = 1,           //个人聊天
    SIMSessionTypeGroupChat = 2,            //群组聊天
    SIMSessionTypeSystem = 3,               //系统消息
    SIMSessionTypePublicChat = 5,           //公众号
    SIMSessionTypeOnlineServiceChat = 6,    //在线客服
    SIMSessionTypeVoiceChat = 7,    //声聊消息
    SIMSessionTypeEncryptChat = 10,    //加密消息
    SIMSessionTypeNewFriendRequest = 101,   //加好友通知
    SIMSessionTypeFileAssistant = 102,      //文件助手
    SIMSessionTypeGroupNotify = 201,        //群消息
    SIMSessionTypeTransfer = 301,           //转账到账通知(aa收款，二维码收付款到账)
    SIMSessionTypeRecharge = 302,           //充值成功
    SIMSessionTypeMessageRemind = 355,      //消息提醒
    SIMSessionTypeNews = 399,               //新闻
};

// 控制类数据返回成功失败及其他原因
typedef enum : NSUInteger {
    ControlRequestTypeFail,//失败
    ControlRequestTypeSuccess,//成功
    ControlRequestTypeFailReason1,//失败原因1
    ControlRequestTypeFailReason2,//失败原因2
    ControlRequestTypeFailReason3,//失败原因3
    ControlRequestTypeFailReason4,//失败原因4
    ControlRequestTypeFailReason5,//失败原因5
    ControlRequestTypeComplete,//认证完成
    ControlRequestTypeHandle,//认证审核中
    ControlRequestTypeNone,//未认证
    ControlRequestTypeNetWork,//网络问题
    ControlRequestType_601,//尚未授权，需要重新登录
    ControlRequestType_602,//指纹验证变动
} ControlRequestType;

typedef NS_ENUM(NSInteger, FriendType) {
    FriendTypeIsMyFriend    = 1, //是我的朋友
    FriendTypeIsNotMyFriend = 2, //不是朋友,陌生人
    FriendTypeIsMyself      = 3,  // 是自己
    FriendTypeIsLife        = 4,  // life进入
    LifeHomePhotoList       = 5
};

typedef enum : NSUInteger {
    SIMMessageSendSelectTypeGroupLinkShare,//分享群组链接不需要直接跳转到聊天，且有需要提示
    SIMMessageSendSelectTypeOther,//其他选择 如转发消息等
    SIMMessageSendSelectTypeFile,//分享系统图片视频文件等
} SIMMessageSendSelectType;

typedef enum : NSInteger {
    SIM_OtherPeople = 0,//其他人
    SIM_PGLife,//PGLife
    SIM_OtherAPP ,//其他应用
    SIM_SaveAlbum,// 保存相册
    SIM_Facebook,// Facebook
    SIM_Instagram,// Instagram
    SIM_Line,// Line
    SIM_copyUrl,// 複製連結
} SIMShareType;

typedef enum : NSUInteger {
    SIMLiveRoleBroadcaster,// 主播
    SIMLiveRoleAudience,// 观众
    SIMLiveRoleHelp,// 小帮手
} SIMLiveRole;


typedef enum : NSUInteger {
    SIMAgoraMultiplayerIdentityMaster,
    SIMAgoraMultiplayerIdentityInvite,
    SIMAgoraMultiplayerIdentityOther,
} SIMAgoraMultiplayerIdentity;

typedef enum : NSUInteger {
    SIMStorageVerificationType_Register,//注册
    SIMStorageVerificationType_ForgetPwd,//忘记密码
    SIMStorageVerificationType_FindPwd,//更改密码
    SIMStorageVerificationType_SetPayPwd,//设定钱包密码
    SIMStorageVerificationType_FindPayPwdr,//更改钱包密码
    SIMStorageVerificationType_FindNumber,//更換電話號碼
    SIMStorageVerificationType_setChatLockPwd,//设置聊天室密码
    SIMStorageVerificationType_setChatDestroyPwd,//设置聊天室销毁密码
    SIMStorageVerificationType_setAppLockPwd,//设置應用程式密碼
    SIMStorageVerificationType_findAppLockPwd,//修改應用程式密碼
    SIMStorageVerificationType_findVerifyAppLockPwd,//修改應用程式密碼解锁时使用
} SIMStorageVerificationType;

typedef enum : NSUInteger {
    SIMWalletPayType_Normal,//其他
    SIMWalletPayType_Lalamove,//lalamove服務費
    SIMWalletPayType_LalamoveTips,//lalamove小費
    SIMWalletPayType_Pray,//祈福
    SIMWalletPayType_Taxi,//大車隊
} SIMWalletPayType;

#endif /* SIMEnumClass_h */
