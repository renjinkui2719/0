//
//  DUIApplication.h
//  DIS_UIAPP
//
//  Created by renjinkui on 2018/2/25.
//  Copyright © 2018年 JK. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DUIApplication;

extern DUIApplication *UIApp;
extern int _UIApplicationLinkedOnVersion;
extern DUIApplication *UIApp;
extern DUIApplication *UIApp;
extern DUIApplication *UIApp;
extern DUIApplication *UIApp;
extern DUIApplication *UIApp;
extern DUIApplication *UIApp;
extern DUIApplication *UIApp;

@interface DUIApplication : UIResponder
{
    id <UIApplicationDelegate> _delegate;
    UIEvent *_event;
    UIEvent *_motionEvent;
    UIEvent *_remoteControlEvent;
    int64_t _remoteControlEventObservers;
    NSArray *_topLevelNibObjects;
    int64_t _networkResourcesCurrentlyLoadingCount;
    NSTimer *_hideNetworkActivityIndicatorTimer;
    UIAlertController *_editAlertController;
    UIStatusBar *_statusBar;
    int64_t _statusBarRequestedStyle;
    UIStatusBarWindow *_statusBarWindow;
    NSMutableArray *_observerBlocks;
    NSMutableArray *_postCommitActions;
    bool _postCommitActionsNeedToSynchronize;
    NSString *_mainStoryboardName;
    NSMutableArray *_tintViewDurationStack;
    NSMutableArray *_statusBarTintColorLockingControllers;
    int64_t _statusBarTintColorLockingCount;
    _UIIdleModeController *_idleModeController;
    FBSDisplayLayoutMonitor *_displayLayoutMonitor;
    int64_t _normativeWhitePointAdaptivityStyle;
    int64_t _preferredUserInterfaceStyle;
    int64_t _systemUserInterfaceStyle;
    UIEventFetcher *_eventFetcher;
    UIEventDispatcher *_eventDispatcher;
    
    struct {
        uint64_t deactivatingReasonFlags: 14;//0
        uint64_t isLaunchedSuspended: 1;//14
        uint64_t calledNonSuspendedLaunchDelegate: 1;//15
        uint64_t calledSuspendedLaunchDelegate: 1;//16
        uint64_t isHandlingURL: 1;//17
        uint64_t statusBarShowsProgress: 1;//18
        uint64_t statusBarHidden: 1;//19
        uint64_t statusBarHiddenDefault: 1;//20
        uint64_t statusBarHiddenVerticallyCompact: 1;//21
        uint64_t blockInteractionEvents: 4;//22
        uint64_t receivesMemoryWarnings: 1;//26
        uint64_t showingProgress: 1;//27
        uint64_t receivesPowerMessages: 1;//28
        uint64_t launchEventReceived: 1;//29
        uint64_t activateEventReceived: 1;//30
        uint64_t systemIsAnimatingApplicationLifecycleEvent: 1;//31
        uint64_t isActivating: 1;//32
        uint64_t shouldExitAfterSendSuspend: 1;//33
        uint64_t terminating: 1;//34
        uint64_t isHandlingShortCutURL: 1;//35
        uint64_t idleTimerDisabled: 1;//36
        uint64_t deviceOrientation: 3;//37
        uint64_t delegateHandleOpenURL: 1;//40
        uint64_t delegateOpenURL: 1;//41
        uint64_t delegateOpenURLOptions: 1;//42
        uint64_t delegateDidReceiveMemoryWarning: 1;//43
        uint64_t delegateWillTerminate: 1;//44
        uint64_t delegateSignificantTimeChange: 1;//45
        uint64_t delegateWillChangeInterfaceOrientation: 1;//46
        uint64_t delegateDidChangeInterfaceOrientation: 1;//47
        uint64_t delegateWillChangeStatusBarFrame: 1;//48
        uint64_t delegateDidChangeStatusBarFrame: 1;//49
        uint64_t delegateDeviceAccelerated: 1;//50
        uint64_t delegateDeviceChangedOrientation: 1;//51
        uint64_t delegateDidBecomeActive: 1;//52
        uint64_t delegateWillResignActive: 1;//53
        uint64_t delegateDidEnterBackground: 1;//54
        uint64_t delegateDidEnterBackgroundWasSent: 1;//55
        uint64_t delegateWillEnterForeground: 1;//56
        uint64_t delegateWillSuspend: 1;//57
        uint64_t delegateDidResume: 1;//58
        uint64_t delegateSupportsStateRestoration: 1;//59
        uint64_t delegateSupportedInterfaceOrientations: 1;//60
        uint64_t delegateNormativeWhitePointAdaptation: 1;//61
        uint64_t delegateHandleSiriTask: 1;//62
        uint64_t delegateSupportsWatchKitRequests: 1;//63
        
