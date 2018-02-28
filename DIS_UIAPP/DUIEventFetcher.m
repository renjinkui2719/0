//
//  DUIEventFetcher.m
//  DIS_UIAPP
//
//  Created by renjinkui on 2018/2/28.
//  Copyright © 2018年 JK. All rights reserved.
//

#import "DUIEventFetcher.h"

static dispatch_once_t __deviceHasHighFrequencyDigitizer_onceToken_0;
static BOOL __deviceHasHighFrequencyDigitizer_hasHighFrequencyDigitizer_0;

@implementation DUIEventFetcher

- (id)init {
    if (self = [super init]) {
        _latestMoveDragEventsBySessionID = [[NSMutableDictionary alloc] init];
        _incomingHIDEvents = [[NSMutableArray alloc] init];
        _incomingHIDEventsFiltered = [[NSMutableArray alloc] init];
        _eventFilters = [[NSMutableArray alloc] init];
        _addToFilteredEventsBlock = ^{
            //___22__UIEventFetcher_init__block_invoke
        };
        [self setupThreadAndRun];
    }
    return self;
}

- (void)_addHIDEventFilter:(id)filter {
    [_eventFilters addObject:filter];
}

- (void)_removeHIDEventFilter:(id)filter {
    [_eventFilters removeObject:filter];
}

- (void)_setupFilterChain {
    for (id filter in _eventFilters.copy) {
        filter();
    }
    _receiveBlock = b;
}

- (void)setupForRunLoop:(NSRunLoop *)runloop {
    _cfRunLoop = [runloop getCFRunLoop];
    [self _setupFilterChain];
    
    CFRunLoopSourceContext context = {
        .version = 0,
        .info = self,
        .retain = NULL,
        .release = NULL,
        .copyDescription = NULL,
        .equal = NULL,
        .hash = NULL,
        .schedule = NULL,
        .cancel = NULL,
        .perform = _UIEventFetcherTriggerHandOff
    };
    
    _triggerHandOffEventsRunLoopSource =  CFRunLoopSourceCreate(NULL, -1, &context);
    CFRunLoopAddSource(_cfRunLoop, _triggerHandOffEventsRunLoopSource, kCFRunLoopCommonModes);
    CFRelease(_triggerHandOffEventsRunLoopSource);
    
    dispatch_once(&__deviceHasHighFrequencyDigitizer_onceToken_0, ^{
        //loc_B6B2BE
    })
    
    //loc_B6B22B
    if (__deviceHasHighFrequencyDigitizer_hasHighFrequencyDigitizer_0) {
        _displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(displayLinkDidFire:)];
        [_displayLink addToRunLoop:runloop forMode:NSRunLoopCommonModes];
    }
    //loc_B6B287
    BKSHIDEventRegisterEventCallbackOnRunLoop(_UIEventFetcherHandleHIDEvent, self, NULL, _cfRunLoop, kCFRunLoopCommonModes);
}

@end
