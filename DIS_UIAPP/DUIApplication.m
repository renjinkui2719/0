//
//  DUIApplication.m
//  DIS_UIAPP
//
//  Created by renjinkui on 2018/2/25.
//  Copyright © 2018年 JK. All rights reserved.
//

#import "DUIApplication.h"
#import <objc/runtime.h>
#import "GraphicsServices.h"

static BOOL __RegisterAsSystemApp;
static BOOL __ShouldMakeUIForDefaultPNG;
static dispatch_once_t _UIApplicationIsExtension_once;
static BOOL _UIApplicationIsExtension_result;
static dispatch_once_t _UIApplicationUsesAlternateUI_onceToken;
static BOOL _UIApplicationUsesAlternateUI__UIApplicationUsesAlternateUIValue;
static FBSUIApplicationSystemService *__systemAppService;
static NSMutableArray *__UIApplicationScenes;
static FBSUIApplicationWorkspace *__workspace;
static void * __UIApplicationDelegateCreatedInMain = &__UIApplicationDelegateCreatedInMain;
static dispatch_once_t __fetchedInternalDeviceOnceToken_1;
static BOOL __isInternalDevice_1;
static dispatch_once_t __UIGetUIKitAlwaysSetsTransactionInputTimeAssumingInternal_onceToken;
static BOOL __hasCachedUIKitAlwaysSetsTransactionInputTime;
static BOOL __cachedUIKitAlwaysSetsTransactionInputTime;
static BOOL __calledRunWithMainScene;
static CFRunLoopObserverRef __beforeCARunLoopObserver;
static CFRunLoopObserverRef __afterCARunLoopObserver;
static CFRunLoopObserverRef __poolEnterRunLoopObserver;
static CFRunLoopObserverRef __poolExitRunLoopObserver;

void _UIApplicationHandleEvent(GSEventRef gsevent) {
    @autoreleasepool {
        if (GSEventShouldRouteToFrontMost(gsevent)) {
            GSEventRemoveShouldRouteToFrontMost(gsevent);
            
            int type = GSEventGetType(gsevent);
            
            //xxx
        }
        
        //loc_4FB28
        UIEvent *event = [UIApp _event];
        
        [event _setGSEvent:gsevent];
        //...log
        
        //loc_4FB77
        if ((!UIApp.isIgnoringInteractionEvents && UIApp.systemIsAnimatingApplicationLifecycleEvent)
            || ![UIApp _isInteractionEvent:gsevent]
            ) {
            //loc_4FBC2
            [UIApp sendEvent:event];
        }
        
        //loc_4FBF7
        //loc_4FC00
    }
    
    if ([CATransition currentState] == 0) {
        //loc_4FC49
        dispatch_once(&__fetchedInternalDeviceOnceToken_1, ^{
            //loc_4FD09
            //___block_literal_global_4811
        });
        if (__isInternalDevice_1) {
            //loc_4FD21
            dispatch_once(&__fetchedInternalDeviceOnceToken_1, ^{
                //loc_4FE40
                //___block_literal_global_4817
            });
            //loc_4FD2F
            if (!__hasCachedUIKitAlwaysSetsTransactionInputTime) {
                NSUserDefaults *defaults = _UIKitUserDefaults();
                __cachedUIKitAlwaysSetsTransactionInputTime = [[defaults objectForKey:@"UIKitAlwaysSetsTransactionInputTime"] boolValue];
                __hasCachedUIKitAlwaysSetsTransactionInputTime = YES;
                //loc_4FE29
            }
            //loc_4FE29
            if (__cachedUIKitAlwaysSetsTransactionInputTime != 0) {
                //loc_4FC20
                [CATransaction setInputTime: _UIEventTimeIntervalForMachTime(GSEventGetHIDTimestamp())];
            }
            else {
                //loc_4FC64
            }
        }
        else {
            //loc_4FC64
        }
    }
    else {
        //loc_4FC20
        [CATransaction setInputTime: _UIEventTimeIntervalForMachTime(GSEventGetHIDTimestamp())];
    }
}

