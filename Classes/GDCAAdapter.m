//
//  GDCAAdapter.m
//  CSignSDK
//
//  Created by fisher hk on 2018/4/3.
//  Copyright © 2018年 fisher hk. All rights reserved.
//适配等

#import "GDCAAdapter.h"
#import "UserUtils.h"

@implementation GDCAAdapter

//适配字体大小
CGFloat adjustFont(CGFloat font) { //kScreenHeight == 667
    CGFloat _fontSize = font;
    if (kScreenHeight == 736){
        return font + 1;
    }else if (kScreenHeight == 568){
        return font - 2;
    }
    return _fontSize;
}

//适配宽度
CGFloat suitW(CGFloat width) {
    
    return kScreenWidth / 375 * width;
}

//适配高度
CGFloat suitH(CGFloat height) {
    return kScreenWidth / 375 * height;
}

//是否iPhone X
BOOL isIphoneX(void) {
    
    if (@available(iOS 11.0, *)) {
        UIEdgeInsets edgeInset = [UIApplication sharedApplication].windows.firstObject.safeAreaInsets;
        if (edgeInset.bottom > 0) {
            return YES;
        }
        return NO;
    }
    return NO;
}

// safe area
CGFloat iPhoneXSafeAreaHeight(void) {
    
    return isIphoneX() ? 34.0 : 0;
}

//状态栏高度
CGFloat statusBarHeight(void) {
    return [[UIApplication sharedApplication] statusBarFrame].size.height;
}


@end
