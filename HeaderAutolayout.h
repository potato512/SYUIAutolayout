//
//  HeaderAutolayout.h
//  DemoImageAutolayout
//
//  Created by zhangshaoyu on 15/7/31.
//  Copyright (c) 2015年 zhangshaoyu. All rights reserved.
//  多屏幕适配方法（3.5，4.0，4.7，5.5）

#ifndef DemoImageAutolayout_Header_h
#define DemoImageAutolayout_Header_h

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
 iPhone5，    AutolayoutScaleX = 1，AutolayoutScaleY = 1；
 iPhone6，    AutolayoutScaleX = 1.171875，AutolayoutScaleY = 1.17429577；
 iPhone6Plus，AutolayoutScaleX = 1.29375， AutolayoutScaleY = 1.295774；
 */

#define IS_IPAD_Autolayout             (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE_Autolayout           (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_RETINA_Autolayout           ([[UIScreen mainScreen] scale] >= 2.0)

#define SCREEN_WIDTH_Autolayout        ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT_Autolayout       ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH_Autolayout   (MAX(SCREEN_WIDTH_Autolayout, SCREEN_HEIGHT_Autolayout))
#define SCREEN_MIN_LENGTH_Autolayout   (MIN(SCREEN_WIDTH_Autolayout, SCREEN_HEIGHT_Autolayout))

#define IS_IPHONE_4_OR_LESS_Autolayout (IS_IPHONE_Autolayout && SCREEN_MAX_LENGTH_Autolayout < 568.0)
#define IS_IPHONE_5_Autolayout         (IS_IPHONE_Autolayout && SCREEN_MAX_LENGTH_Autolayout == 568.0)
#define IS_IPHONE_6_Autolayout         (IS_IPHONE_Autolayout && SCREEN_MAX_LENGTH_Autolayout == 667.0)
#define IS_IPHONE_6P_Autolayout        (IS_IPHONE_Autolayout && SCREEN_MAX_LENGTH_Autolayout == 736.0)

////////////////////////////////////////////////////////////////////////////////////

#define Delegate_Autolayout     ([[UIApplication sharedApplication] delegate])
#define ScreenWidth_Autolayout  ([[UIScreen mainScreen] bounds].size.width)
#define ScreenHeight_Autolayout ([[UIScreen mainScreen] bounds].size.height)

#define ScaleX_Autolayout ((ScreenHeight_Autolayout > 480.0) ? (ScreenWidth_Autolayout / 320.0) : 1.0)
#define ScaleY_Autolayout ((ScreenHeight_Autolayout > 480.0) ? (ScreenHeight_Autolayout / 568.0) : 1.0)

////////////////////////////////////////////////////////////////////////////////////

CG_INLINE CGFloat
CGRectGetMinXAutolayout(CGRect rect)
{
    CGFloat x = rect.origin.x * ScaleX_Autolayout;
    return x;
}

CG_INLINE CGFloat
CGRectGetMinYAutolayout(CGRect rect)
{
    CGFloat y = rect.origin.y * ScaleX_Autolayout;
    return y;
}

CG_INLINE CGFloat
CGRectGetWidthAutolayout(CGRect rect)
{
    CGFloat width = rect.size.width * ScaleX_Autolayout;
    return width;
}

CG_INLINE CGFloat
CGRectGetHeightAutolayout(CGRect rect)
{
    CGFloat height = rect.size.height * ScaleX_Autolayout;
    return height;
}

CG_INLINE CGPoint
CGPointMakeAutolayout(CGFloat x, CGFloat y)
{
    CGPoint point;
    point.x = x * ScaleX_Autolayout;
    point.y = y * ScaleY_Autolayout;
    
    return point;
}

CG_INLINE CGSize
CGSizeMakeAutolayout(CGFloat width, CGFloat height)
{
    CGSize size;
    size.width = width * ScaleX_Autolayout;
    size.height = height * ScaleY_Autolayout;
    
    return size;
}

////////////////////////////////////////////////////////////////////////////////////

CG_INLINE CGRect
CGRectMakeAutolayout(CGFloat x, CGFloat y, CGFloat width, CGFloat height, BOOL layoutWidth, BOOL layoutHeight)
{
    CGRect rect;
    rect.origin.x = x;
    rect.origin.y = y;
    rect.size.width = (layoutWidth ? (width * ScaleX_Autolayout) : width);
    rect.size.height = (layoutHeight ? (height * ScaleY_Autolayout) : height);
    
    return rect;
}

CG_INLINE CGFloat
GetHeightAutolayout(CGFloat height)
{
    CGFloat autoHeight = height * ScaleY_Autolayout;
    return autoHeight;
}

CG_INLINE CGFloat
GetWidthAutolayout(CGFloat width)
{
    CGFloat autoWidth = width * ScaleX_Autolayout;
    return autoWidth;
}

////////////////////////////////////////////////////////////////////////////////////

/*
CG_INLINE CGRect
CGRectMakeAutolayout(CGFloat x, CGFloat y, CGFloat width, CGFloat height, BOOL autoWidth, BOOL autoHeight)
{
    CGRect rect;
    rect.origin.x = x;
    rect.origin.y = y;
    rect.size.width = width;
    rect.size.height = height;
    return rect;
}

FOUNDATION_EXPORT CGRect SETViewFrame(CGRect rect4 ,CGRect rect5 ,CGRect rect6 ,CGRect rect6_ )
{
    int height = (int)[UIScreen mainScreen].bounds.size.height;
    
    if (height == 480)
    {
        return rect4;
    }
    else if (height == 568)
    {
        return rect5;
    }
    else if (height == 667)
    {
        return rect6;
    }
    else if (height == 736)
    {
        return rect6_;
    }

    return rect4;
}
*/

////////////////////////////////////////////////////////////////////////////////////

#endif
