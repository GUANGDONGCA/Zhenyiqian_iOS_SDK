//
//  UserUtils.h
//  GDCA
//
//  Created by 余藩 on 2017/3/1.
//  Copyright © 2017年 CA. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UserUtils : NSObject

+ (NSString *)getIPAddress:(BOOL)preferIPv4;

+ (NSDictionary *)getIPAddresses;

+ (NSString *)getCurrentDeviceModel;

@end
