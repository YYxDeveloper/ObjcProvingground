//
//  SIMInterface.h
//  SAMIM
//
//  Created by   on 2018/9/29.
//  Copyright © 2018年  . All rights reserved.
//

#ifndef SIMInterface_h
#define SIMInterface_h

//以下4个环境只能打开一个
#ifdef TESTENV
#define TestEnvironment         //测试环境
#elif SIMENV
#define SimProductEnvironment   //仿真环境
#elif DEVDEBUGENV
#define DevelopmentEnvironment  //开发环境
#else
#define ProductEnvironment      //正式环境
#endif


//是否启用AirShip推送
//#define AirShipPush

//是否不再使用极光推送和Voip,后台直推
//#define NoJiGuangPush

#if defined(TestEnvironment) //测试环境

//声网   APPID
//#define AppKey_AgoraAppID           @"97697848b6d64e9e96b31b851ec0f856"
// 測試 appid
#define AppKey_AgoraAppID           @"0531a2f66e92499e8ef6aa71fd934623"


//2021年06月25日14
#define HostUrlStr                  @"https://cs.pgtalk.com"//专业版地址

//#define HostUrlStr                  @"http://47.241.14.123/wmsMobilePro"//专业版地址

// webview拼
#define PHPHostUrlStr               @"https://cs.pgtalk.com/wap"

// 定义域名
#define HostServerUrl               @"https://cs.pgtalk.com"

#define socketHostURL               @"https://cs.pgtalk.com:9092"

//公众号
#define PublicNoHostServerUrl       @"https://cs.pgtalk.com"

//pg更新
#define deskey @"pgtalk168"

#define carddeskey @"PGTalkCreditCard@1688"

#define kGoogleBaseUrl @"https://gcdn.pgtalk.com"

#define kGooglebucketUrl @"pgtalk-tw-cs"

#elif defined(ProductEnvironment) //正式环境

//声网   APPID
#define AppKey_AgoraAppID           @"9b012a6c59b342d1a1bf9ae2cac97839"
//https://chat.pgtalk.com/
//#define HostUrlStr                  @"https://hoadmin66.pgtalk.com/wmsMobilePro"//专业版地址
#define HostUrlStr                  @"https://meta.pgtalk.com"
// webview拼
#define PHPHostUrlStr               @"https://meta.pgtalk.com/wap"

// 定义域名
#define HostServerUrl               @"meta.pgtalk.com"

//公众号
#define PublicNoHostServerUrl       @"https://meta.pgtalk.com"

// https://sk.pgtalk.com:9093
#define socketHostURL               @"https://meta.pgtalk.com:9092"

//pg更新
#define deskey @"tQXOm3mb"

#define carddeskey @"PGTalkCreditCardProd@1688"

#define kGoogleBaseUrl @"https://gcdn.pgtalk.com"

#define kGooglebucketUrl @"pgtalk-tw"

#elif defined(DevelopmentEnvironment) //开发环境

//声网   APPID
#define AppKey_AgoraAppID           @"0531a2f66e92499e8ef6aa71fd934623"

//#define HostUrlStr                  @"http://192.168.1.23:8080/wmsMobilePro"//本地测试地址 志熊本地地址
#define HostUrlStr                  @"http://192.168.2.55"//本地测试地址  小胖本地地址

// webview拼
#define PHPHostUrlStr               @"http://192.168.2.55/wap"

//// 定义域名
#define HostServerUrl               @"192.168.2.55"

#define socketHostURL               @"http://192.168.2.55:9092"

//公众号
#define PublicNoHostServerUrl       @"http://192.168.2.55"

//pg更新

#define deskey @"pgtalk168"

#define carddeskey @"PGTalkCreditCard@1688"

#define kGoogleBaseUrl @"https://gcdn.pgtalk.com"

#define kGooglebucketUrl @"pgtalk-tw-cs"

#elif defined(SimProductEnvironment) //仿真环境

//声网   APPID
#define AppKey_AgoraAppID           @"a9fec2d61099411e954798500c16e736"

//#define HostUrlStr                  @"http://47.241.7.222/wmsMobilePro"//专业版地址
//#define HostUrlStr                  @"http://35.221.216.159"
#define HostUrlStr                  @"https://sim.pgtalk.com"

// webview拼
#define PHPHostUrlStr               @"https://sim.pgtalk.com/wap"

//// 定义域名
#define HostServerUrl               @"sim.pgtalk.com"

#define socketHostURL               @"https://sim.pgtalk.com:9092"

//公众号
#define PublicNoHostServerUrl       @"https://sim.pgtalk.com"

//pg更新
#define deskey @"pgtalk168"

#define carddeskey @"PGTalkCreditCard@1688"

#define kGoogleBaseUrl @"https://gcdn.pgtalk.com"

#define kGooglebucketUrl @"pgtalk-tw-fz"


#endif

//极光推送appkey
#define AppKey_JGPush               @"ad67346e37f92e957ddd8ac5"
//极光推送 MasterSecret
#define MasterSecret_JGPush         @"626531ddce8ef94fd447f77c"

#define URLAddress(key)    [NSString stringWithFormat:@"%@%@",HostUrlStr,key]

#define ErrorCode       -999999

//注册协议地址

#define kWAP_registDoc  @"/pgTalk-operation/common/registDoc"
#pragma mark - 登录注册相关
/***************************************** 登录注册相关 ************************************/
//登录
#define kApi_doLogin_Path                          @"/pgTalk-user/loginAuth/doLogin"
//刷新token
#define kApi_refreshToken_Path                      @"/pgTalk-user/loginAuth/refreshToken"
//找回密码
#define kApi_FindPassword_Path                     @"/pgTalk-user/loginAuth/findPwd"
//根据手机号码获取验证码 有滑块
#define kApi_AcquireCode_Path                      @"/pgTalk-user/chat/getValidateNum"
//发送验证码不验证滑块
#define kApi_SendCaptcha_Path                      @"/chat/sendCaptcha"

///推荐注册页面  /pgTalk-user/loginAuth/register
//用户注册
#define kApi_UserRegister_Path                     @"/pgTalk-user/loginAuth/registration"//@"/chat/register"
//第三方登录
#define kApi_ThirdPartLogin_Path                   @"/pgTalk-user/loginAuth/otherLogin"
//更改手机号码
#define kApi_ThirdPartLoginUpdateMobile_Path       @"/pgTalk-user/chat/updateMobile"
//第三方登录解除绑定
#define kApi_ThirdPartLoginUnbindMobile_Path       @"/pgTalk-user/chat/unbindOtherLogin"
// 賬號註銷
#define kApi_User_AccountLogout      @"/pgTalk-user/user/accountLogout"
//獲取上傳阿里雲憑證
#define kApi_uploadALiYunToken_Path            @"/pgTalk-user/upload/aLiYunToken"

/// 查询手机号是否已经注册
#define kApi_UserIsRegister_Path                    @"/pgTalk-user/loginAuth/userStatic"

/// 校验注册验证码
#define kApi_CheckValidateNum_Path                   @"/pgTalk-user/loginAuth/checkValidateNum"

/// 新注册
#define kApi_UserNewRegister_Path                   @"/pgTalk-user/loginAuth/registration_new"

//国家区号
#define kApi_commonGetAreaPath @"/pgTalk-operation/common/getArea"

//点击金砖登录调用
#define kApi_jzAuthLoginPath @"/pgTalk-third/api/jz/jzAuthLogin"

//金砖登录回调
#define kApi_getUserInfoPath @"/pgTalk-third/api/jz/getUserInfo"

// 邀请好友二维码
//#define kApi_downloadUrlPath    @"/downloadUrl"
#define kApi_downloadUrlPath    @"/pgTalk-user/user/createRecommendUrl"

//是否商家
#define kApi_walletIsBusiness   @"/pgTalk-user/business/isBusiness"//@"/wallet/isBusiness"


//推荐活动
#define KApi_recommendActivityCollect  @"/pgTalk-activity/recommendActivity/activityCollect"

//推荐活动明细
#define KApi_recommendActivityStatistics  @"/pgTalk-activity/recommendActivity/recommendActivityStatistics"

//结账记录
#define kApi_walletWithdrawRecord @"/pgTalk-finance/wallet/withdrawRecord"

// 第三方授權相關
#define kApi_authApi_authCode  @"/pgTalk-third/application/authCode"  //@"/authApi/authCode"
// app授權碼
#define kApi_authApi_generateAuthCode  @"/pgTalk-third/application/generateAuthCode"

// 获取实名认证信息
#define kApi_user_getUserAuth   @"/pgTalk-user/user/getUserAuth"
// 实名认证并绑定银行卡
#define kApi_user_realAuthBindBankCard    @"/pgTalk-user/user/realAuthBindBankCard"

//提现选择币种初始化
#define kApi_walletGetMainPath  @"/pgTalk-third/wallet/getMain"
 
////更新接口
//#define kApi_updatePGTalkAppPath @"/common/updatePGTalkApp"
 
//在登陆成功后，发送ready接口到，这时先发送ready接口,，些接口会返回，好友信息，群组信息。
#define kApi_Ready_Path                            @"/pgTalk-user/chat/ready"
//当ready数据处理完成时发送，确认消息
#define kApi_ConfirmReady_Path                     @"/chat/confirmReady"

//推荐好友
#define kApi_RecommendFriend_Path                  @"/pgTalk-friend/recommendFriend/friendList"
/// 好友邀請
#define kApi_FriendRequest_Path                  @"/pgTalk-friend/friendRequest/list"
/// 刪除好友邀請
#define kApi_DelFriendRequest_Path                  @"/pgTalk-friend/friendRequest/del/"
/// 刪除所有好友邀請
#define kApi_DelAllFriendRequest_Path                  @"/pgTalk-friend/friendRequest/delAll"
/// 好友邀請數量
#define kApi_CountInviteFriendRequest_Path                  @"/pgTalk-friend/friendRequest/count"
//添加好友
#define kApi_addRecommendFriend_Path                        @"/pgTalk-friend/recommendFriend/requestFriend"
//跳过好友
#define kApi_jumpRecommendFriend_Path                       @"/pgTalk-friend/recommendFriend/skipFriend"
#pragma mark - 消息
/***************************************** 消息 ****************************************/

