//
//  CSign.h
//  CSignSDK
//
//  Created by fisher hk on 2018/4/9.
// Copyright © 2018年 fisher hk. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Certfile, GDCAUserInfo, CaloginModel, ManyFilesSignature;

/**
 证书类型
 
 GDCACertTypeRSA:RSA证书
 GDCACertTypeSM2:SM2(国密)证书
 GDCACertTypeSM2_ORG:SM2(国密)机构证书
 默认 GDCACertTypeRSA
 */
typedef NS_ENUM(NSInteger, GDCACertType){
    GDCACertTypeRSA = 0,
    GDCACertTypeSM2,
    GDCACertTypeSM2_ORG
};

@interface SignManager : NSObject

@property (nonatomic, copy) NSString *app_id;//
@property (nonatomic, copy) NSString *app_secret;//
@property (nonatomic, strong) UIColor *themeColor;//
@property (nonatomic, assign) BOOL isPublicSite;/// 正式环境为true 测试环境为false  默认为测试环境

@property (nonatomic, strong) UIColor *naviTitleColor;

+ (instancetype)shared;

/**
 *获取当前SDK的版本号
 *当前SDK版本 : 3.1.0
 *return  返回当前API的版本号
 */
UIKIT_EXTERN NSString* GDCASDKGetVersion(void);

/**
 设置独立服务器
 
 @param site 独立服务器请求地址, site为nil则使用默认服务器地址
 */
- (void)setSelfSite:(NSString *)site;

/**
 SDK 校验接口 初始化

 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)checkLogin:(void(^)(void))successBlock failure:(void(^)(NSString *msg))failureBlock;

/**
 生成证书
 条件：需先调用“实名认证”接口
 
 @param voucherID 凭证号
 @param certType 证书类型 GDCACertType
 @param isProgressbar 是否需要loading YES：有loading， NO：无loading
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)createCert:(NSString *)voucherID certType:(GDCACertType)certType isProgressbar:(BOOL)isProgressbar success:(void(^)(NSString *msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock;

/**
 证书详情

 条件：需先调用“生成证书”接口
 
 @param voucherId 凭证号
 @param certType 证书类型 GDCACertType
 @param isProgressbar 是否需要loading YES：有loading， NO：无loading
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)getCertInfo:(NSString *)voucherId certType:(GDCACertType)certType isProgressbar:(BOOL)isProgressbar success:(void(^)(Certfile *cert))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock;

/**
 修改PIN
 备注：此接口暂时只有RSA的可以使用
 
 条件：需先调用“生成证书”接口
 
 @param voucherId 凭证号
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)changePin:(NSString *)voucherId success:(void(^)(NSString *msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock;

/**
 重置PIN
 备注：此接口暂时只有RSA的可以使用
 
 条件：需先调用“生成证书”接口
 
 @param voucherId 凭证号
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)resetPin:(NSString *)voucherId success:(void(^)(NSString *msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock;

/**
 实名认证包括身份证ocr+活体校验
 
 @param voucherId 凭证号
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)requestAuth:(NSString *)voucherId success:(void (^)(NSString *msg))successBlock failure:(void (^)(NSInteger code, NSString *msg))failureBlock;

/**
 CA 登录
 备注：此接口暂时只有RSA的可以使用
 
 条件：需先调用“生成证书”接口
 
 @param voucherId 凭证号
 @param qrcodeResult 接入方扫描二维码得到的内容(可选) qrcodeResult为空，进入二维码扫描  有值跳过二维码
 @param popComfirmDialog true-弹出确定CA登录的对话框，false-不弹出确定CA登录的对话框
 @param autoFinish 输入签署密码后自动校验密码是否正确，false-输入6位签署密码后需要点击确定按钮校验
 @param successBlock 成功回调 返回CaloginModel对象
 @param failureBlock 失败回调
 */
- (void)caLogin:(NSString *)voucherId qrcodeResult:(NSString *)qrcodeResult popComfirmDialog:(BOOL)popComfirmDialog autoFinish:(BOOL)autoFinish success:(void (^)(CaloginModel *calogin))successBlock failure:(void (^)(NSInteger code, NSString *msg))failureBlock;

