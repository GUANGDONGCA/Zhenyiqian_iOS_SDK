//
//  GDCAAdapter.h
//  CSignSDK
//
//  Created by fisher hk on 2018/4/3.
//  Copyright © 2018年 fisher hk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface GDCAAdapter : NSObject

BOOL isIphoneX(void);

// safe area
CGFloat iPhoneXSafeAreaHeight(void);

//状态栏高度
CGFloat statusBarHeight(void);

@end