//设置消息免打扰信息
#define kApi_SetMessageIsDisturb_Path              @"/pgTalk-group/chat/setIgnore"
//上传图片
#define kApi_UploadImage_Path                      @"/blade-resource/oss/endpoint/put-file"//@"/chat/uploadImage" //2021年06月26日
//上传文件
#define kApi_Chat_doUploads_Path                   @"/chat/doUploads"
//红包历史记录
#define kApi_RedpacketHistoryRecord_Path           @"/pgTalk-finance/chat/getRedPacketHistory"
//红包发送
#define kApi_RedpacketSend_Path                    @"/pgTalk-finance/chat/sendRedPacketNew"
//#define kApi_RedpacketSend_Path                    @"/pgTalk-finance/chat/sendRedPacket"

//红包打开
#define kApi_RedpacketOpen_Path                    @"/pgTalk-finance/chat/openRedPacket"
//聊天置顶
#define kApi_SessionSetTop_Path                    @"/pgTalk-user/chat/setTop"
//置顶取消
#define kApi_SessionCancleTop_Path                 @"/pgTalk-user/chat/cancleTop"
//查询聊天历史记录
#define kApi_GetMsgHistoryp_Path                   @"/chat/getMsgHistory"
//查询转账状态
#define kApi_TransferStatus_Path                   @"/pgTalk-finance/transfer/viewTransfer"
//确认收钱
#define kApi_TransferConfimTransfer_Path           @"/pgTalk-finance/transfer/confimTransfer"
//转账给好友
#define kApi_TransferCreateTransfer_Path           @"/pgTalk-finance/transfer/createTransferNew"
// 用户转账配置
#define kAPI_TransferConfig_Path @"/pgTalk-finance/transfer/transferConfig"
///   /pgTalk-finance/transfer/createTransfer
//修改群名称
#define kApi_UpdateGroupName_Path                  @"/pgTalk-group/chat/updateGroup"
//修改群成员名称
#define kApi_UpdateGroupMemberMark_Path            @"/pgTalk-group/chat/updateGroupMemberMark"
//收藏功能，添加收藏
#define kApi_MessageAddFavorite_Path               @"/pgTalk-user/favorite/addFavorite"
//收藏功能，获取我的收藏列表
#define kApi_MessageGetFavorite_Path               @"/pgTalk-user/favorite/getFavorite"
//收藏功能，取消收藏
#define kApi_MessageDelFavorite_Path               @"/pgTalk-user/favorite/delFavorite"
//添加群公告
#define kApi_CreateGroupNote_Path                  @"/pgTalk-group/chat/createGroupNote"
//编辑群公告
#define kApi_UpdateGroupNote_Path                  @"/pgTalk-group/chat/updateGroupNote"
//群公告列表
#define kApi_GetNoteList_Path                      @"/pgTalk-group/chat/getNoteList"
//删除群公告
#define kApi_DeleteGroupNote_Path                  @"/pgTalk-group/chat/deleteGroupNote"
//设置群管理员
#define kApi_GroupSetAdmin_Path                    @"/pgTalk-group/chat/setGroupAdmin"
//编辑群简介
#define kApi_GroupUpdateDesc_Path                  @"/pgTalk-group/chat/updateGroupDesc"
//設置群公開
#define kApi_GroupPublicSearch                     @"/pgTalk-group/chat/updateGroupIsPublicSearch"
//搜索公開群
#define kApi_GroupGetPublicGroup                   @"/pgTalk-group/chat/getPublicGroup"

//AA收款详情
#define kApi_AATransDetail_Path                    @"/pgTalk-finance/transfer/aaTransDetail"
//发起AA收款
#define kApi_AATransCreate_Path                    @"/pgTalk-finance/transfer/aaTrans"
//支付AA收款
#define kApi_AATransPay_Path                       @"/pgTalk-finance/transfer/aaTransPay"
//消息提醒
#define kApi_MessageReminding_Path                 @"/pgTalk-user/user/setMsgAlert"
//获取服务器消息
#define kApi_MessageGetCloudMessage_Path           @"/pgTalk-user/chat/getCloudMessage"
//删除服务器消息
#define kApi_MessageCleanCloudMessage_Path         @"/pgTalk-user/chat/cleanSessionMessage"
//阅后即焚
#define kApi_MessageUpdateMessageFired_Path        @"/pgTalk-user/chat/updateMessageFired"
//删除单条消息
#define kApi_MessageDelMessage_Path                @"/pgTalk-user/chat/delMessage"
//查询红包开启状态
#define kApi_GetPacketStatus_Path                 @"/pgTalk-finance/chat/getPacketStatus"
//查询会话所有消息
#define kApi_GetAllCloudMessage_Path                 @"/chat/getAllCloudMessage"

//群组阅后即焚开关
#define kApi_GroupupdateGroupSnapchat              @"/pgTalk-group/chat/updateGroupSnapchat"
//更新截屏通知开关
#define kApi_GroupupdateGroupScreen                @"/pgTalk-group/chat/updateGroupScreen"

//call是否接听
#define kApi_IfReceive  @"/pgTalk-third/sendMsgApi/ifReceive"
/// 发送消息/pgTalk-third/sendMsgApi/sendMsg // 发送语音拒绝消息 /pgTalk-third/sendMsgApi/sendVoiceRejectionMsg
#pragma mark - 联系人
/***************************************** 联系人 *************************************/
//获取个人群全部成员详细信息
#define kApi_AcquireGroupMembers_Path              @"/pgTalk-group/chat/getGroupMember"
//获取个人群某个成员详细信息
#define kApi_AcquireGroupMemberById_Path           @"/pgTalk-group/chat/getGroupMemberById"
//添加群成员
#define kApi_AddGroupMemeber_Path                  @"/pgTalk-group/chat/addGroupMember"
//创建群组
#define kApi_CreateGroup_Path                      @"/pgTalk-group/chat/createGroup"
//退出私人群
#define kApi_QuitGroup_Path                        @"/pgTalk-group/chat/quitGroup"
//解散私人群
#define kApi_DissolveGroup_Path                    @"/pgTalk-group/chat/dismissGroup"
//转让私人群
#define kApi_TransGroup_Path                       @"/pgTalk-group/chat/transGroup"
//转让私人群确认
#define kApi_TransGroupConfirm_Path                @"/pgTalk-group/chat/transGroupConfirm"
//根据id获取群信息
#define kApi_GetGroupById_Path                     @"/pgTalk-group/chat/getGroupById"
//申请加好友，或者申请加入群
#define kApi_AddFriend_Path                        @"/pgTalk-friend/chat/requestFriend"
//删除好友
#define kApi_DelFriend_Path                        @"/pgTalk-friend/chat/delFriend"
//同意加好友或者加群
#define kApi_AcceptFriend_Path                     @"/pgTalk-friend/chat/acceptRequest"
//创建好友分组
#define kApi_createFriendGroup_Path                @"/chat/createFriendGroup"
//查找用户
#define kApi_queryUser_Path                        @"/pgTalk-user/chat/queryUser"
//通过用户id查询资料
#define kApi_queryUserById_Path                    @"/pgTalk-friend/chat/getUserById"
//查找群组
#define kApi_queryGroup_Path                       @"/pgTalk-group/chat/queryGroup"
////同意对方加群 同意对方加好友 重复!!!!!!
//#define kApi_AcceptFriend_Path                     @"/chat/acceptRequest"
//加入黑名单
#define kApi_SetBlock_Path                         @"/pgTalk-friend/chat/setBlock"
//移出黑名单
#define kApi_RemoveBlack_Path                      @"/pgTalk-friend/chat/removeBlack"
//黑名单列表
#define kApi_GetBlackList_Path                     @"/pgTalk-friend/chat/getBlackList"
//修改备注/chat/updateRemark
#define kApi_UpdateRemark_Path                     @"/pgTalk-friend/chat/updateRemark"
//设置群头像
#define kApi_SetGroupHeader_Path                   @"/pgTalk-group/chat/setGroupHeader"
//设置朋友圈权限
#define kApi_SetFeedAuth_Path                      @"/pgTalk-feed/feed/setFeedAuth"


//添加好友标签(设置某个好友的标签)
#define kApi_AddFriendMark_Path                    @"/pgTalk-friend/chat/addFriendMark"
//添加标签
#define kApi_AddMark_Path                          @"/pgTalk-friend/chat/addMark"
//添加标签好友（某个标签添加好友）
#define kApi_AddFriendToMark_Path                  @"/pgTalk-friend/chat/addFriendToMark"
//修改标签
#define kApi_UpdateMark_Path                       @"/pgTalk-friend/chat/updateMark"
//移除标签
#define kApi_RemoveMark_Path                       @"/pgTalk-friend/chat/removeMark"
//移除标签好友
#define kApi_RemoveMarkFriend_Path                 @"/pgTalk-friend/chat/removeMarkFriend"
//获取用户的标签
#define kApi_UserMark_Path                         @"/pgTalk-friend/chat/userMarks"
//获取标签成员
#define kApi_UserMarkFriend_Path                   @"/pgTalk-friend/chat/userMarkFriend"
//获取好友标签列表
#define kApi_UserFriendMark_Path                   @"/pgTalk-friend/chat/userFriendMark"
//好友设置星标
#define kApi_UserSetStarFriend_Path                @"/pgTalk-friend/user/setStarFriend"
//变更好友阅后即焚状态
#define kApi_UserUpdateFriendSnapchat_Path         @"/pgTalk-friend/chat/updateFriendSnapchat"
//变更好友截屏通知状态
#define kApi_UserUpdateFriendScreent_Path          @"/pgTalk-friend/chat/updateFriendScreen"

