//
//  ManyFilesSignature.h
//  GDSignatureOC
//
//  Created by fisher hk on 2018/4/17.
//  Copyright © 2018年 fisher hk. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ManyFilesSignature : NSObject

@property (nonatomic, assign) NSInteger Id;
@property (nonatomic, copy) NSString *signCertUuid;
@property (nonatomic, copy) NSString *signCertId;
@property (nonatomic, strong) NSArray *fileDetailTransfers;

@end

@interface ManyFilesHash : NSObject

@property (nonatomic, copy) NSString *signHash;
@property (nonatomic, assign) NSInteger Id;

@end

