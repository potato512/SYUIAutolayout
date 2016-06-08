//
//  AutoSizeCGRect.h
//  zhangshaoyu
//
//  Created by zhangshaoyu on 15/6/11.
//  Copyright (c) 2015年 zhangshaoyu. All rights reserved.
//

#ifndef zhangshaoyu_AutoSizeCGRect_h
#define zhangshaoyu_AutoSizeCGRect_h

////////////////////////////////////////////////////////////////////////////////////

/*
 各版本尺寸
 1 iPhone4      640*960   320*480 2倍
 2 iPhone4S     640*960   320*480 2倍
 3 iPhone5      640*1136  320*568 2倍
 4 iPhone5S     640*1136  320*568 2倍
 5 iPhone5C     640*1136  320*568 2倍
 6 iPhone6      750*1334  375*667 2倍
 7 iPhone6 Plus 1242*2208 414*736 3倍
 
 各版本比例
 iPhone5，    autoSizeScaleX=1，autoSizeScaleY=1；
 iPhone6，    autoSizeScaleX=1.171875，autoSizeScaleY=1.17429577；
 iPhone6Plus，autoSizeScaleX=1.29375， autoSizeScaleY=1.295774；
*/

#define IS_IPAD_AutoSize             (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE_AutoSize           (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_RETINA_AutoSize           ([[UIScreen mainScreen] scale] >= 2.0)

#define SCREEN_WIDTH_AutoSize        ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT_AutoSize       ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH_AutoSize   (MAX(SCREEN_WIDTH_AutoSize, SCREEN_HEIGHT_AutoSize))
#define SCREEN_MIN_LENGTH_AutoSize   (MIN(SCREEN_WIDTH_AutoSize, SCREEN_HEIGHT_AutoSize))

#define IS_IPHONE_4_OR_LESS_AutoSize (IS_IPHONE_AutoSize && SCREEN_MAX_LENGTH_AutoSize < 568.0)
#define IS_IPHONE_5_AutoSize         (IS_IPHONE_AutoSize && SCREEN_MAX_LENGTH_AutoSize == 568.0)
#define IS_IPHONE_6_AutoSize         (IS_IPHONE_AutoSize && SCREEN_MAX_LENGTH_AutoSize == 667.0)
#define IS_IPHONE_6P_AutoSize        (IS_IPHONE_AutoSize && SCREEN_MAX_LENGTH_AutoSize == 736.0)

////////////////////////////////////////////////////////////////////////////////////

#define AutoSizeDelegate_AutoSize     ([[UIApplication sharedApplication] delegate])
#define AutoSizeScreenWidth_AutoSize  ([[UIScreen mainScreen] bounds].size.width)
#define AutoSizeScreenHeight_AutoSize ([[UIScreen mainScreen] bounds].size.height)

#define AutoSizeScaleX_AutoSize ((AutoSizeScreenHeight_AutoSize > 480.0) ? (AutoSizeScreenWidth_AutoSize / 320.0) : 1.0)
#define AutoSizeScaleY_AutoSize ((AutoSizeScreenHeight_AutoSize > 480.0) ? (AutoSizeScreenHeight_AutoSize / 568.0) : 1.0)

#define AutoSizeScalesX (AutoSizeScaleX_AutoSize)
#define AutoSizeScalesY (AutoSizeScaleY_AutoSize)

////////////////////////////////////////////////////////////////////////////////////

CG_INLINE CGFloat
AutoSizeCGRectGetMinX(CGRect rect)
{
    CGFloat x = rect.origin.x * AutoSizeScaleX_AutoSize;
    return x;
}

CG_INLINE CGFloat
AutoSizeCGRectGetMinY(CGRect rect)
{
    CGFloat y = rect.origin.y * AutoSizeScaleX_AutoSize;
    return y;
}

CG_INLINE CGFloat
AutoSizeCGRectGetWidth(CGRect rect)
{
    CGFloat width = rect.size.width * AutoSizeScaleX_AutoSize;
    return width;
}

CG_INLINE CGFloat
AutoSizeCGRectGetHeight(CGRect rect)
{
    CGFloat height = rect.size.height * AutoSizeScaleX_AutoSize;
    return height;
}

CG_INLINE CGPoint
AutoSizeCGPointMake(CGFloat x, CGFloat y)
{
    CGPoint point;
    point.x = x * AutoSizeScaleX_AutoSize;
    point.y = y * AutoSizeScaleY_AutoSize;
    
    return point;
}

CG_INLINE CGSize
AutoSizeCGSizeMake(CGFloat width, CGFloat height)
{
    CGSize size;
    size.width = width * AutoSizeScaleX_AutoSize;
    size.height = height * AutoSizeScaleY_AutoSize;
    
    return size;
}

CG_INLINE CGRect
AutoSizeCGRectMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height)
{
    CGRect rect;
    rect.origin.x = x * AutoSizeScaleX_AutoSize;
    rect.origin.y = y * AutoSizeScaleY_AutoSize;
    rect.size.width = width * AutoSizeScaleX_AutoSize;
    rect.size.height = height * AutoSizeScaleY_AutoSize;
    
    return rect;
}

////////////////////////////////////////////////////////////////////////////////////

// 常用

CG_INLINE CGRect
AutoSizeDidCGRectMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height)
{
    CGRect rect;
    rect.origin.x = x;
    rect.origin.y = y;
    rect.size.width = width * AutoSizeScaleX_AutoSize;
    rect.size.height = height * AutoSizeScaleY_AutoSize;
    
    return rect;
}

CG_INLINE CGRect
AutoSizeShouldCGRectMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height, BOOL autoW, BOOL autoH)
{
    CGRect rect;
    rect.origin.x = x;
    rect.origin.y = y;
    rect.size.width = (autoW ? (width * AutoSizeScaleX_AutoSize) : width);
    rect.size.height = (autoH ? (height * AutoSizeScaleY_AutoSize) : height);
    
    return rect;
}

CG_INLINE CGFloat
AutoSizeGetHeight(CGFloat height)
{
    CGFloat autoHeight = height * AutoSizeScaleY_AutoSize;
    return autoHeight;
}

CG_INLINE CGFloat
AutoSizeGetWidth(CGFloat width)
{
    CGFloat autoWidth = width * AutoSizeScaleX_AutoSize;
    return autoWidth;
}

////////////////////////////////////////////////////////////////////////////////////

#endif