///// 消息免打扰 /pgTalk-group/chat/setIgnore
#pragma mark - 个人
/****************************************** 个人 *****************************************/
#define kApi_SetMessageIsDisturb_PersonUrl              @"/pgTalk-friend/chat/setIgnore"
//更改用户信息
#define kApi_SetUserInfo_Path                      @"/pgTalk-user/chat/updateProfile"
//修改隐私设置
#define kApi_SetPrivateSetting_Path                @"/pgTalk-user/chat/updatePrivateSetting"
//修改隐私设置开启粉丝权限
#define kApi_SetPrivateFansShow_Path                @"/pgTalk-user/chat/updateUserIsFansShow"
//更新用户头像
#define kApi_UploadUserIcon_Path                   @"/pgTalk-user/chat/updateHead"
//查询余额
#define kApi_GetBalance_Path                       @"/pgTalk-finance/wallet/getBalance"
//查询资金详情
#define kApi_WalletDetail_Path                     @"/pgTalk-finance/wallet/walletDetail"
//查询账单
#define kApi_GetWalletHistory_Path                 @"/pgTalk-finance/wallet/getWalletHistory"
//获取直播账单
#define kApi_GetLiveWalletHistory_Path                 @"/pgTalk-finance/wallet/getLiveWalletHistory"

// 获取消费可退款列表
#define kApi_GetWalleConsumer                      @"/pgTalk-finance/consumer/consumerRecord"
// 退款
#define kApi_consumerRefund                        @"/pgTalk-finance/consumer/consumerRefund"
// 退款记录
#define kApi_consumerRefundList                    @"/pgTalk-finance/consumer/consumerRefundRecord"

//实名认证
#define kApi_UpdateAuth_Path                       @"/pgTalk-user/user/updateAuth"
//实名认证检测
#define kApi_AuthCheck_Path                        @"/user/authcheck"
//获取实名认证
#define kApi_AuthGetUserAuth_Path                        @"/chat/getUserAuth"


//设置或更新支付密码
#define kApi_SetPayPwd_Path                        @"/pgTalk-user/pay/setPayPwd"
//远程校验支付密码
#define kApi_ValidatePayPwd_Path                   @"/pgTalk-user/pay/validatePayPwd"
// 设置生物识别密码
#define kAPI_SetBioCodePwd                         @"/pgTalk-user/pay/setBioCode"
//充值
//#define kApi_CreateRechargeOrder_Path              @"/wallet/createRechargeOrder"

//充值
#define kApi_CreateRechargeOrder_Path @"/pgTalk-third/wallet/recharge"

//取消充值
#define kApi_CancelOrder_Path                      @"/wallet/cancelOrder"
//投诉
#define kApi_ChatReport_Path                       @"/chat/report"
//功能介绍
//#define kApi_FunctionalIntroduction_Path           @"https://pro.huiwork.com/wap/version/historys"
#define kApi_FunctionalIntroduction_Path           [NSString stringWithFormat:@"%@/version/historys",PHPHostUrlStr]

//变更用户戳一戳通知开关
#define kApi_UpdateSettingRock_Path                @"/pgTalk-user/chat/updateSettingRock"

/*************  后需添加的接口
 *********************/

////检测实名认证状态 /user/authcheck
//#define kApi_AuthCheck_Path                        @"/user/authcheck"

//用户账户余额更新
//#define kApi_WalletUpdate_Path                     @"/user/walletupdate"

//用户账户余额更新
#define kApi_WalletUpdate_Path @"/pgTalk-finance/wallet/withdraw"
//附近商户
#define kApi_geoFindNearbyBusiness_Path   @"/pgTalk-user/geo/findNearbyBusiness"
//附近商家 范围内全部
#define kApi_nearbyBusinessMap_Path   @"/pgTalk-user/business/nearbyBusinessMap"

//用户充值接口
#define kApi_AppPay_Path                           @"/app/pay.php"
//用户手机列表
#define kApi_ImportPhone_Path                      @"/pgTalk-user/chat/inviteContact"
//Paypal用户充值订单生成
#define kApi_PayPal_Path                           @"/user/paypal"

//微信二维码支付登陆接口
#define kApi_WChatLogin_Path                      @"/app/login"
//获取微信支付二维码
#define kApi_WChatGetPayCode_Path                 @"/app/getPayCodeUrl"
//检测版本更新
#define kApi_CheckVersion_Path                    @"/pgTalk-operation/version/getVersion"

//获取微信项目列表接口
#define kApi_WChatGetAppList_Path                 @"/app/getAppList"
//保存微信的订单信息
#define kApi_WChatSaveOrder_Path                  @"/user/wxorders"
//设置短信推荐人关系
#define kApi_Setrefer_Path                        @"/user/setrefer"
//通过注册手机号获取推荐人id
#define kApi_Getrefer_Path                        @"/user/getrefer"
//用户摇一摇
#define kApi_UserRock_Path                        @"/geo/findRandom"
//查询摇一摇历史记录
#define kApi_GetRockRecord_Path                   @"/geo/getRockRecord"
//清除摇一摇历史记录
#define kApi_RemoveRockRecord_Path                @"/geo/removeRockRecord"
//清除打招呼的人
#define kApi_RemoveRockMessage_Path               @"/geo/removeRockMessage"
//打招呼的人列表
#define kApi_RockGreetList_Path                   @"/geo/greetList"
//打招呼
#define kApi_RockSendGreet_Path                   @"/geo/sendGreet"
//查找附近的人
#define kApi_FindNearby_Path                      @"/pgTalk-user/geo/findNearby"
//更新当前位置
#define kApi_UpdateGeo_Path                       @"/pgTalk-user/geo/updateGeo"
//清除定位位置
#define kApi_ClearLocation_Path                   @"/pgTalk-user/geo/clearLocation"

#pragma mark - 群组
#define kApi_GroupInvite_Path                   @"/pgTalk-group/groupRequest/list"
#define kApi_GroupRemoveInvite_Path                   @"/pgTalk-group/groupRequest/remove"


#pragma mark - 设置
/*************  设置 *********************/
//钱包---发起收款，返回json用于生成收款二维码
#define kApi_CreateReceipt_Path                    @"/pgTalk-finance/transfer/createReceipt"
//钱包---发起付款，返回json用于生成收款二维码
#define kApi_CreatePayment_Path                    @"/pgTalk-finance/transfer/createPayment"
//钱包---扫了收款人二维码后，进行付款请求
#define kApi_PostPayment_Path                      @"/pgTalk-finance/transfer/postPayment"
//绑定银行卡
#define kApi_BankBindingCard_Path        @"/pgTalk-user/bankCard/bindingCard"//@"/wallet/bindingCard"
//绑定银行卡列表(旧)
#define kApi_CardList_Path           @"/pgTalk-user/bankCard/bankList"//@"/wallet/getCardList"
//绑定银行卡列表(新)
#define kApi_BankCardList_Path          @"/pgTalk-user/bankCard/getBankCardList"// @"/wallet/getBankCardList"
//解除绑定银行卡
#define kApi_BankDissCardList_Path       @"/pgTalk-user/bankCard/dissCard"
//设置默认银行卡
#define kApi_BankDefaultCard_Path        @"/pgTalk-user/bankCard/setDefaultBankCard"
//删除银行卡
#define kApi_BankRemoveCard_Path         @"/pgTalk-user/bankCard/removeBank"
//汇款银行卡列表
#define kApi_BankTransfer_Path @"/pgTalk-finance/linerecharge/transferBankList"
//意见反馈
#define kApi_FeedBackSubmit_Path         @"/feedback/feedback_submit"
///银行卡列表 /pgTalk-user/bankCard/bankList
//获取靓号分类
#define kApi_GetNumberType_Path          @"/pay/getNumberType"
//获取获取靓号
#define kApi_GetVipNumber_Path           @"/pay/getVipNumber"
//支付靓号购买
#define kApi_CreateNumberOrder_Path      @"/pay/createNumberOrder"
//检测靓号状态
#define kApi_CheckIMNumberStatus_Path            @"/pay/checkNumber"
//開啓勿擾模式
#define kApi_TurnOnDoNotDisturb_Path            @"/pgTalk-user/chat/isTurnOnDoNotDisturb"
#pragma mark - 朋友圈
/*************  后需添加的接口---朋友圈       部分 *********************/
//朋友圈分享
#define FriendShareAdd       @"/pgTalk-feed/feed/addFeed"
//朋友圈更新貼文
#define FriendUpdateLife       @"/pgTalk-feed/feed/updateLife"
//朋友圈，我自己的相册
#define FriendGetMyFeed      @"/pgTalk-feed/feed/getMyFeed"
//好友的朋友圈列表
#define FeedGetFriendFeed      @"/pgTalk-feed/feed/getFriendFeed"
// 朋友圈照片墙
#define FeedPhotoWall  @"/pgTalk-feed/feed/photoWall"
// 获取朋友的朋友圈详情
#define FeedFeedDetail  @"/pgTalk-feed/feed/getFeedDetail"
// 根據朋友圈ID獲取評論用戶
#define FeedCommentList  @"/pgTalk-feed/feed/getFeedCommentList"

//朋友圈，获取陌生人的朋友圈动态列表
#define FriendGetStranger    @"/pgTalk-feed/feed/getFriendFeed"
//朋友圈动态列表
#define FriendShareList      @"/pgTalk-feed/feed/getFeed"
//朋友圈点赞列表
#define kFriendPraiseList      @"/pgTalk-feed/feed/getPraiseUserList"

