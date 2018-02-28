//
//  DUIEvent.m
//  DIS_UIAPP
//
//  Created by renjinkui on 2018/2/27.
//  Copyright © 2018年 JK. All rights reserved.
//

#import "DUIEvent.h"
#import "DUIApplication.h"

@implementation DUIEvent

- (void)dealloc {
    if (_gsEvent) {
        CFRelease(_gsEvent);
    }
    if (_hidEvent) {
        CFRelease(_hidEvent);
    }
}


- (UIEventType)type {
    return -1;
}

- (UIEventSubtype)subtype {
    return 0;
}

- (NSSet <UITouch *> *)allTouches {
    return nil;
}

- (NSSet <UITouch *> *)touchesForWindow:(UIWindow *)window {
    return nil;
}

- (NSSet <UITouch *> *)touchesForView:(UIWindow *)window {
    return nil;
}

- (NSSet <UITouch *> *)touchesForGestureRecognizer:(UIWindow *)window {
    return nil;
}

- (NSArray <UITouch *> *)coalescedTouchesForTouch:(UITouch *)touch {
    return nil;
}

- (NSArray <UITouch *> *)predictedTouchesForTouch:(UITouch *)touch {
    return nil;
}

- (id)_initWithEvent:(GSEventRef)gsevent touches:(NSArray *)touches {
    return nil;
}

- (void)_setGSEvent:(GSEventRef)gsevent {
    if (_gsEvent) {
        CFRelease(_gsEvent);
    }
    if (gsevent) {
        [self _setHIDEvent:nil];
        _gsEvent = CFRetain(gsevent);
        [self _setTimestamp:GSEventGetTimestamp(gsevent)];
    }
}

- (GSEventRef)_gsEvent {
    return _gsEvent;
}

- (void)_setHIDEvent:(struct __IOHIDEvent *)hidevent {
    _cachedScreen = nil;
    if (_hidEvent) {
        CFRelease(_hidEvent);
    }
    if (hidevent) {
        [self _setGSEvent:nil];
        _hidEvent = CFRetain(hidevent);
        [self _setTimestamp: _UIEventTimeIntervalForMachTime(IOHIDEventGetTimeStamp(hidevent))];
    }
}

- (struct __IOHIDEvent *)_hidEvent {
    return _hidEvent;
}

- (NSSet <UITouch *> *)_touchesForGestureRecognizer:(UIGestureRecognizer *)gr {
    return nil;
}

- (int)_shakeState {
    return -1;
}

- (int64_t)_moveDirection {
    return 0;
}

- (uint64_t)_focusHeading {
    return 0;
}

- (id)_triggeringPhysicalButton {
    return nil;
}

- (id)_modifiedInput {
    return nil;
}

- (id)_unmodifiedInput {
    return nil;
}

- (int64_t)_modifierFlags {
    return 0;
}

- (BOOL)_isKeyDown {
    return NO;
}

- (CGPoint)_digitizerLocation {
    return CGPointZero;
}

- (id)_init {
    return [super init];
}

- (UIScreen *)_screen {
    if (_cachedScreen) {
        return _cachedScreen;
    }
    
    UIScreen *screen = _UIEventHIDUIScreenForHIDEvent([self _hidEvent]);
    if (screen) {
        return screen;
    }
    
    screen = [UIScreen mainScreen];
    return screen;
}

- (NSSet *)_windows {
    UIWindow *keywindow = [UIApp _keyWindowForScreen:[self _screen]];
    if (keywindow) {
        return [NSSet setWithObject:keywindow];
    }
    return nil;
}

- (void)_sendEventToResponder:(id)responder {
    
}

- (void)_cleanupAfterDispatch {
    
}

- (BOOL)isKeyDown {
    return NO;
}

- (double)_wheelVelocity {
    return 0;
}

- (NSArray *)_gestureRecognizersForWindow:(UIWindow *)window {
    return nil;
}

- (double)timestamp {
    return _timestamp;
}

- (void)_setTimestamp:(double)timestamp {
    _timestamp = timestamp;
}

- (double)_initialTouchTimestamp {
    return __initialTouchTimestamp;
}

@end
