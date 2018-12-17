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

//适配字体大小
CGFloat adjustFont(CGFloat font);

//适配宽度
CGFloat suitW(CGFloat width);

//适配高度
CGFloat suitH(CGFloat height);

//是否iPhone X
BOOL isIphoneX(void);

// safe area
CGFloat iPhoneXSafeAreaHeight(void);

//状态栏高度
CGFloat statusBarHeight(void);

@end
