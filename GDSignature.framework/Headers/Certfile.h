//
//  Certfile.h
//  GDSignatureOC
//
//  Created by fisher hk on 2018/4/12.
//  Copyright © 2018年 fisher hk. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Certfile : NSObject

@property (nonatomic, assign) NSInteger Id;  //证书id
@property (nonatomic, copy) NSString *uuid; //证书uuid
@property (nonatomic, assign) NSInteger certStatus;//证书状态：1-正常 ,
@property (nonatomic, copy) NSString *mobileName; ////手机设备名称
@property (nonatomic, copy) NSString *medium;//设备媒体uuid
@property (nonatomic, copy) NSString *signCertSerial;//签名证书序列号
@property (nonatomic, copy) NSString *certSubjectName; ////证书拥有者
@property (nonatomic, copy) NSString *signCert; ////签名证书本身
@property (nonatomic, copy) NSString *certIssuerName;//证书颁发者
@property (nonatomic, copy) NSString *certVerson;//证书版本
@property (nonatomic, copy) NSString *keyId;//keyid
@property (nonatomic, copy) NSString *creditNumber; ////信任服务号
@property (nonatomic, copy) NSString *certType; ////证书类型
@property (nonatomic, copy) NSString *certSerialNumber;//证书序列号
@property (nonatomic, copy) NSString *certNotBefore;//证书有效期 证书生效日期
@property (nonatomic, copy) NSString *certNotAfter; ////证书有效期 证书失效日期
@property (nonatomic, copy) NSString *certSigAlgName; ////证书签名算法
@property (nonatomic, copy) NSString *applyMsg; //////申请信息
@property (nonatomic, copy) NSString *busytype; ////业务类型
@property (nonatomic, copy) NSString *certName; //证书名称
@property (nonatomic, copy) NSString *certNo; //证件号
@property (nonatomic, copy) NSString *circle; //证书期限 1D/1Y
@property (nonatomic, copy) NSString *encryptCert; //加密证书本身(base64编码)
@property (nonatomic, copy) NSString *encryptCertSerial; //加密证书序列号
@property (nonatomic, copy) NSString *endDate; //结束日期
@property (nonatomic, copy) NSString *keytype; //key类型
@property (nonatomic, assign) long personId; //对应用户id
@property (nonatomic, copy) NSString *personName; //用户名
@property (nonatomic, copy) NSString *publicKey; //公钥
@property (nonatomic, copy) NSString *startDate; //开始日期
@property (nonatomic, copy) NSString *certID;

@end

