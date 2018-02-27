//
//  DUIEvent.h
//  DIS_UIAPP
//
//  Created by renjinkui on 2018/2/27.
//  Copyright © 2018年 JK. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DUIEvent : NSObject
{
    struct __GSEvent *_gsEvent;
    struct __IOHIDEvent *_hidEvent;
    UIScreen *_cachedScreen;
    double _timestamp;
    double __initialTouchTimestamp;
}

@property (nonatomic, setter=_setTimestamp:) double timestamp;
@property (readonly, nonatomic) double _initialTouchTimestamp;
@property (readonly, nonatomic) int64_t type;
@property (readonly, nonatomic) int64_t subtype;
@property (readonly, nonatomic) NSSet *allTouches;

@end