        uint64_t delegateSupportsIntentForwarding: 1;//0
        uint64_t idleModeVisualEffectsEnabled: 1;//1
        uint64_t userDefaultsSyncDisabled: 1;//2
        uint64_t headsetButtonClickCount: 4;//3
        uint64_t isHeadsetButtonDown: 1;//7
        uint64_t isFastForwardActive: 1;//8
        uint64_t isRewindActive: 1;//9
        uint64_t shakeToEdit: 1;//10
        uint64_t zoomInClassicMode: 1;//11
        uint64_t ignoreHeadsetClicks: 1;//12
        uint64_t touchRotationDisabled: 1;//13
        uint64_t taskSuspendingUnsupported: 1;//14
        uint64_t taskSuspendingOnLockUnsupported: 1;//15
        uint64_t isUnitTests: 1;//16
        uint64_t requiresHighResolution: 1;//17
        uint64_t singleUseLaunchOrientation: 3;//18
        uint64_t defaultInterfaceOrientation: 3;//21
        uint64_t supportedInterfaceOrientationsMask: 5;//24
        uint64_t delegateWantsNextResponder: 1;//29
        uint64_t delegateWantsStatusBarTouchesEnded: 1;//30
        uint64_t interfaceLayoutDirectionIsValid: 1;//31
        uint64_t interfaceLayoutDirection: 3;//32
        uint64_t restorationExtended: 1;//35
        uint64_t normalRestorationInProgress: 1;//36
        uint64_t normalRestorationCompleted: 1;//37
        uint64_t isDelayingTintViewChange: 1;//38
        uint64_t isUpdatingTintViewColor: 1;//39
        uint64_t isHandlingMemoryWarning: 1;//40
        uint64_t forceStatusBarTintColorChanges: 1;//41
        uint64_t disableLegacyAutorotation: 1;//42
        uint64_t couldNotRestoreStateWhenLocked: 1;//43
        uint64_t disableStyleOverrides: 1;//44
        uint64_t legibilityAccessibilitySettingEnabled: 1;//45
        uint64_t viewControllerBasedStatusBarAppearance: 1;//46
        uint64_t fakingRequiresHighResolution: 1;//47
        uint64_t isStatusBarFading: 1;//48
        uint64_t systemWindowsSecure: 1;//49
        uint64_t isFrontBoardForeground: 1;//50
        uint64_t appSwitcherLayoutState: 2;//51
        uint64_t isObservingPIP: 1;//53
        uint64_t shouldRestoreKeyboardInputState: 1;//54
        uint64_t subclassOverridesInterfaceOrientation: 1;//55
        uint64_t isResigningActive: 1;//56
        uint64_t receivedUnhandledMenuButton: 1;//57
        uint64_t disablingBecomeFirstResponder: 1;//58
    } _applicationFlags;
    
    UIColor *_defaultTopNavBarTintColor;
    UIMoveEvent *_moveEvent;
    NSMutableDictionary *_physicalKeyCommandMap;
    NSMutableOrderedSet *_physicalKeycodeMap;
    bool _alwaysHitTestsForMainScreen;
    UIWindow *_backgroundHitTestWindow;
    int _ignoredStyleOverrides;
    NSMutableSet *_actionsPendingInitialization;
    NSMutableSet *_idleTimerDisabledReasons;
    UIRepeatedAction *_keyRepeatAction;
    double _currentTimestampWhenFirstTouchCameDown;
    struct CGPoint _currentLocationWhereFirstTouchCameDown;
    bool _saveStateRestorationArchiveWithFileProtectionCompleteUntilFirstUserAuthentication;
    BKSProcessAssertion *_fenceTaskAssertion;
    BKSAnimationFenceHandle *_cachedSystemAnimationFence;
    UISystemNavigationAction *_systemNavigationAction;
    UIActivityContinuationManager *_activityContinuationManager;
    UIGestureEnvironment *__gestureEnvironment;
    UIForceStageObservable *_forceStageObservable;
    id _HIDGameControllerEventObserver;
    NSObject_OS_dispatch_queue_ *_HIDGameControllerEventQueue;
    int _simulatorShakeNotificationToken;
    bool optOutOfRTL;
    bool _isDisplayingActivityContinuationUI;
    SBSApplicationShortcutService *_shortcutService;
    id ___queuedOrientationChange;
    int64_t __expectedViewOrientation;
}
@property (readonly, nonatomic) bool supportsAlternateIcons;
@property (readonly, nonatomic) NSString *alternateIconName;
@property (nonatomic, getter=_isDisplayingActivityContinuationUI, setter=_setIsDisplayingActivityContinuationUI:) bool isDisplayingActivityContinuationUI;
@property (retain, nonatomic) SBSApplicationShortcutService *shortcutService;
@property (copy, nonatomic, setter=__setQueuedOrientationChange:) id __queuedOrientationChange;
@property (nonatomic, setter=_setApplicationActivatedAtLeastOnce:) bool _applicationActivatedAtLeastOnce;
@property (nonatomic, setter=_setExpectedViewOrientation:) int64_t _expectedViewOrientation;
@property (nonatomic, getter=_shouldOptOutOfRTL, setter=_setOptOutOfRTL:) bool optOutOfRTL;
@property (nonatomic) id <UIApplicationDelegate> delegate;
@property (readonly, nonatomic, getter=isIgnoringInteractionEvents) bool ignoringInteractionEvents;
@property (nonatomic, getter=isIdleTimerDisabled) bool idleTimerDisabled;
@property (readonly, nonatomic) UIWindow *keyWindow;
@property (readonly, nonatomic) NSArray *windows;
@property (nonatomic, getter=isNetworkActivityIndicatorVisible) bool networkActivityIndicatorVisible;
@property (readonly, nonatomic) int64_t statusBarStyle;
@property (readonly, nonatomic, getter=isStatusBarHidden) bool statusBarHidden;
@property (readonly, nonatomic) int64_t statusBarOrientation;
@property (readonly, nonatomic) double statusBarOrientationAnimationDuration;
@property (readonly, nonatomic) struct CGRect statusBarFrame;
@property (nonatomic) int64_t applicationIconBadgeNumber;
@property (nonatomic) bool applicationSupportsShakeToEdit;
@property (readonly, nonatomic) int64_t applicationState;
@property (readonly, nonatomic) double backgroundTimeRemaining;
@property (readonly, nonatomic) int64_t backgroundRefreshStatus;
@property (readonly, nonatomic, getter=isProtectedDataAvailable) bool protectedDataAvailable;
@property (readonly, nonatomic) int64_t userInterfaceLayoutDirection;
@property (readonly, nonatomic) NSString *preferredContentSizeCategory;

@end
