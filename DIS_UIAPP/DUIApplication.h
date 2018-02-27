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
        uint32_t deactivatingReasonFlags: 14;
        uint32_t isLaunchedSuspended: 1;
        uint32_t calledNonSuspendedLaunchDelegate: 1;
        uint32_t calledSuspendedLaunchDelegate: 1;
        uint32_t isHandlingURL: 1;
        uint32_t statusBarShowsProgress: 1;
        uint32_t statusBarHidden: 1;
        uint32_t statusBarHiddenDefault: 1;
        uint32_t statusBarHiddenVerticallyCompact: 1;
        uint32_t blockInteractionEvents: 4;
        uint32_t receivesMemoryWarnings: 1;
        uint32_t showingProgress: 1;
        uint32_t receivesPowerMessages: 1;
        uint32_t launchEventReceived: 1;
        uint32_t activateEventReceived: 1;
        uint32_t systemIsAnimatingApplicationLifecycleEvent: 1;
        uint32_t isActivating: 1;
        uint32_t shouldExitAfterSendSuspend: 1;
        uint32_t terminating: 1;
        uint32_t isHandlingShortCutURL: 1;
        uint32_t idleTimerDisabled: 1;
        uint32_t deviceOrientation: 3;
        uint32_t delegateHandleOpenURL: 1;
        uint32_t delegateOpenURL: 1;
        uint32_t delegateOpenURLOptions: 1;
        uint32_t delegateDidReceiveMemoryWarning: 1;
        uint32_t delegateWillTerminate: 1;
        uint32_t delegateSignificantTimeChange: 1;
        uint32_t delegateWillChangeInterfaceOrientation: 1;
        uint32_t delegateDidChangeInterfaceOrientation: 1;
        uint32_t delegateWillChangeStatusBarFrame: 1;
        uint32_t delegateDidChangeStatusBarFrame: 1;
        uint32_t delegateDeviceAccelerated: 1;
        uint32_t delegateDeviceChangedOrientation: 1;
        uint32_t delegateDidBecomeActive: 1;
        uint32_t delegateWillResignActive: 1;
        uint32_t delegateDidEnterBackground: 1;
        uint32_t delegateDidEnterBackgroundWasSent: 1;
        uint32_t delegateWillEnterForeground: 1;
        uint32_t delegateWillSuspend: 1;
        uint32_t delegateDidResume: 1;
        uint32_t delegateSupportsStateRestoration: 1;
        uint32_t delegateSupportedInterfaceOrientations: 1;
        uint32_t delegateNormativeWhitePointAdaptation: 1;
        uint32_t delegateHandleSiriTask: 1;
        uint32_t delegateSupportsWatchKitRequests: 1;
        uint32_t delegateSupportsIntentForwarding: 1;
        uint32_t idleModeVisualEffectsEnabled: 1;
        uint32_t userDefaultsSyncDisabled: 1;
        uint32_t headsetButtonClickCount: 4;
        uint32_t isHeadsetButtonDown: 1;
        uint32_t isFastForwardActive: 1;
        uint32_t isRewindActive: 1;
        uint32_t shakeToEdit: 1;
        uint32_t zoomInClassicMode: 1;
        uint32_t ignoreHeadsetClicks: 1;
        uint32_t touchRotationDisabled: 1;
        uint32_t taskSuspendingUnsupported: 1;
        uint32_t taskSuspendingOnLockUnsupported: 1;
        uint32_t isUnitTests: 1;
        uint32_t requiresHighResolution: 1;
        uint32_t singleUseLaunchOrientation: 3;
        uint32_t defaultInterfaceOrientation: 3;
        uint32_t supportedInterfaceOrientationsMask: 5;
        uint32_t delegateWantsNextResponder: 1;
        uint32_t delegateWantsStatusBarTouchesEnded: 1;
        uint32_t interfaceLayoutDirectionIsValid: 1;
        uint32_t interfaceLayoutDirection: 3;
        uint32_t restorationExtended: 1;
        uint32_t normalRestorationInProgress: 1;
        uint32_t normalRestorationCompleted: 1;
        uint32_t isDelayingTintViewChange: 1;
        uint32_t isUpdatingTintViewColor: 1;
        uint32_t isHandlingMemoryWarning: 1;
        uint32_t forceStatusBarTintColorChanges: 1;
        uint32_t disableLegacyAutorotation: 1;
        uint32_t couldNotRestoreStateWhenLocked: 1;
        uint32_t disableStyleOverrides: 1;
        uint32_t legibilityAccessibilitySettingEnabled: 1;
        uint32_t viewControllerBasedStatusBarAppearance: 1;
        uint32_t fakingRequiresHighResolution: 1;
        uint32_t isStatusBarFading: 1;
        uint32_t systemWindowsSecure: 1;
        uint32_t isFrontBoardForeground: 1;
        uint32_t appSwitcherLayoutState: 2;
        uint32_t isObservingPIP: 1;
        uint32_t shouldRestoreKeyboardInputState: 1;
        uint32_t subclassOverridesInterfaceOrientation: 1;
        uint32_t isResigningActive: 1;
        uint32_t receivedUnhandledMenuButton: 1;
        uint32_t disablingBecomeFirstResponder: 1;
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
