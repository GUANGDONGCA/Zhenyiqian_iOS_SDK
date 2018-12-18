//
//  CaloginModel.h
//  GDSignatureOC
//
//  Created by fisher hk on 2018/4/17.
//  Copyright © 2018年 fisher hk. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CaloginModel : NSObject

@property (nonatomic, copy) NSString *uuid; //签署任务唯一标识
@property (nonatomic, copy) NSString *sender; //签署任务发起人
@property (nonatomic, copy) NSString *senderId; //签署任务发起人Id
@property (nonatomic, copy) NSString *createTime; //创建时间
@property (nonatomic, copy) NSString *confirmMsg; //确认信息

@property (nonatomic, assign) NSInteger Id; //证书Id
@property (nonatomic, copy) NSString *createTimeStr; //创建时间字符串
@property (nonatomic, assign) long claimTime; //任务认领时间
@property (nonatomic, copy) NSString *claimTimeStr; //任务认领时间字符串

@property (nonatomic, assign) NSInteger signStatus; //签署状态 0:等待认领 1:待办 2:已办 4:正在生成缩略图 5:异常
@property (nonatomic, assign) NSInteger signResult; //签署结果 0 未完成  1 签署成功 2 签署拒绝 3 签署撤销 4 过期
@property (nonatomic, assign) NSInteger taskSignStatus; //任务签署状态 0 未开始 1 签署中 2 签署结束 3 签署失败
@property (nonatomic, assign) NSInteger taskSignResult; //证书Id任务签署结果 0 未完成  1 签署成功 2 签署拒绝 3 签署撤销 4 过期

@property (nonatomic, copy) NSString *doer; //签署人
@property (nonatomic, assign) long  doerId; //签署人id
@property (nonatomic, copy) NSString *finishTime; //签署时间
@property (nonatomic, copy) NSString *finishTimeStr; //签署时间字符串

@property (nonatomic, copy) NSString *companyStr; //公司名
@property (nonatomic, assign) NSInteger signType; //签名类型 1:签署 2:登录 3:授权,5:多文件
@property (nonatomic, copy) NSString *signTitle; //任务标题
@property (nonatomic, copy) NSString *signHash; //签署哈希

@property (nonatomic, copy) NSString *signCertUuid; //需要使用的签名证书uuid
@property (nonatomic, assign) long signCertId; //签名类型 1:签署 2:登录 3:授权,5:多文件
@property (nonatomic, copy) NSString *duration; //截止日期
@property (nonatomic, copy) NSString *originalFileName; //签署文件名

@property (nonatomic, copy) NSString *durationStr; //截止日期字符串
@property (nonatomic, copy) NSString *channelStr; //发起渠道名称
@property (nonatomic, copy) NSString *sessionId; //签署sessionId
@property (nonatomic, copy) NSString *busAccountName; //业务系统账户名

@end




