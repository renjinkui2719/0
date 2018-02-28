//
//  DUIEventFetcher.h
//  DIS_UIAPP
//
//  Created by renjinkui on 2018/2/28.
//  Copyright © 2018年 JK. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DUIEventFetcher : NSObject
{
    NSMutableArray *_incomingHIDEvents;
    NSMutableArray *_incomingHIDEventsFiltered;
    CFRunLoopRef _cfRunLoop;
    CFRunLoopSourceRef _triggerHandOffEventsRunLoopSource;
    id _receiveBlock;
    id _addToFilteredEventsBlock;
    id _gameControllerEventFilterGenerator;
    id _watchSystemAppFilter;
    NSMutableArray *_eventFilters;
    CADisplayLink *_displayLink;
    int64_t _countOfDigitizerEventsReceivedSinceLastDisplayLinkCallback;
    bool _didDispatchOneMoveEventSinceLastDisplayLinkCallback;
    double _lastImportantEventTimestamp;
    bool _shouldSignalOnDisplayLink;
    id <UIEventFetcherSink> _eventFetcherSink;
    double _commitTimeForTouchEvents;
    NSMutableDictionary *_latestMoveDragEventsBySessionID;
    double _latestMoveDragEventTimestamp;
    double _latestMoveDragEventResendTimestamp;
}

@property (nonatomic) bool shouldSignalOnDisplayLink;
@property (nonatomic) double commitTimeForTouchEvents;
@property (retain, nonatomic) NSMutableDictionary *latestMoveDragEventsBySessionID;
@property (nonatomic) double latestMoveDragEventTimestamp;
@property (nonatomic) double latestMoveDragEventResendTimestamp;
@property (retain, nonatomic) id <UIEventFetcherSink> eventFetcherSink;

@end