int _DUIApplicationMainPreparations(int argc, char **  argv, NSString *  principalClassName, NSString *  delegateClassName) {
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(queue, ^{
        //___block_literal_global_4485
    });
    dispatch_async(queue, ^{
        //___block_literal_global_4488
    });
    
    if (argc >= 2) {
        for (int i = 1; i < argc; i++){
            char *arg = argv[i];
            if (strcmp(arg, "-BuildDefaultPNG") == 0) {
                __ShouldMakeUIForDefaultPNG = YES;
            }
            else if (strcmp(arg, "-RegisterForSystemEvents") == 0 || strcmp(arg, "--RegisterForSystemEvents") == 0) {
                __RegisterAsSystemApp = YES;
            }
        }
    }
    
    //loc_29087
    BKSDisplayServicesStart();
    UIApplicationInitialize();
    
    if (!principalClassName) {
        principalClassName = NSBundle.mainBundle.infoDictionary[@"NSPrincipalClass"];
    }
    //loc_29110
    Class principalClass = nil;
    if (principalClassName.length) {
        principalClass = NSClassFromString(principalClassName);
        NSCAssert(principalClass, @"Unable to instantiate the UIApplication subclass instance. No class named %@ is loaded.", principalClassName);
    }
    else {
        principalClass = DUIApplication.class;
    }
    //loc_29249
    GSEventRegisterEventCallBack(_UIApplicationHandleEvent);
    UIEventFetcher *eventFetcher = [UIEventFetcher new];
    
    __RegisterAsSystemApp = [[principalClass class] registerAsSystemApp];
    
    dispatch_once(&_UIApplicationIsExtension_once, ^{
        //loc_295EE
    });
    //loc_2929E
    if (_UIApplicationIsExtension_result) {
        GSEventInitializeAsExtension();
    }
    else {
        GSEventInitialize(__RegisterAsSystemApp);
    }
    //loc_292BA
    GSEventPushRunLoopMode(kCFRunLoopDefaultMode);
    
    [principalClass _startWindowServerIfNecessary];
    [principalClass _startStatusBarServerIfNecessary];
    
    UIApplicationInstantiateSingleton(principalClass);
    
    UIApp.eventFetcher = eventFetcher;
    
    dispatch_once(&_UIApplicationUsesAlternateUI_onceToken, ^{
        //loc_29606
    });
    
    //loc_2930F
    if (_UIApplicationUsesAlternateUI__UIApplicationUsesAlternateUIValue) {
        _UIPerformAlternateUISetup();
    }
    
    //loc_29321
    __systemAppService = [[FBSUIApplicationSystemService alloc] initWithQueue: _dispatch_main_q];
    __systemAppService.delegate = UIApp;
    
    __UIApplicationScenes = [[NSMutableArray alloc] init];
    
    __workspace = [[FBSUIApplicationWorkspace alloc] initWithSerialQueue:[DUIApplication _systemAnimationFenceExemptQueue]];
    __workspace.delegate = UIApp;
    
    [_UIRemoteKeyboards sharedRemoteKeyboards];
    
    if (UIDevice.currentDevice.userInterfaceIdiom == 1) {
        [UIClassicController sharedClassicController];
    }
    
    //loc_2947B
    if (!delegateClassName) {
        delegateClassName = NSBundle.mainBundle.infoDictionary[@"UIApplicationDelegateClass"];
        if (!delegateClassName) {
            return ;
        }
    }
    
    //loc_29507
    Class delegateClass = NSStringFromClass(delegateClassName);
    NSCAssert(delegateClass, @"Unable to instantiate the UIApplication delegate instance. No class named %@ is loaded.", delegateClassName);
    //loc_2951B
    if ([delegateClass isSubclassOfClass:DUIApplication.class]) {
        UIApp.delegate = UIApp;
    }
    else {
        //loc_29562
        id <UIApplicationDelegate> delegate = [[delegateClass alloc] init];
        UIApp.delegate = delegate;
        objc_setAssociatedObject(UIApp, __UIApplicationDelegateCreatedInMain, delegate, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
}

int DUIApplicationMain(int argc, char **  argv, NSString *  principalClassName, NSString *  delegateClassName) {
    if (_UIApplicationLinkedOnVersion == 0) {
        static dispatch_once_t __UIApplicationLinkedOnVersionOnce;
        dispatch_once(&__UIApplicationLinkedOnVersionOnce, ^{
            _UIApplicationLinkedOnVersion = dyld_get_program_sdk_version();
        });
    }
    //loc_28F23
    if (_UIApplicationLinkedOnVersion < 0x20100) {
        _DUIApplicationMainPreparations(argc, argv, principalClassName, delegateClassName);
    }
    else {
        @autoreleasepool{
            _DUIApplicationMainPreparations(argc, argv, principalClassName, delegateClassName);
        }
    }
    
    [UIApp _run];
    
    return 0;
}

void _beforeCACommitHandler(CFRunLoopObserverRef observer, CFRunLoopActivity activity, void *info) {
    
}

void _afterCACommitHandler(CFRunLoopObserverRef observer, CFRunLoopActivity activity, void *info) {
    
}

void _installAfterCACommitHandler() {
    CFRunLoopRef currentRunloop = CFRunLoopGetCurrent();
    
    if (!__beforeCARunLoopObserver) {
        CFRunLoopObserverContext context = {
            .version = NULL,
            .info = self,
            .retain = NULL,
            .release = NULL,
            .copyDescription = NULL
        };
        __beforeCARunLoopObserver = CFRunLoopObserverCreate(NULL, kCFRunLoopBeforeWaiting | kCFRunLoopExit /*0xA0*/, YES, 1999000, _beforeCACommitHandler, &context);
        CFRunLoopAddObserver(currentRunloop, __beforeCARunLoopObserver, kCFRunLoopCommonModes);
        
        
        __afterCARunLoopObserver = CFRunLoopObserverCreate(NULL, kCFRunLoopBeforeWaiting | kCFRunLoopExit /*0xA0*/, YES, 2001000, _afterCACommitHandler, &context);
        CFRunLoopAddObserver(currentRunloop, __afterCARunLoopObserver, kCFRunLoopCommonModes);
    }
    //loc_237A3
}

void _wrapRunLoopWithAutoreleasePoolHandler(CFRunLoopObserverRef observer, CFRunLoopActivity activity, void *info) {
    if (activity == kCFRunLoopExit || activity == kCFRunLoopBeforeWaiting) {
        //loc_22C81
        CFIndex count = CFArrayGetCount(info);
        id v = CFArrayGetValueAtIndex(info, CFIndex idx);
        NSPopAutoreleasePool(v);
        CFArrayRemoveValueAtIndex(info, CFIndex idx);
        if (activity == kCFRunLoopBeforeWaiting) {
            CFArrayAppendValue(info, NSPushAutoreleasePool(nil));
        }
    }
    else if (activity == kCFRunLoopEntry){
        CFArrayAppendValue(info, NSPushAutoreleasePool(nil));
    }
}

@implementation DUIApplication

- (UIEvent *)_event {
    return _event;
}

- (void)sendEvent:(UIEvent *)event {
    GSEventRef gsevent = [event _gsEvent];
    if(![self handleEvent:gsevent withNewEvent:event]) {
        return;
    }
    
    _applicationFlags.isResigningActive = NO;
    if (_eventDispatcher.mainEnvironment.eventWantsLowLatency) {
        [CATransaction setLowLatency:YES];
    }
    //loc_420D9
    NSArray *windows = [event _windows];
    for (UIWindow *window in windows) {
        [window sendEvent:event];
    }
    //loc_421BD
    if ([self _pressesEvent] == event) {
        if (_UIPressesContainsPressType(event.allPresses, 5) && !_applicationFlags.receivedUnhandledMenuButton) {
            [self _sendEventToGameControllerObserver:[event _hidEvent]];
        }
    }
}

- (void)_run {
    @autoreleasepool {
        _UIAccessibilityInitialize();
        
        [self _registerForUserDefaultsChanges];
        [self _registerForSignificantTimeChangeNotification];
        [self _registerForLanguageChangedNotification];
        [self _registerForLocaleWillChangeNotification];
        [self _registerForLocaleChangedNotification];
        [self _registerForAlertItemStateChangeNotification];
        [self _registerForKeyBagLockStatusNotification];
        [self _registerForNameLayerTreeNotification];
        [self _registerForBackgroundRefreshStatusChangedNotification];
        [self _registerForHangTracerEnabledStateChangedNotification];
        
        dispatch_once(&_UIApplicationIsExtension_once, ^{
            //loc_2416A
            //___block_literal_global_957
        });
        //loc_23FAE
        if (!_UIApplicationIsExtension_result) {
            UIStartMIGServer();
        }
        
        //loc_23FBC
        _installAfterCACommitHandler(self);
        
        [self _installAutoreleasePoolsIfNecessaryForMode:kCFRunLoopDefaultMode];
        
        [_eventDispatcher _installEventRunLoopSources:CFRunLoopGetMain()];
        
        if([self.class registerAsSystemApp] || [self isFrontBoard]) {
            //loc_24030
            _eventDispatcher._mainEnvironment._isSystemApplication = YES;
            __calledRunWithMainScene = YES;
        }
        //loc_24072
        else if([self.class _isSystemUIService]){
            id identifier = [self.class _systemUIServiceIdentifier];
            id settings = [self.class _systemUIServiceClientSettings];
            [__workspace requestSceneCreationWithIdentifier:identifier initialClientSettings:settings completion:^{
                //___block_literal_global_1004
            }];
        }
        else {
            //loc_24110
            dispatch_once(&_UIApplicationIsExtension_once, ^{
                //loc_24182
                //___block_literal_global_957
            });
            if (_UIApplicationIsExtension_result && ![self.class _wantsApplicationBehaviorAsExtension]) {
                __calledRunWithMainScene = YES;
                [self __completeAndRunAsPlugin];
            }
        }
        
    }
    
    GSEventRun();
}

- (void)_installAutoreleasePoolsIfNecessaryForMode:(CFRunLoopMode)mode {
    CFRunLoopRef currentRunloop = CFRunLoopGetCurrent();
    
    if (!__poolEnterRunLoopObserver) {
        CFMutableArrayRef array = CFArrayCreateMutable(NULL, 0, NULL);
        
        CFRunLoopObserverContext context = {
            .version = NULL,
            .info = array,
            .retain = CFRetain,
            .release = CFRelease,
            .copyDescription = CFCopyDescription
        };
        
        __poolEnterRunLoopObserver = CFRunLoopObserverCreate(NULL, kCFRunLoopEntry, YES, INT64_MIN, _wrapRunLoopWithAutoreleasePoolHandler, &context);
        __poolExitRunLoopObserver = CFRunLoopObserverCreate(NULL, kCFRunLoopBeforeWaiting | kCFRunLoopExit, YES, INT64_MIN, _wrapRunLoopWithAutoreleasePoolHandler, &context);
        
        CFRunLoopAddObserver(currentRunloop, __poolEnterRunLoopObserver, kCFRunLoopCommonModes);
        CFRunLoopAddObserver(currentRunloop, __poolExitRunLoopObserver, kCFRunLoopCommonModes);
        
        CFRelease(array);
    }
    
    //loc_22DE7
    if (!CFRunLoopContainsObserver(currentRunloop, __poolEnterRunLoopObserver, mode)) {
        CFRunLoopAddObserver(currentRunloop, __poolEnterRunLoopObserver, mode);
        CFRunLoopAddObserver(currentRunloop, __poolExitRunLoopObserver, mode);
    }
}

@end