//朋友圈动态点赞
#define FriendSharePraise    @"/pgTalk-feed/feed/addFeedPraise"
//取消动态点赞
#define FriendShareCanclePraise    @"/pgTalk-feed/feed/canclePraise"
//朋友圈动态删除
#define FriendShareDelete    @"/pgTalk-feed/feed/deleteFeed"
//朋友圈动态评论
#define FriendShareReply     @"/pgTalk-feed/feed/addFeedComment"
//动态详情
#define FriendShareDetail    @"/pgTalk-feed/feed/getOneFeed"
//朋友圈封面设置
#define FriendShareSetCover  @"/pgTalk-user/feed/changeBackImage"
//获取朋友圈封面
#define FriendGetBackImage   @"/pgTalk-user/feed/getBackImage"
//朋友圈查看好友动态
#define FriendShareUserList  @"/share/userlist"
//朋友圈，查看好友或群成员个人资料时，里面的相册预览
#define FriendGetFeedAlbum   @"/pgTalk-feed/feed/getFeedAlbum"
//根据时间筛选
#define SearchFriendShareList     @"/pgTalk-feed/feed/searchFeed"
//朋友圈赠送礼物
#define FriendShareSendGift     @"/feed/sendFeedGift"
//朋友圈收到礼物列表
#define FriendShareGiftList     @"/feed/myGift"
//朋友圈删除自己的评论
#define FriendShareDelFeedComment     @"/pgTalk-feed/feed/delFeedComment"
// 朋友圈屏蔽動態或者用戶
#define FriendSharehHiddenFeed     @"/pgTalk-feed/feed/shield"
// 朋友圈解除屏蔽用戶
#define FriendSharehRemoveBlack    @"/pgTalk-feed/feed/removeBlack/"
// 是否屏蔽用戶
#define FriendSharehIsBlack     @"/pgTalk-feed/feed/isBlack/"
// 朋友圈分享數量
#define FriendShareCount     @"/pgTalk-feed/feed/share/"

#pragma mark - php——接口（手动加前缀 php_api）
/*************  php——接口（手动加前缀 php_api） *********************/
//php前缀
#define phpPrefix                                  @"php_api"
//设置聊天背景
#define kApi_SetChatBg_Path                        @"php_api/chat/setChatBg"
//转文字地址
#define VoiceTureTextAddress @"/chat/speech"

#pragma mark - 群组项目新加
/******************  群组项目新加  *********************/
//删除群成员
#define kApi_RemoveGroupMember_Path                @"/pgTalk-group/chat/removeGroupMember"
//申请加入群组
#define kApi_RequestGroupJoin_Path                 @"/pgTalk-group/chat/requestGroupJoin"
///未使用 /pgTalk-group/chat/requestGroup
//更新加群验证
#define kApi_UpdateJoinstatus_Path                 @"/pgTalk-group/chat/updateJoinstatus"
//升级群
#define kApi_PayForGroupLevel_Path                 @"/chat/payForGroupLevel"
//支付加群
#define kApi_PayForGroupJoin_Path                  @"/pgTalk-group/chat/payForGroupJoin"
//获取群等级配置
#define kApi_QueryGroupConfig_Path                 @"/pgTalk-group/chat/queryGroupConfig"
//审核群成员/更新群成员禁言状态
#define kApi_UpdateGroupMember_Path                @"/pgTalk-group/chat/updateGroupMember"
//群续费
#define kApi_PayForGroupExt_Path                   @"/chat/payForGroupExt"

//绑定信鸽token
#define kApi_BindXgToken_Path                      @"/chat/bindXgToken"

//设置fcn  token
#define kApi_BindFmcToken_Path                      @"/pgTalk-user/chat/bindFmcToken"

//绑定voipToken
#define kApi_BindVoipToken_path                     @"/pgTalk-user/chat/bindVoipToken"

// 授权登录
#define kApi_PCAuthLogin_Path                      @"/pc/authLogin"

// 查询二维码信息
#define kApi_PCQueryCode_Path                      @"/pc/queryCode"

// 生成推荐分享链接
#define kApi_CreateRecommendLink_Path              @"/user/createRecommendLink"
//开通会员
#define kApi_SettingLeaguerOpenVipMember_Path      @"/user/openVipMember"
//查询会员充值记录
#define kApi_SettingLeaguerGetVipLogList_Path      @"/user/getVipLogList"
//在线客服
#define kApi_SettingOnlineServiceList_Path      @"/chat/getService"

#pragma mark - 短视频
/******************  短视频  *********************/
// 发布短视频
#define kApi_VideoPublish_Path                     @"/video/publish"
// 发表评论
#define kApi_VideoAddComment_Path                  @"/video/addComment"
// 删除评论
#define kApi_VideoRemoveComment_Path               @"/video/removeComment"
// 获取短视频列表
#define kApi_VideoGetVideos_Path                   @"/video/getVideos"
// 获取短视频评论列表
#define kApi_VideoGetVideoComment_Path             @"/video/getVideoComment"
// 获取短视频详情
#define kApi_VideoGetVideoInfo_Path                @"/video/getVideoInfo"
// 视频点赞
#define kApi_VideoAddPraise_Path                   @"/video/addPraise"
// 视频取消赞
#define kApi_VideoRemovePraise_Path                @"/video/removePraise"
// 删除视频
#define kApi_VideoRemove_Path                      @"/video/remove"

#pragma mark - 气泡
/******************  气泡  *********************/
// 设置气泡
#define kApi_SetMsgSkin_Path                      @"/pgTalk-user/user/setMsgSkin"

#pragma mark - 公众号
/******************  公众号  *********************/
// 公众号搜索
#define kApi_PublicSearch_Path                      @"/imPublic/publicSearch"
// 公众号详情
#define kApi_PublicGetInfo_Path                     @"/imPublic/getInfo"
// 关注公众号
#define kApi_AddPublic_Path                         @"/imPublic/addPublic"
// 取消关注公众号
#define kApi_CancelPublic_Path                      @"/imPublic/cancelPublic"
// 用户关注的公众号列表
#define kApi_GetPublicUserList_Path                 @"/imPublic/getPublicUserList"
// 用户关注的公众号列表
#define kApi_GetFuncReturn_Path                     @"/imPublic/funcReturn"
// 消息存储
#define kApi_SaveMessage_Path                       @"/pub/saveMessage"

/******************  声网  *********************/
//该方法查询指定频道内的分角色用户列表
#define kApi_AgoraHostUrl_USER @"https://api.agora.io/dev/v1/channel/user"
// 查询用户状态
#define kApi_AgoraHostUrl_USER_PROPERTY @"https://api.agora.io/dev/v1/channel/user/property"
/******************  群组聊天机器人  *********************/
//开启机器人
#define kApi_RobotOpen_Path                         @"/pgTalk-group/robot/openRobot"
//关闭机器人
#define kApi_RobotClose_Path                        @"/pgTalk-group/robot/closeRobot"
//获取群组可设置欢迎语列表
#define kApi_RobotGetWelcomeList_Path               @"/pgTalk-group/robot/getWelcomeList"
//设置群组欢迎语
#define kApi_RobotSetWelcome_Path                   @"/pgTalk-group/robot/setWelcome"
//取消群组欢迎语
#define kApi_RobotCancelWelcome_Path                @"/pgTalk-group/robot/cancelWelcome"
//群组全部禁言 0关闭全部禁言 1开启全部禁言
#define kApi_GroupUpdateSilence_Path                @"/pgTalk-group/chat/updateGroupSilence"
//群主消息置顶0关闭 1开启
#define kApi_GroupUpdateMsgtop_Path                 @"/pgTalk-group/chat/updateGroupMsgtop"
//变更群成员拉人是否需要审核
#define kApi_GroupUpdateInivteAuth_Path             @"/pgTalk-group/chat/updateGroupInivteAuth"

///群组成员查看资料状态 /pgTalk-group/chat/updateGroupMemViewStatus
//查询退群成员列表
#define kApi_GroupGetMemberOut_Path                 @"/pgTalk-group/chat/getGroupMemberOut"
//群主获取群组未领取的红包信息
#define kApi_GroupGetRedPacket_Path                 @"/pgTalk-finance/chat/getGroupRedPacket"
//获取群组不活跃列表
#define kApi_GroupGetStatistics_Path                @"/chat/getGroupStatistics"
//更新群组活跃度统计
#define kApi_GroupUpdateStatistics_Path             @"/chat/updateGroupStatistic"

//提交反馈
#define kApi_feedbackAppSave_Path               @"/pgTalk-operation/feedback/appSave"

//公告列表
#define kApi_announcementAnnouncementList_Path  @"/pgTalk-operation/announcement/announcementList"
//公告数量
#define kApi_announcementNum_Path  @"/pgTalk-operation/announcement/announcementNum"
//一键公告已读
#define kApi_announcementRead_Path  @"/pgTalk-operation/announcement/read"
//公告已读一条
#define kApi_announcementReadOne_Path  @"/pgTalk-operation/announcement/readOne"

//充值收款信息
#define kApi_linerechargeReceiveInfo_Path @"/pgTalk-finance/linerecharge/receiveInfo"

//充值记录
#define kApi_linerechargeRechargeRecord_Path @"/pgTalk-finance/linerecharge/rechargeRecord"

//充值提交
#define kApi_linerechargeSave_Path  @"/pgTalk-finance/linerecharge/save"
//未支付充值訂單
#define kApi_getUnpaidRechargeRecordId @"/pgTalk-finance/linerecharge/getUnpaidRechargeRecordId"

//允许附近人搜到我
#define kApi_chatUpdateUserNearbyShow_Path  @"/pgTalk-user/chat/updateUserNearbyShow"

//商家资料
#define kApi_geoBusinessDetail_Path @"/pgTalk-user/business/businessDetail"///@"/geo/businessDetail"
//優惠卷活動關聯商家
#define kApi_geoAvailableBusiness_Path @"/pgTalk-user/business/availableBusiness"

//修改商家资料
#define kApi_geoBusinessUpdate_Path  @"/pgTalk-user/business/businessUpdate"//@"/geo/businessUpdate"

//红包配置
#define kApi_chatRedPacketConfig_Path  @"/pgTalk-finance/chat/redPacketConfig"

//配置是否可以打开钱包
#define kApi_linerechargeReceiveFlag_Path  @"/pgTalk-finance/linerecharge/receiveFlag"


