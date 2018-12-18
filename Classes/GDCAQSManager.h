//
//  GDCAQSManager.h
//  GDSignature
//
//  Created by fisher hk on 2018/10/19.
//  Copyright © 2018年 fisher hk. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class Certfile, GDCAUserInfo, CaloginModel, ManyFilesSignature;
@interface GDCAQSManager : NSObject

@property (nonatomic, copy) NSString *app_id;//
@property (nonatomic, copy) NSString *app_secret;//
@property (nonatomic, strong) UIColor *themeColor;//
@property (nonatomic, assign) BOOL isPublicSite;/// 正式环境为true 测试环境为false  默认为测试环境

@property (nonatomic, copy) NSString *clientId;//券商的 clientId
@property (nonatomic, copy) NSString *qsAppId;//券商的APP ID

@property (nonatomic, strong) UIColor *naviTitleColor;

+ (instancetype)shared;

/**
 *获取当前SDK的版本号
 *当前SDK版本 : 3.1.0
 *return  返回当前API的版本号
 */
UIKIT_EXTERN NSString* GDCASDKQSGetVersion(void);

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
 @param isProgressbar 是否需要loading YES：有loading， NO：无loading
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)createCert:(NSString *)voucherID isProgressbar:(BOOL)isProgressbar success:(void(^)(NSString *msg))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock;

/**
 证书详情
 
 条件：需先调用“生成证书”接口
 
 @param voucherId 凭证号
 @param isProgressbar 是否需要loading YES：有loading， NO：无loading
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)getCertInfo:(NSString *)voucherId isProgressbar:(BOOL)isProgressbar success:(void(^)(Certfile *cert))successBlock failure:(void(^)(NSInteger code, NSString *msg))failureBlock;

/**
 单个文件签署号签署
 
 条件：需先调用“生成证书”接口
 
 @param voucherId 凭证号
 @param clientId 券商clientId
 @param qsAppId 券商qsAppId
 @param pdfId  pdfId
 @param signPosition 签署位置
 @param stampImg 签署图片
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)qsSignFile:(NSString *)voucherId clientId:(NSString*)clientId qsAppId:(NSString *)qsAppId pdfId:(NSString *)pdfId signPosition:(NSString *)signPosition stampImg:(NSString *)stampImg success:(void(^)(void))successBlock failure:(void(^)(NSInteger code, NSString * msg))failureBlock;

@end

NS_ASSUME_NONNULL_END
