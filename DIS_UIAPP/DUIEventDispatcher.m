//
//  DUIEventDispatcher.m
//  DIS_UIAPP
//
//  Created by renjinkui on 2018/2/28.
//  Copyright © 2018年 JK. All rights reserved.
//

#import "DUIEventDispatcher.h"
#import "DUIApplication.h"

@implementation DUIEventDispatcher

- (id)initWithApplication:(DUIApplication *)application {
    if (self = [super init]) {
        _mainEnvironment = [[UIEventEnvironment alloc] initWithApplication:application];
    }
    return self;
}

- (void)_installEventRunLoopSources:(CFRunLoopRef)runloop {
    _runLoop = runloop;
    _eventFetcher = _mainEnvironment._application._eventFetcher;
    
    CFRunLoopSourceContext context = {
        .version = 0,
        .info = _mainEnvironment,
        .retain = NULL,
        .release = NULL,
        .copyDescription = NULL,
        .equal = NULL,
        .hash = NULL,
        .schedule = NULL,
        .cancel = NULL,
        .perform = __handleEventQueue
    };
    
    _handleEventQueueRunLoopSource =  CFRunLoopSourceCreate(NULL, -1, &context);
    CFRunLoopAddSource(runloop, _handleEventQueueRunLoopSource, kCFRunLoopCommonModes);
    CFRelease(_handleEventQueueRunLoopSource);
    
    CFRunLoopSourceContext context1 = {
        .version = 0,
        .info = self,
        .retain = NULL,
        .release = NULL,
        .copyDescription = NULL,
        .equal = NULL,
        .hash = NULL,
        .schedule = NULL,
        .cancel = NULL,
        .perform = __handleHIDEventFetcherDrain
    };
    
    _collectHIDEventsRunLoopSource =  CFRunLoopSourceCreate(NULL, -2, &context1);
    CFRunLoopAddSource(runloop, _collectHIDEventsRunLoopSource, kCFRunLoopCommonModes);
    CFRelease(_handleEventQueueRunLoopSource);
}

- (void)signalNextDelivery {
    CFRunLoopSourceSignal(_handleEventQueueRunLoopSource);
}

- (void)eventFetcherDidReceiveEvents:(id)events {
    CFRunLoopSourceSignal(_collectHIDEventsRunLoopSource);
    CFRunLoopWakeUp(_runLoop);
}

- (void)dealloc {
    CFRunLoopSourceInvalidate(_handleEventQueueRunLoopSource);
    CFRunLoopSourceInvalidate(_collectHIDEventsRunLoopSource);
}


@end