//请求抽奖活动是否开启
#define kApi_activityStartActivity_Path   @"/pgTalk-activity/activity/startActivity"
//请求抽奖
#define kApi_activityLottery_Path   @"/pgTalk-activity/activity/lottery"

//新抽奖接口
#define kApi_activityActivityPage_Path  @"/pgTalk-activity/activity/activityPage"



//抽奖活动已有币种
#define kApi_activityUserPrizeList_Path    @"/pgTalk-activity/activity/userPrizeList"

// 奖品列表
#define kApi_activityPrizeList_Path    @"/pgTalk-activity/activity/prizeList"

// 兑奖
#define kApi_activityExchange_Path     @"/pgTalk-activity/activity/exchange"


//兑奖记录
#define kApi_activityExchangeRecordList_Path @"/pgTalk-activity/activity/exchangeRecordList"

// 首页轮播
#define kApi_advertAdvertList_Path   @"/pgTalk-operation/advert/advertList"

//首页公告弹窗
#define kApi_announcementAnnouncementPopUps_Path    @"/pgTalk-operation/announcement/announcementPopUps"

//设置公告今日提醒
#define kApi_announcementSetPopupReminder_Path   @"/pgTalk-operation/announcement/setPopupReminder"

//更新接口
#define KAPI_wmsMobileProGetVersion @"/pgTalk-operation/version/getVersion"

//
#define KAPI_hide @"/pgTalk-operation/version/hide"

//投诉类型
#define KAPI_complaintGetMain @"/pgTalk-operation/complaint/getMain"

// 提交投诉
#define KAPI_complaintSave @"/pgTalk-operation/complaint/save"

// 解析订单
#define KAPI_pgPayAnalyzeDataURL @"/pgTalk-third/payOrder/analyzeData"

// 支付订单
#define KAPI_pgPayPay @"/pgTalk-third/payOrder/pay"
// 生成付款碼
#define KAPI_pgPayPaymentCode @"/pgTalk-third/payOrder/generatePaymentCode"
// 生成儲值碼
#define KAPI_pgPayRechargeCode @"/pgTalk-third/payOrder/generateRechargeCode"
// 自動使用折扣
#define KAPI_pgPayAutoUseDiscount @"/pgTalk-user/chat/updateAutoUseDiscount"
// 折扣订单
#define KAPI_transPayURL @"/pgTalk-finance/transfer/calculateDiscount"
// PT活动
#define KAPI_ptPayURL @"/pgTalk-finance/ptActivity/getActivityInfo"

//公告详情
#define KH5AnnouncementIndex @"/pgTalk-operation/announcement/index?id="
//http://47.241.14.123/wmsMobilePro/announcement/index?id=1295607063045926914
// 广告
#define KH5bannerIndex @"/pgTalk-operation/advert/index?id="

//退出登录清除
#define chatDoLogoutURL @"/pgTalk-user/loginAuth/doLogout"

//上传消费申诉
#define saveConsumerAppealURL @"/pgTalk-operation/consumerAppeal/saveConsumerAppeal"
//获取申诉记录
#define consumerAppealRecordURL @"/pgTalk-operation/consumerAppeal/consumerAppealRecord"

///點讚用戶
#define kImFeedPraises @"/pgTalk-feed/feed/getOneFeed"

//Web登入
#define qrScanIsExpireURL @"/pgTalk-user/loginAuth/queryCodeStatus"//@"/queryCodeStatus"
#define webScanLoginURL  @"/pgTalk-user/user/authLogin"//@"/authLogin"

//优惠活动列表
#define kAPI_disCountActivityList @"/pgTalk-finance/discountActivity/list"
//优惠活动入口
#define kAPI_disCountActivityMain @"/pgTalk-finance/discountActivity/main"

//应用程序列表
#define kAPI_applicationList     @"/pgTalk-third/application/list"
//应用程序入口
#define kAPI_applicationMain     @"/pgTalk-third/application/main"

// 公告通知
#define kAPI_AnnouncementMessage @"/pgTalk-operation/announcementMessage/list"

//商家类型
#define kAPI_commonBusinessType     @"/pgTalk-user/common/businessType"
// 商家分類
#define kAPI_commonBusinessCategory     @"/pgTalk-user/common/businessCategory"
//APP地区
#define kAPI_commonAppRegion      @"/pgTalk-user/common/appRegion"

//直播类的接口
//直播授权
#define kAPI_liveAuthorize        @"/live/authorize"
//结束直播
#define kAPI_liveStopRoom         @"/pgTalk-live/liveRoom/stopLiveRoom"
//申请主播
#define kAPI_liveApplyLive        @"/pgTalk-live/liveUser/applyLive"
//获取主播审核状态
#define kAPI_liveAuditStatus      @"/pgTalk-live/liveUser/getAuditStatus"

// 直播分类
#define KAPI_liveClassify @"/pgTalk-live/live/classify"
// 直播礼物
#define KAPI_liveGiftList @"/pgTalk-live/live/giftList"
// 直播打赏
#define kAPI_liveReward @"/pgTalk-live/live/reward"
// 直播隨機礼物
#define KAPI_liveRandomGiftList @"/pgTalk-live/randomGift/list"
// 直播送隨機礼物
#define KAPI_liveRandomGiftPay @"/pgTalk-live/randomGift/pay"
// 粉丝明细
#define kAPI_liveFansDetail @"/liveFans/getFansDetail"
// 粉丝数量
#define kAPI_liveFansCount @"/pgTalk-live/liveFans/getFansCount"
// 粉丝列表
#define kAPI_liveFansList @"/pgTalk-live/liveFans/getFansList"
// 直播关注
#define kAPI_liveFansSubscribe @"/pgTalk-live/liveFans/subscribe"
// 观众进入房间
#define kAPI_liveEnterRoom @"/pgTalk-live/liveRoom/enterLiveRoom"
// 观众离开房间
#define kAPI_liveQuitRoom @"/pgTalk-live/liveRoom/quitLiveRoom"
// 正在开播的直播间
#define kAPI_liveRoomList @"/pgTalk-live/liveRoom/getLiveRoomList"
// 推荐直播间
#define kAPI_liveRecommendRoomList @"/pgTalk-live/liveRoom/getRecommendRoomList"
// 关注的直播间
#define kAPI_liveSubscribeRoomList @"/pgTalk-live/liveRoom/getSubscribeRoomList"
// 获取观众列表
#define kAPI_liveOnlineViewer @"/pgTalk-live/liveRoom/getOnlineViewer"
// 获取排行榜前三
#define kAPI_liveTopThree @"/pgTalk-live/liveRoom/liveTopThree/"
// 获取观众数量
#define kAPI_liveOnlineViewerCount @"/pgTalk-live/liveRoom/getOnlineViewerCount"
// 获取观众 不分页
#define kAPI_liveOnlineViewerList @"/pgTalk-live/liveRoom/getOnlineViewerList"
// 主播开播
#define kAPI_liveStartRoom @"/pgTalk-live/liveRoom/startLiveRoom"
// 踢人
#define kAPI_liveKick @"/pgTalk-live/operating/kick"
// 取消踢人
#define kAPI_liveCancelKicking @"/pgTalk-live/operating/cancelKicking"
// 禁言
#define kAPI_liveMute @"/pgTalk-live/operating/mute"
// 取消禁言
#define kAPI_liveCancelMute @"/pgTalk-live/operating/cancelMute"
// 收益详情
#define kAPI_liveIncomeDetail @"/pgTalk-live/liveIncome/detail"
// 提现列表
#define kAPI_liveWithdrawList @"/pgTalk-live/liveIncome/getLiveWithdrawList"
// 提现
#define kAPI_liveIncomeWithdraw @"/pgTalk-live/liveIncome/withdraw"
// 直播收益记录
#define kAPI_LiveRoomGroup @"/pgTalk-live/liveRoomRecord/getLiveRoomRecordGroup"
// 直播收益明细
#define kAPI_liveConsumptionRecord @"​/pgTalk-live/liveRoomRecord/getLiveConsumptionRecord"
// 直播回放
#define kAPI_livePlaybackRecord @"/pgTalk-live/liveRoomRecord/getLivePlaybackRecord"
// 直播正在开播数量
#define kPAI_liveLiveNumber @"/pgTalk-live/liveRoom/getInProgressNum"
//  获取直播房间详情
#define kPAI_liveLiveRoom @"/pgTalk-live/liveRoom/getOneLiveRoom"
// 直播打赏记录
#define kPAI_liveGiftMoney @"/pgTalk-live/liveRoom/getLiveGiftMoney"
// 直播分享连接
#define kPAI_liveShare @"/pgTalk-live/live/generateLiveShareAddress"
// 直播特效
#define kPAI_liveEfficacy @"/pgTalk-live/live/getLiveSpecialEfficacy"
// 更新直播间信息
#define kPAI_LiveUpdateRoomInfo @"/pgTalk-live/liveRoom/updateRoomInfo"
// 直播全部观众
#define kPAI_LiveAllOnline @"/pgTalk-live/liveRoom/getAllOnlineViewerList"

