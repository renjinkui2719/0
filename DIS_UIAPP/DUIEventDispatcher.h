//
//  DUIEventDispatcher.h
//  DIS_UIAPP
//
//  Created by renjinkui on 2018/2/28.
//  Copyright © 2018年 JK. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DUIEventDispatcher : NSObject
{
    UIEventEnvironment *_mainEnvironment;
    UIEventFetcher *_eventFetcher;
    CFRunLoopSourceRef _handleEventQueueRunLoopSource;
    CFRunLoopSourceRef *_collectHIDEventsRunLoopSource;
    CFRunLoopRef *_runLoop;
}

@property (retain, nonatomic) UIEventEnvironment *mainEnvironment;

- (id)initWithApplication:(DUIApplication *)application;
- (void)_installEventRunLoopSources:(CFRunLoopRef)runloop;
- (void)signalNextDelivery;
- (void)eventFetcherDidReceiveEvents:(id)events;

@end
