//
//  Encrpty.h
//  GDCASign
//
//  Created by 余藩 on 2017/4/7.
//  Copyright © 2017年 Personal. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Encrpty : NSObject

+ (NSString *)getSha256String:(NSString *)srcString;

+ (NSString *)encryptAES:(NSString *)content key:(NSString *)key;

+ (NSString *)decryptAES:(NSString*)content key: (NSString*)key;

@end