// 获取用户资料
#define kAPI_LiveUserInfo @"/pgTalk-live/live/getUserInfo"
// 是否被禁播
#define kAPI_getLiveUserStatus @"/pgTalk-live/liveUser/getLiveUserStatus"
//直播警告
#define kAPI_liveCaveat  @"/pgTalk-live/live/caveat"
//获取房间信息
#define kAPI_getLiveRoomInfo  @"/pgTalk-live/liveRoom/getRoomInfo"
//直播黑名单列表
#define kAPI_getLiveBlackList  @"/pgTalk-live/liveChatBlack/getBlackList"
//直播黑名单移除
#define kAPI_liveRemoveBlack  @"/pgTalk-live/liveChatBlack/remove"
//直播黑名单设置
#define kAPI_liveSubmitBlack  @"/pgTalk-live/liveChatBlack/submit"
//直播设置小帮手
#define kAPI_liveSetHelp  @"/pgTalk-live/liveAdmin/save/"
// 直播取消小帮手
#define kAPI_liveCloseHelp  @"/pgTalk-live/liveAdmin/remove/"
/// 直播奖金池金额
#define kAPI_liveBonusMoney @"/pgTalk-live/bonusPool/bonusPoolMoney"
/// 直播奖金池说明
#define kAPI_liveBonusInfo  @"/pgTalk-live/bonusPool/introduction"
/// 直播奖金池投入
#define kAPI_liveBonusInvest  @"/pgTalk-live/bonusPool/invest"
/// 直播奖金池投入金额列表
#define kAPI_liveBonusList  @"/pgTalk-live/bonusPool/list"
/// 直播奖金池上榜名单
#define kAPI_liveBonusWinRecord  @"/pgTalk-live/bonusPool/winRecord"
/// 直播活動禮物廣告
#define kAPI_liveActivityGiftAdvert  @"/pgTalk-live/activityGift/advert"
/// 直播活動禮物廣告分類
#define kAPI_liveActivityGiftCategory  @"/pgTalk-live/activityGift/category"
/// 直播活動禮物廣告詳情
#define kAPI_liveActivityGiftDetail  @"/pgTalk-live/activityGift/detail"
/// 直播活動禮物懸浮圖
#define kAPI_liveActivityGiftFloat  @"/pgTalk-live/activityGift/float"
/// 直播活動禮物榜单
#define kAPI_liveActivityGiftLeaderboard  @"/pgTalk-live/activityGift/leaderboard"
/// 直播活動禮物
#define kAPI_liveActivityGiftList  @"/pgTalk-live/activityGift/list"
/// 直播活動禮物購買
#define kAPI_liveActivityGiftPay  @"/pgTalk-live/activityGift/pay"
/// 直播发起话题
#define kAPI_liveVoteLaunch  @"/pgTalk-live/liveVote/launch"
/// 直播用户投票
#define kAPI_liveVoteUserVote @"/pgTalk-live/liveVote/vote"
/// 直播聊天消息發送
#define kAPI_liveSendMessage  @"/pgTalk-live/live/sendMessage"
/// 直播翻譯
#define kAPI_liveTranslateLanguage  @"/pgTalk-live/live/translateLanguage"

//日志上传
#define kApI_userLogUpload    @"/pgTalk-user/userLog/upload"
// 获取共同好友
#define kAPI_mutualFriends @"/pgTalk-friend/chat/getMutualFriends"
// 获取每日新增好友
#define kAPI_todayFriend @"/pgTalk-friend/chat/getTodayFriend"
// 修改用户同意加入群
#define kAPI_updateAgreeJoinGroup @"/chat/updateAgreeJoinGroup"
// 群组黑名单
#define kAPI_groupBlacklist @"/pgTalk-group/chat/getGroupBlacklist"
// 移除群组黑名单
#define kAPI_removeGroupBlacklist @"/pgTalk-group/chat/removeGroupBlacklist"
// 的士解析交易
#define kAPI_taxiAnalyzeData @"/pgTalk-finance/taxi/analyzeData"
// 的士支付
#define kAPI_taxiPay @"/pgTalk-finance/taxi/pay"
// 的士信用卡支付
#define kAPI_taxiCreditCardPay @"/pgTalk-third/taxi/creditCardPay"
// 信用卡支付
#define kAPI_creditCardPay @"/pgTalk-creditCard/creditCard/"
// 通用配置接口  IsEnableFeedPhotoWall YES 显示发现入口  IsEnableCreditCardPay YES 信用卡可用
#define kAPI_lifeConfig @"/pgTalk-user/common/config"
// life追踪
#define kAPI_lifeSubscribe @"/pgTalk-feed/feedFans/subscribe"
// life取消追踪
#define kAPI_lifeUnSubscribe @"/pgTalk-feed/feedFans/unSubscribe"
// life获取追踪列表
#define kAPI_lifeSubscribeList @"/pgTalk-feed/feedFans/getFeedSubscribeList"
// life获取粉丝列表
#define kAPI_lifeFriendList @"/pgTalk-feed/feedFans/getFriendFeedSubscribeList"
// life是否開啓推送通知
#define kAPI_lifeEnablePush @"/pgTalk-feed/feedFans/enablePush"
// life动态搜索
#define kAPI_lifeFeedSearch @"/pgTalk-feed/feed/lifeFeedSearch"
// life用户搜索
#define kAPI_lifeUserSearch @"/pgTalk-user/feed/lifeUserSearch"
// life汇总数据
#define kAPI_lifeFeedCollect @"/pgTalk-feed/feed/getFeedCollect"


///提交成为声聊主播
#define kAPI_commitVoiceChatURL @"/pgTalk-live/voiceChatUser/submit"

///声聊主播列表
#define kAPI_voiceChatListURL @"/pgTalk-live/voiceChatRoom/getVoiceUserList"

///获取声聊主播信息
#define kAPI_getVoiceChatUserInfoURL @"/pgTalk-live/voiceChatUser/getSubmitInfo"

///获取声聊主播状态
#define kAPI_getVoiceChatUserStateURL @"/pgTalk-live/voiceChatRoom/getVoiceUserStatus/"

//获取追踪列表
#define kAPI_getVoiceChatFansListURL @"/pgTalk-live/voiceChatFans/getSubscribeList"
//点击头像查看主播
#define kAPI_getVoiceChatHostInfoURL @"/pgTalk-live/voiceChatFans/getUserInfo/"
//追踪主播
#define kAPI_voiceChatHostSubscribeURL @"/pgTalk-live/voiceChatFans/subscribe/"
//取消主播追踪
#define kAPI_voiceChatHostUnSubscribeURL @"/pgTalk-live/voiceChatFans/unSubscribe/"
//获取收费标准
#define kAPI_getVoiceChatPriceListURL @"/pgTalk-live/voiceChatPayTemplate/payList/"
//获取声聊会话列表
#define kAPI_getVoiceChatRecords @"​​/pgTalk-live/voiceChatRoom/getRecords"
//声聊收益记录
#define kAPI_getVoiceChatRecordGroup @"/pgTalk-live/voiceChatRecord/getVoiceChatRecordGroup"

//发起声聊聊天
#define kAPI_startAudioVideoChatURL @"/pgTalk-live/voiceChatRoom/startAudioVideoChat"
//挂断声聊聊天
#define kAPI_stopAudioVideoChatURL @"/pgTalk-live/voiceChatRoom/stopAudioVideoChat/"


///进入声聊聊天室
#define kAPI_enterVoiceChatRoomURL @"/pgTalk-live/voiceChatRoom/enterRoom/"
//获取聊天记录
#define kAPI_getRecordsVideoChatURL @"/pgTalk-live/voiceChatRoom/getRecords"
//删除聊天记录
#define kAPI_deleteRecordVideoChatURL @"/pgTalk-live/voiceChatRoom/deleteRecord"
///获取主播状态
#define kAPI_getVoiceUserStatusURL @"/pgTalk-live/voiceChatRoom/getVoiceUserStatus/"

//获取提示内容
#define kAPI_getVoiceChatTipsURL @"/pgTalk-live/voiceChatRoom/getOrderInfo"
//获取订单明细
#define kAPI_getVoiceChatOrderDetail @"/pgTalk-live/voiceChatRoom/getOrderDetail"
// 获取声聊粉丝列表
#define kAPI_getVoiceChatFansList @"/pgTalk-live/voiceChatFans/getFansList"
// 获取声聊主播信息 {voiceChatUserId}
#define kAPI_getVoiceChatFansUserInfo @"/pgTalk-live/voiceChatFans/getUserInfo/"

// 获取声聊主播信息 {voiceChatUserId}
#define kAPI_deleteVoiceChatData @"/pgTalk-live/voiceChatRoom/deleteRecord/"
// 发送声聊消息
#define kAPI_sendVoiceText @"/pgTalk-live/voiceChatRoom/sendVoiceText"
// 声聊置顶聊天
#define kAPI_SetVoiceTop @"/pgTalk-live/voiceChatRoom/setTop"
// 声聊黑名单
#define kAPI_getVoiceBlack @"/pgTalk-live/voicechatblack/getBlackList"
// 声聊加入黑名单
#define kAPI_addVoiceBlack @"/pgTalk-live/voicechatblack/submit"
// 声聊移除黑名单
#define kAPI_removeVoiceBlack @"/pgTalk-live/voicechatblack/remove"

///读取消息
#define kAPI_readMsgVoiceChatDataURL @"/pgTalk-live/voiceChatRoom/readMsg/"


///读取我接待的
#define kAPI_getUersRecordsVoiceChatDataURL @"/voiceChatRoom/getUserRecords​/"

// 查看缴费单
#define kAPI_getViewCouponCode @"/pgTalk-finance/linerecharge/viewCouponCode"
// 获取声聊免费时长
#define kAPI_getFreeVoiceInfo @"/pgTalk-live/voiceChatRoom/getFreeVoiceInfo"



// 获取名人堂推荐列表
#define kAPI_getRecommendUserListURL @"/pgTalk-feed/recommendUser/getRecommendUserList"


//一键追踪
#define kAPI_focuHallFansURL @"/pgTalk-feed/feedFans/subscribeUsers"

//上传票据
#define kAPI_uploadBillURL @"/pgTalk-finance/linerecharge/uploadBill"

//汇款最高限额
#define kAPI_getMaxRemittanceLimitURL @"/pgTalk-finance/linerecharge/getMaxRemittanceLimit"


//排行榜
#define kAPI_getRankListURL @"/pgTalk-live/live/leaderboard"

//每日任务数据
#define kAPI_getTalkMoneyTask @"/pgTalk-activity/talkMoney/main"
//每日任务弹窗 只弹一次
#define kAPI_getTalkMoneyPop @"/pgTalk-activity/talkMoney/activityPopUps"
//每日任务推荐商品
#define kAPI_getTalkMoneyGoods @"/pgTalk-activity/talkMoney/recommendGoods"
// 聊天奖励
#define kAPI_getTalkMoneyChat @"/pgTalk-activity/talkMoney/chatAward"