/**
 单个文件签署号签署
 
 条件：需先调用“生成证书”接口
 备注：此接口暂时只有RSA的可以使用
 
 @param voucherId 凭证号
 @param signSerial 签署号
 @param isProgressbar 是否需要loading YES：有loading， NO：无loading
 @param autoFinish 是否输入签署密码后自动校验密码
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)signFile:(NSString *)voucherId signSerial:(NSString *)signSerial isProgressbar:(BOOL)isProgressbar autoFinish:(BOOL)autoFinish success:(void(^)(void))successBlock failure:(void(^)(NSInteger code, NSString * msg))failureBlock;

/**
多文件签署号签署
 备注：此接口暂时只有RSA的可以使用
 
 条件：需先调用“生成证书”接口
 
 @param voucherId 凭证号
 @param signSerial 批量签署号
 @param isProgressbar 是否需要loading YES：有loading， NO：无loading
 @param autoFinish 是否输入签署密码后自动校验密码
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)signFiles:(NSString *)voucherId signSerial:(NSString *)signSerial isProgressbar:(BOOL)isProgressbar autoFinish:(BOOL)autoFinish success:(void (^)(ManyFilesSignature *signature))successBlock failure:(void (^)(NSInteger code, NSString *msg))failureBlock;

/**
 单个文件Hash签署
 
 条件：需先调用“生成证书”接口
 
 @param voucherId 凭证号
 @param originHash 文件的原文哈希，类型为String
 @param certType 证书类型 GDCACertType
 @param isProgressbar 是否需要loading YES：有loading， NO：无loading
 @param autoFinish 是否输入签署密码后自动校验密码
 @param successBlock 成功回调 base64之后的p7数据
 @param failureBlock 失败回调
 */
- (void)signHash:(NSString *)voucherId originHash:(NSString *)originHash certType:(GDCACertType)certType isProgressbar:(BOOL)isProgressbar autoFinish:(BOOL)autoFinish success:(void(^)(NSString *pk7msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock;

/**
 多文件Hash签署
 备注：此接口暂时只有RSA的可以使用
 
 条件：需先调用“生成证书”接口
 
 @param voucherId 凭证号
 @param originHashs Array<String>的原文哈希数组
 @param isProgressbar 是否需要loading YES：有loading， NO：无loading
 @param autoFinish 是否输入签署密码后自动校验密码
 @param successBlock 成功回调 返回base64之后的p7数据
 @param failureBlock 失败回调
 */
- (void)signHashs:(NSString *)voucherId originHashs:(NSArray<NSString*>*)originHashs isProgressbar:(BOOL)isProgressbar autoFinish:(BOOL)autoFinish success:(void(^)(NSArray *pkcs7datas))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock;

/**
 通过唯一业务id获取凭证号
 
 @param bizNo 唯一业务id
 @param successBlock 成功回调 返回凭证号 voucherId
 @param failureBlock 失败回调
 */
- (void)getVoucherId:(NSString *)bizNo success:(void (^)(NSString *voucherId))successBlock failure:(void (^)(NSInteger code, NSString *msg))failureBlock;

/**
 凭证号补充手机号码
 
 @param mobile 手机号码，暂时只支持国内
 @param voucherId 凭证号
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)appendPhoneNo:(NSString *)mobile voucherId:(NSString *)voucherId success:(void (^)(NSString *msg))successBlock failure:(void (^)(NSInteger code, NSString *msg))failureBlock;

/**
 深度活体鉴别
 
 @param name    身份证姓名
 @param idNO  身份证号码
 @param bizNo  活体鉴别唯一业务ID
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)deepLivingCheck:(NSString *)name idNO:(NSString *)idNO bizNo:(NSString *)bizNo success:(void (^)(NSString *msg))successBlock failure:(void (^)(NSInteger code, NSString *msg))failureBlock;

/**
 识别身份证正反面信息
 
 @param bizNo 凭证号
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)ocrIdentityForPicture:(NSString *)bizNo success:(void (^)(GDCAUserInfo *userInfo))successBlock failure:(void (^)(NSInteger code, NSString *msg))failureBlock;

/**
 快捷活体鉴别
 
 @param bizNo 唯一业务ID，由接入方传入
 @param name 身份证姓名
 @param idNO 身份证号码
 @param originalPhoto 大头贴图片数据 imageData base64EncodedString
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)easyLivingCheck:(NSString *)bizNo name:(NSString *)name idNO:(NSString *)idNO photo:(NSString *)originalPhoto success:(void (^)(NSString *msg))successBlock failure:(void (^)(NSInteger code, NSString *msg))failureBlock;

/**
 SM2证书加密
 备注：此接口暂时只有SM2的可以使用
 
 @param certModel 证书信息model
 @param encryptData 加密数据
 @param isProgressbar 是否需要loading YES：有loading， NO：无loading
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)SM2EncryptWithCert:(Certfile *)certModel encryptData:(NSString*)encryptData isProgressbar:(BOOL)isProgressbar success:(void(^)(NSString *msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock;

/**
 SM2证书解密
 备注：此接口暂时只有SM2的可以使用
 
 @param certModel 证书信息model
 @param decryptData 需要解密的数据
 @param isProgressbar 是否需要loading YES：有loading， NO：无loading
 @param autoFinish 是否输入签署密码后自动校验密码
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)SM2Decrypt:(Certfile *)certModel decryptData:(NSString*)decryptData isProgressbar:(BOOL)isProgressbar autoFinish:(BOOL)autoFinish success:(void(^)(NSString *msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock;

@end
