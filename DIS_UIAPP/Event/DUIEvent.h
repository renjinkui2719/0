//
//  DUIEvent.h
//  DIS_UIAPP
//
//  Created by renjinkui on 2018/2/27.
//  Copyright © 2018年 JK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GraphicsServices.h"

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


- (NSSet <UITouch *> *)touchesForWindow:(UIWindow *)window;
- (NSSet <UITouch *> *)touchesForView:(UIWindow *)window;
- (NSSet <UITouch *> *)touchesForGestureRecognizer:(UIWindow *)window;
- (NSArray <UITouch *> *)coalescedTouchesForTouch:(UITouch *)touch;
- (NSArray <UITouch *> *)predictedTouchesForTouch:(UITouch *)touch;
- (id)_initWithEvent:(GSEventRef)gsevent touches:(NSArray *)touches;
- (void)_setGSEvent:(GSEventRef)gsevent;
- (GSEventRef)_gsEvent;
- (void)_setHIDEvent:(struct __IOHIDEvent *)hidevent;
- (struct __IOHIDEvent *)_hidEvent;
- (NSSet <UITouch *> *)_touchesForGestureRecognizer:(UIGestureRecognizer *)gr;
- (int)_shakeState;
- (int64_t)_moveDirection;
- (uint64_t)_focusHeading;
- (id)_triggeringPhysicalButton;
- (id)_modifiedInput;
- (id)_unmodifiedInput;
- (int64_t)_modifierFlags;
- (BOOL)_isKeyDown;;
- (CGPoint)_digitizerLocation;
- (id)_init;
- (UIScreen *)_screen;
- (NSSet *)_windows;
- (void)_sendEventToResponder:(id)responder;
- (void)_cleanupAfterDispatch;
- (BOOL)isKeyDown;
- (double)_wheelVelocity;
- (NSArray *)_gestureRecognizersForWindow:(UIWindow *)window;

@end