//每日任务詳情
#define kAPI_getDailyTasksDetail @"/pgTalk-activity/dailyTasks/detail"
//每日任务簽到
#define kAPI_getDailyTasksCheckIn @"/pgTalk-activity/dailyTasks/checkIn"
//每日任务
#define kAPI_getDailyTasksReceiveAward @"/pgTalk-activity/dailyTasks/receiveAward"
// 每日任務數量
#define kAPI_getDailyTasksAwardCount @"/pgTalk-activity/dailyTasks/awardCount"

//设置推荐人
#define kAPI_addReferrerURL @"/pgTalk-user/user/setReferrer"


//获取关注数量
#define kAPI_getSubscribeCountURL @"/pgTalk-live/voiceChatFans/getSubscribeCount"

//获取声聊收益排行榜
#define kAPI_getLeaderboardURL @"/pgTalk-live/voiceChatRecord/leaderboard"

//获取主播详情
#define kAPI_getVoiceUserOneURL @"/pgTalk-live/voiceChatRoom/getVoiceUserOne"

//获取声聊个人收益排行榜
#define kAPI_getMyLeaderboardURL @"/pgTalk-live/voiceChatRecord/myLeaderboard"

//获取CQ2数据
#define kAPI_getCO2ListURL @"/voiceChatRecord/myLeaderboard"

//获取主播状态
#define kAPI_getHOSTStatusURL @"/pgTalk-live/liveRoom/getLiveRoomStatus/"

//加入铁粉计划
#define kAPI_joinPopularizeURL @"/pgTalk-activity/popularize/joinPopularize"

//铁粉计划结算记录
#define kAPI_fansRecordListURL @"/pgTalk-activity/popularize/getPopularizeSettlementRecordList"

//铁粉计划数据
#define kAPI_getPopularizeInfoURL @"/pgTalk-activity/popularize/getPopularizeInfo"

//talkmoney和铁粉计划开关
#define kAPI_activityConfigURL @"/pgTalk-activity/talkMoney/activityConfig"


//是否展示推荐好友
#define kAPI_getShowRecommendFriendURL @"/pgTalk-friend/recommendFriend/getShowRecommendFriend"

//获取好友列表
#define kAPI_getFriendListURL @"/pgTalk-friend/chat/getFriendList"

//获取群组列表
#define kAPI_getGroupListURL @"/pgTalk-group/chat/getGroupList"

//获取用户详情
#define kAPI_getUserInfoURL @"/pgTalk-user/user/getUserInfo"

//获取支付详情
#define kAPI_getPayInfoURL @"/pgTalk-user/pay/getPayInfo"

//获取置顶详情
#define kAPI_getTopListURL @"/pgTalk-user/chat/getTopList"

//获取pg详情
#define kAPI_getPGTalkURL @"/pgTalk-user/user/getPGTalkAccount"


//直播服务条款
#define kAPI_getAgreeRegulationURL @"/pgTalk-live/live-regulation/agreeRegulation"
//是否已同意直播条款
#define kAPI_getIsAgreeURL @"/pgTalk-live/live-regulation/getIsAgree"



//2021年06月26日10

//支付回调
#define kAPI_applePayCallBackURL @"/pgTalk-finance/diamond-purchase-product/applePayCallBack"

//pgp兑换钻石
#define kAPI_applePayExchangeURL @"/pgTalk-finance/diamond-purchase-product/exchange"


//获取产品列表
#define kAPI_applePayGetProductListURL @"/pgTalk-finance/diamond-purchase-product/getProductList"

//获取苹果内购钻石订单
#define kAPI_applePayPurchaseURL @"/pgTalk-finance/diamond-purchase-product/purchase"


//获取苹果内购钻石订单记录
#define kAPI_applePayGetRecordListURL @"/pgTalk-finance/diamond-purchase-record/getRecordList"


//三方请求头部
#define kAPI_thirdHeaderURL @"/pgTalk-third"

//设置语言
#define kAPI_setLanguageURL @"/pgTalk-user/user/setLanguage"



//2021年06月30日 web
//直播隐私协议
#define kAPI_live_privacyURL @"/pgTalk-operation/common/doc?name=live_privacy"
//内容管理:
#define kAPI_live_content_descURL @"/pgTalk-operation/common/doc?name=live_content_desc"
//服务条款:
#define kAPI_live_terms_serviceURL @"/pgTalk-operation/common/doc?name=live_terms_service"
//问题反馈
#define kAPI_feedbackURL @"/pgTalk-operation/feedback/index"

//获取群人数
#define kAPI_getGroupMemberCountURL @"/pgTalk-group/chat/getGroupMemberCount"

//获取订单详情
#define kAPI_getOrderDetailURL @"/pgTalk-finance/linerecharge/detail"

//确认订单
#define kAPI_getconfirmPaymentURL @"/pgTalk-finance/linerecharge/confirmPayment"

//取消订单
#define kAPI_getcancelOrderURL @"/pgTalk-finance/linerecharge/cancelOrder"


//获取发证类别
#define kAPI_getcategoryListURL @"/pgTalk-user/issuance/categoryList"

//获取发证编号类别
#define kAPI_getcodeListURL @"/pgTalk-user/issuance/codeList"


//提交认证
#define kAPI_get_userAuthURL @"/pgTalk-user/user/userAuth"

//生成linepay支付订单
#define kAPI_generateLinePayOrderURL @"/pgTalk-finance/linerecharge/generateLinePayOrder"

//linepay支付回调
#define kAPI_linePayCallbackURL @"/pgTalk-finance/linerecharge/linePayCallback"

//linepay支付回调页面
#define kAPI_linePayCallbackPageURL @"/pgTalk-finance/linerecharge/linePayCallbackPage"


//linepay web页面
#define kAPI_linePayWebPayAuthURL @"/pgTalk-user/user/webPayAuth"

//谷歌上传配置接口
#define kAPI_gooaleUploadDetailURL @"/pgTalk-user/upload/googleStorageConfig"

//校验每月汇款限额
#define kAPI_checkMonthLimitURL @"/pgTalk-finance/linerecharge/checkMonthLimit"

//支付方式列表
#define kAPI_payTypeListURL @"/pgTalk-finance/linerecharge/payTypeList"

//获取GIF缩略图
#define kApi_ChatCodeList                  @"/pgTalk-user/chat/codeList"


//Lift随机动态
#define kAPI_lifeFeedRandomURL @"/pgTalk-feed/feed/lifeFeedRandom"
///信用卡列表
#define kAPI_creditCardListURL @"/pgTalk-user/userCreditCard/creditCardList"


///绑定信用卡
#define kAPI_bandingUserCreditCardURL @"/pgTalk-user/userCreditCard/bandingUserCreditCard"


///信用卡详情
#define kAPI_creditCardDetailURL @"/pgTalk-user/userCreditCard/creditCard/"

///删除信用卡
#define kAPI_deleteCreditCardURL @"/pgTalk-user/userCreditCard/removeCreditCard/"

///更新信用卡
#define kAPI_updateUserCreditCardURL @"/pgTalk-user/userCreditCard/updateUserCreditCard"


///设置默认信用卡
#define kAPI_setDefaultBankCardURL @"/pgTalk-user/userCreditCard/setDefaultBankCard/"


///使用者條例
#define kAPI_setcredit_card_serviceURL @"/pgTalk-operation/common/doc?name=credit_card_service"

//同意lalamove服务条款
#define kAPI_getLaLaMoveAgreeRegulationURL @"/pgTalk-third/lalamove/agreeRegulation"
//是否已同意laalmove条款
#define kAPI_getLaLaMoveIsAgreeURL @"/pgTalk-third/lalamove/getIsAgree"
//lalamove服务条款:
#define kAPI_LaLamove_serviceURL @"/pgTalk-operation/common/doc?name=delivery_service"
//lalamove车型
#define kAPI_LaLamove_deliveryConfigURL @"/pgTalk-third/lalamove/deliveryConfig"
//lalamove市场
#define kAPI_LaLamove_marketTypeURL @"/pgTalk-third/common/marketType"
//lalamove報價
#define kAPI_LaLamove_quotationsURL @"/pgTalk-third/lalamove/quotations"
//lalamove生成訂單
#define kAPI_LaLamove_generateOrderURL @"/pgTalk-third/lalamove/generateOrderQuotation"
//lalamove下單
#define kAPI_LaLamove_payPgpOrderURL @"/pgTalk-third/lalamove/payPgp"
//lalamove 付小費
#define kAPI_LaLamove_payTipsOrderURL @"/pgTalk-third/lalamove/tips"
//lalamove訂單
#define kAPI_LaLamove_ordersURL @"/pgTalk-third/lalamove/orders"
//lalamove訂單詳情
#define kAPI_LaLamove_orderDetailURL @"/pgTalk-third/lalamove/detail"
//lalamove取消訂單
#define kAPI_LaLamove_cancelOrderURL @"/pgTalk-third/lalamove/cancel"

// movie 同意条款
#define kAPI_getMovieAgreeRegulationURL @"/pgTalk-movie/movie/agreeRegulation"
//是否已同意movie条款
#define kAPI_getMovieIsAgreeURL @"/pgTalk-movie/movie/getIsAgree"
// movie 购买影片
#define kAPI_getMovieBuyURL @"/pgTalk-movie/movie/buyMovie"
//movie 分享數量
#define kAPI_getMovieShareURL     @"/pgTalk-movie/operating/share/"

//2021年12月02日
//獲取通知狀態
#define kAPI_getAnnouncementNoticeStatusURL @"/pgTalk-operation/announcement/getAnnouncementNoticeStatus"
//修改通知狀態
#define kAPI_updateAnnouncementNoticeStatusURL @"/pgTalk-operation/announcement/updateAnnouncementNoticeStatus"


