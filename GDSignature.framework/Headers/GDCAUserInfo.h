//
//  GDCAUserInfo.h
//  GDSignatureOC
//
//  Created by fisher hk on 2018/4/13.
//  Copyright © 2018年 fisher hk. All rights reserved.
//用户信息

#import <Foundation/Foundation.h>

@interface GDCAUserInfo : NSObject

@property (nonatomic, copy) NSString *address;//地址
@property (nonatomic, copy) NSString *birthday;//生日
@property (nonatomic, copy) NSString *certid;//身份证id
@property (nonatomic, copy) NSString *fork;//民族

@property (nonatomic, copy) NSString *identyId; //照片的唯一id
@property (nonatomic, copy) NSString *issue_authority;//发证机构
@property (nonatomic, copy) NSString *name;//姓名
@property (nonatomic, copy) NSString *sex;//性别

@property (nonatomic, assign) NSInteger type;//正反面照，0：人像面照， 1：国徽面照
@property (nonatomic, copy) NSString *vaild_priod;//有效期
@property (nonatomic, copy) NSString *facePhotoBase64; //身份证人相面照片数据 base64EncodedString
@property (nonatomic, copy) NSString *backPhotoBase64; //身份证国徽面照片数据 base64EncodedString

@end
