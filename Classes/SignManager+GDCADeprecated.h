//
//  SignManager+GDCADeprecated.h
//  GDSignature
//
//  Created by fisher hk on 2018/7/5.
//  Copyright © 2018年 fisher hk. All rights reserved.
//此文件接口皆已废弃 请使用SignManager.h中对应的新接口

#import <GDSignature/GDSignature.h>

@interface SignManager (GDCADeprecated)

/**
 当前控制器
 @deprecated 此属性在V-3.0.0 版本已经废弃
 */
@property (nonatomic, strong) UIViewController *currentViewController DEPRECATED_ATTRIBUTE;

/**
 SDK 校验接口 初始化
 @deprecated 此接口在V-3.0.0 版本已经废弃
 @note 请使用 SignManager.h - (void)checkLogin:(void(^)(void))successBlock failure:(void(^)(NSString *msg))failureBlock; 代替
 
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)validateSDK:(void(^)(void))successBlock failure:(void(^)(NSString *msg))failureBlock DEPRECATED_ATTRIBUTE;

/**
 生成证书
 @deprecated 此接口在V-3.0.0 版本已经废弃
 @note 请使用 SignManager.h - (void)createCert:(NSString *)voucherID isProgressbar:(BOOL)isProgressbar success:(void(^)(NSString *msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock; 代替
 
 @param voucherID 凭证ID
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)creatCert:(NSString *)voucherID success:(void(^)(NSString *msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock DEPRECATED_ATTRIBUTE;

/**
 生成证书
 @deprecated 此接口在V-3.0.0 版本已经废弃
 @note 请使用 SignManager.h - (void)createCert:(NSString *)voucherID certType:(GDCACertType)certType isProgressbar:(BOOL)isProgressbar success:(void(^)(NSString *msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock; 代替
 
 @param voucherID 凭证ID
 @param isProgressbar 是否需要loading YES：有loading， NO：无loading
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)createCert:(NSString *)voucherID isProgressbar:(BOOL)isProgressbar success:(void(^)(NSString *msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock DEPRECATED_ATTRIBUTE;

/**
 证书详情
 @deprecated 此接口在V-3.0.0 版本已经废弃
 @note 请使用  SignManager.h - (void)getCertInfo:(NSString *)voucherId isProgressbar:(BOOL)isProgressbar success:(void(^)(Certfile *cert))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock; 代替
 
 @param voucherId 凭证ID
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)getCertDetail:(NSString *)voucherId success:(void(^)(Certfile *cert))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock DEPRECATED_ATTRIBUTE;

/**
 证书详情
 @deprecated 此接口在V-3.1.0 版本已经废弃
 @note 请使用  SignManager.h - (void)getCertInfo:(NSString *)voucherId certType:(GDCACertType)certType isProgressbar:(BOOL)isProgressbar success:(void(^)(Certfile *cert))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock; 代替
 
 @param voucherId 凭证ID
  @param isProgressbar 是否需要loading YES：有loading， NO：无loading
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)getCertInfo:(NSString *)voucherId isProgressbar:(BOOL)isProgressbar success:(void(^)(Certfile *cert))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock DEPRECATED_ATTRIBUTE;

/**
 实名认证
 @deprecated 此接口在V-3.0.0 版本已经废弃
 @note 请使用 SignManager.h - (void)requestAuth:(NSString *)voucherId success:(void (^)(NSString *msg))successBlock failure:(void (^)(NSInteger code, NSString *msg))failureBlock; 代替
 
 @param voucherId 凭证ID
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)userAuthed:(NSString *)voucherId success:(void (^)(NSString *msg))successBlock failure:(void (^)(NSInteger code, NSString *msg))failureBlock DEPRECATED_ATTRIBUTE;

/**
 CA 登录
 @deprecated 此接口在V-3.0.0 版本已经废弃
 @note 请使用 SignManager.h - (void)caLogin:(NSString *)voucherId qrcodeResult:(NSString *)qrcodeResult popComfirmDialog:(BOOL)popComfirmDialog autoFinish:(BOOL)autoFinish success:(void (^)(CaloginModel *calogin))successBlock failure:(void (^)(NSInteger code, NSString *msg))failureBlock; 代替
 
 @param voucherId 凭证ID
 @param loginInfo 登录信息   loginInfo为空，进入二维码扫描   有值跳过二维码
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)caLogin:(NSString *)voucherId loginInfo:(NSString *)loginInfo success:(void (^)(CaloginModel *calogin))successBlock failure:(void (^)(NSInteger code, NSString *msg))failureBlock DEPRECATED_ATTRIBUTE;

/**
 普通签署
 @deprecated 此接口在V-3.0.0 版本已经废弃
 @note 请使用 SignManager.h - (void)signFile:(NSString *)voucherId signSerial:(NSString *)signSerial isProgressbar:(BOOL)isProgressbar autoFinish:(BOOL)autoFinish success:(void(^)(void))successBlock failure:(void(^)(NSInteger code, NSString * msg))failureBlock; 代替
 
 @param voucherId 凭证ID
 @param signSerial 签署号
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)checkSignOperation:(NSString *)voucherId signSerial:(NSString *)signSerial success:(void(^)(void))successBlock failure:(void(^)(NSInteger code, NSString * msg))failureBlock DEPRECATED_ATTRIBUTE;

/**
 普通批量签署
 @deprecated 此接口在V-3.0.0 版本已经废弃
 @note 请使用 SignManager.h - (void)signFiles:(NSString *)voucherId signSerial:(NSString *)signSerial isProgressbar:(BOOL)isProgressbar autoFinish:(BOOL)autoFinish success:(void (^)(ManyFilesSignature *signature))successBlock failure:(void (^)(NSInteger code, NSString *msg))failureBlock; 代替
 
 @param voucherId 凭证ID
 @param signSerial 批量签署号
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)signMutipleOperation:(NSString *)voucherId signSerial:(NSString *)signSerial success:(void (^)(ManyFilesSignature *signature))successBlock failure:(void (^)(NSInteger code, NSString *msg))failureBlock DEPRECATED_ATTRIBUTE;

/**
 P7签署(hash原文签署)
 @deprecated 此接口在V-3.0.0 版本已经废弃
 @note 请使用 SignManager.h - (void)signHash:(NSString *)voucherId originHash:(NSString *)originHash isProgressbar:(BOOL)isProgressbar autoFinish:(BOOL)autoFinish success:(void(^)(NSString *pk7msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock; 代替
 
 @param voucherId 凭证ID
 @param originHash 原文签署号
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)checkSignOperation:(NSString *)voucherId originHash:(NSString *)originHash success:(void(^)(NSString *msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock DEPRECATED_ATTRIBUTE;

/**
 单个文件Hash签署
 @deprecated 此接口在V-3.0.0 版本已经废弃
 @note 请使用 SignManager.h- (void)signHash:(NSString *)voucherId originHash:(NSString *)originHash certType:(GDCACertType)certType isProgressbar:(BOOL)isProgressbar autoFinish:(BOOL)autoFinish success:(void(^)(NSString *pk7msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock; 代替
 
 条件：需先调用“生成证书”接口
 
 @param voucherId 凭证号
 @param originHash 文件的原文哈希，类型为String
 @param isProgressbar 是否需要loading YES：有loading， NO：无loading
 @param autoFinish 是否输入签署密码后自动校验密码
 @param successBlock 成功回调 base64之后的p7数据
 @param failureBlock 失败回调
 */
- (void)signHash:(NSString *)voucherId originHash:(NSString *)originHash isProgressbar:(BOOL)isProgressbar autoFinish:(BOOL)autoFinish success:(void(^)(NSString *pk7msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock DEPRECATED_ATTRIBUTE;

/**
 P7批量签署(hash原文批量签署，成功返回p7数组)
 @deprecated 此接口在V-3.0.0 版本已经废弃
 @note 请使用 SignManager.h - (void)signHashs:(NSString *)voucherId originHashs:(NSArray<NSString*>*)originHashs isProgressbar:(BOOL)isProgressbar autoFinish:(BOOL)autoFinish success:(void(^)(NSArray *pkcs7datas))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock; 代替
 
 
 @param voucherId 凭证ID
 @param signHashs 签署hash数组
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)SignMutipleOperation:(NSString *)voucherId signHashs:(NSArray<NSString*>*)signHashs success:(void(^)(NSArray *pkcs7datas))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock DEPRECATED_ATTRIBUTE;

@end