// 台灣大車隊叫小黄車
#define kAPI_Taxi_CallYellowURL @"/pgTalk-third/callTaxi/callYellowTaxi"
// 台灣大車隊小黃車報價
#define kAPI_Taxi_YellowEstimatedFareURL @"/pgTalk-third/callTaxi/getYellowTaxiEstimatedFare"
// 台灣大車隊訂單列表
#define kAPI_Taxi_OrderList @"/pgTalk-third/callTaxi/getOrderList"
// 台灣大車隊訂單詳情
#define kAPI_Taxi_OrderDetail @"/pgTalk-third/callTaxi/getOrderDetail"
// 台灣大車隊取消訂單
#define kAPI_Taxi_CancelOrder @"/pgTalk-third/callTaxi/cancelOrder"
// 台灣大車隊行程中的訂單
#define kAPI_Taxi_LastItineraryOrder @"/pgTalk-third/callTaxi/getLastItineraryOrder"
// 台灣大車隊城市列表
#define kAPI_Taxi_GetCity @"/pgTalk-third/callTaxi/getCityId"
// 台灣大車隊乘客未上車
#define kAPI_Taxi_NotInCar @"/pgTalk-third/callTaxi/isNotInCar"
// 台灣大車隊报价
#define kAPI_Taxi_Estimated @"/pgTalk-third/callTaxi/getYellowTaxiEstimatedFare"

// 第三方应用程序
#define kAPI_GetThirdApplication @"/pgTalk-third/application/getThirdApplication"

//直播提醒通知狀態
#define kAPI_updateLiveNoticeStatusURL @"/pgTalk-user/user/updateSystemNoticeStatus"
// 宗教祭祀祈福首页
#define kAPI_Religious_GetMain @"/pgTalk-activity/religiousBlessing/getMain"
// 宗教祭祀祈福生成订单
#define kAPI_Religious_BuildOrder @"/pgTalk-activity/religiousBlessing/buildOrder"
// 宗教祭祀祈福取消订单
#define kAPI_Religious_CancelOrder @"/pgTalk-activity/religiousBlessing/cancelOrder"
// 宗教祭祀祈福获取时辰 暂时没使用
#define kAPI_Religious_GetBlessingTime @"/pgTalk-activity/religiousBlessing/getReligiousBlessingTime"
// 宗教祭祀祈福首页支付订单
#define kAPI_Religious_PayOrder @"/pgTalk-activity/religiousBlessing/payOrder"
// 宗教祭祀祈福点灯详情
#define kAPI_Religious_RecordDetail @"/pgTalk-activity/religiousBlessing/recordDetail"
// 宗教祭祀祈福点灯记录
#define kAPI_Religious_RecordList @"/pgTalk-activity/religiousBlessing/recordList"
// 宗教祭祀祈福移除祈福者
#define kAPI_Religious_RemoveUser @"/pgTalk-activity/religiousBlessing/removeUser"
// 宗教祭祀祈福新增-更新祈福者
#define kAPI_Religious_SubmitUser @"/pgTalk-activity/religiousBlessing/submitUser"
// 宗教祭祀祈福祈福者列表
#define kAPI_Religious_UserList @"/pgTalk-activity/religiousBlessing/userList"
// 庙宇列表
#define kAPI_Religious_TempleList @"/pgTalk-activity/religiousBlessing/templeList"
// 服務說明
#define kAPI_Religious_content_descURL @"/pgTalk-operation/common/doc?name=religious_blessing_service"
// 批量增加好友 手机通讯录
#define kAPI_BulkAddFriend @"/pgTalk-friend/chat/bulkAddFriend"


// 直播特效
#define kAPI_getLiveSpecialEfficacy @"/pgTalk-live/live/getLiveSpecialEfficacy"

// 演唱会列表
#define kAPI_Concert_List @"/pgTalk-activity/concert/list"
// 活动详情
#define kAPI_Concert_Detail @"/pgTalk-activity/concert/detail"
// 活動門票信息
#define kAPI_Concert_Tickets @"/pgTalk-activity/concert/concertTickets"
// 发送验证码
#define kAPI_Concert_Email_Code @"/pgTalk-activity/concert/sendEmailVerificationCode"
// 下单
#define kAPI_Concert_PlaceOrder @"/pgTalk-activity/concert/placeOrder"
// 支付订单
#define kAPI_Concert_PayOrder @"/pgTalk-activity/concert/payOrder"
// 取消订单
#define kAPI_Concertt_CancelOrder @"/pgTalk-activity/concert/cancelOrder"
// 校驗學生會會員
#define kAPI_Concert_StudentUnionMember @"/pgTalk-activity/concert/checkStudentUnionMember"
// 用戶票券详情
#define kAPI_Concert_User_ticket @"/pgTalk-activity/concert/ticket/"
// 用戶票券
#define kAPI_Concert_User_tickets @"/pgTalk-activity/concert/tickets"
// 检票
#define kAPI_Concert_Wicket @"/pgTalk-activity/concert/wicket"
// 未付款订单
#define kAPI_Concert_UnpaidOrder @"/pgTalk-activity/concert/getUnpaidOrder"
// 退款詳情
#define kAPI_Concert_RefundDetail @"/pgTalk-activity/concert/refund/detail/"
// 退款
#define kAPI_Concert_Refund @"/pgTalk-activity/concert/refund/"

// 領取優惠券
#define kAPI_Coupon_Acquire @"/pgTalk-coupon/coupon/acquireCoupon"
// 優惠券活動
#define kAPI_Coupon_Activity @"/pgTalk-coupon/coupon/activity"
// 可用優惠券
#define kAPI_Coupon_Available @"/pgTalk-coupon/coupon/available"
// 優惠券詳情
#define kAPI_Coupon_Detail @"/pgTalk-coupon/coupon/detail/"
// 兌換優惠券
#define kAPI_Coupon_Exchange @"/pgTalk-coupon/coupon/exchangeCoupon"
// 用戶優惠券
#define kAPI_Coupon_User @"/pgTalk-coupon/coupon/userCoupons"

// 用戶標識
#define kAPI_User_Star @"/pgTalk-feed/recommendUser/officialStar"
// 幣商鑽石比值
#define kAPI_DiamondBusiness_Rate @"/pgTalk-finance/diamondBusiness/diamondExchangeRate"
// 是否是幣商
#define kAPI_DiamondBusiness_Is @"/pgTalk-finance/diamondBusiness/isDiamondBusiness"
// 購買記錄
#define kAPI_DiamondBusiness_PayRecordList @"/pgTalk-finance/diamondBusiness/payRecordList"
// 幣商轉賬
#define kAPI_DiamondBusiness_Transfer @"/pgTalk-finance/diamondBusiness/transfer"
// 幣商虛擬銀行購買
#define kAPI_DiamondBusiness_VirtualBank @"/pgTalk-finance/diamondBusiness/virtualBank"
// 取消訂單
#define kAPI_DiamondBusiness_CancelOrder @"/pgTalk-finance/diamondBusiness/payRecord/cancelOrder"
// 通過訂單ID獲取詳情
#define kAPI_DiamondBusiness_PayRecordDetail @"/pgTalk-finance/diamondBusiness/payRecord/detail"
// 獲取未付款訂單
#define kAPI_DiamondBusiness_PayRecordId @"/pgTalk-finance/diamondBusiness/getUnpaidConvenienceStoreRechargeRecordId"

// 設置聊天、銷毀密碼
#define kAPI_ChatLock_Setting  @"/pgTalk-user/chatRoomLock/setting"
// 聊天、銷毀密碼配置信息
#define kAPI_ChatLock_Config  @"/pgTalk-user/chatRoomLock/config"
// 聊天、銷毀密碼配置信息
#define kAPI_ChatLock_Check  @"/pgTalk-user/chatRoomLock/check"
// 開關銷毀密碼
#define kAPI_ChatLock_Closek  @"/pgTalk-user/chatRoomLock/close"
// 好友上鎖
#define kAPI_Friend_Lock  @"/pgTalk-friend/chat/lock"
// 群組上鎖
#define kAPI_Group_Lock  @"/pgTalk-group/chat/lock"
// 好友隱藏
#define kAPI_Friend_Hidden  @"/pgTalk-friend/chat/hidden"
// 群組隱藏
#define kAPI_Group_Hidden  @"/pgTalk-group/chat/hidden"
// 群組隱藏
#define kAPI_Chat_RivacySetting @"/pgTalk-user/chat/updatePrivacySetting"
// vip订阅
#define kAPI_Vip_Subscribe @"/pgTalk-finance/vipSubscribe/subscribe"
// 關閉vip自動續費
#define kAPI_Vip_CloseAutoSubscribe @"/pgTalk-user/user/closeAutoSubscribe"
// 變更vip方案
#define kAPI_Vip_ReplaceSubscribePlan @"/pgTalk-user/user/replaceSubscribePlan"
// vip狀態
#define kAPI_Vip_Status @"/pgTalk-user/user/vipStatus"
// vip产品列表
#define kAPI_Vip_ProductList @"/pgTalk-finance/vipSubscribe/list"
// 福袋抽獎
#define kAPI_Vip_Lottery @"/pgTalk-activity/vip/lottery"
// 校驗程序鎖密碼
#define kAPI_AppPwd_Check @"/pgTalk-user/appPwd/check"
// 關閉應用程序鎖
#define kAPI_AppPwd_Close @"/pgTalk-user/appPwd/close"
// 是否設置應用程序鎖
#define kAPI_AppPwd_GetAppPwdInfo @"/pgTalk-user/appPwd/getAppPwdInfo"
// 設置生物識別
#define kAPI_AppPwd_SetBioCode @"/pgTalk-user/appPwd/setBioCode"
// 設置應用程序鎖
#define kAPI_AppPwd_Setting @"/pgTalk-user/appPwd/setting"
// 開啟-關閉過期通知
#define kAPI_Vip_CloseExpireNotice @"/pgTalk-user/user/closeExpireNotice"
// vip订阅支付方式
#define kAPI_Vip_PayType @"/pgTalk-finance/vipSubscribe/payType"

#endif /* SIMInterface_h */

