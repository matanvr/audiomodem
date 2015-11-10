# NHNetworkTime
A network time protocol client.

### About

The clock on the oldest iPhone, iTouch or iPad is not closely synchronized to the correct time. In the case of a device which is obtaining its time from the telephone system, there is a setting to enable synchronizing to the phone company time, but that time has been known to be over a minute different from the correct time.

In addition, users may change their device time and severely affect applications that rely on correct times to enforce functionality, or may set their devices clock into the past in an attempt to dodge an expiry date.

This project contains code to provide time obtained from standard time servers using the simple network time protocol (SNTP: RFC 5905). The implementation is not a rigorous as described in that document since the goal was to improve time accuracy to tens of milliSeconds, not to microseconds.

Computers using the NTP protocol usually employ it in a continuous low level task to keep track of the time on a continuous basis.  A background application uses occasional time estimates from a set of time servers to determine the best time by sampling these values over time. iOS applications are different, being more likely to want a one-time, quick estimate of the time.

### Usage

#### Cocoapod
Add below line to Podfile:  

```
pod NHNetworkTime
```  
and run `pod update` in Terminal
#### Manual
Add all file in folder NHNetworkTime to your project. Then add `CocoaAsyncSocket` use Cocoapod or add manual.

#### Simple to use
Import this whenever you want to get time:   

```
#import "NHNetworkTime.h"
```



Call `syncWithComplete:` in `- application: didFinishLaunchingWithOptions:` to synchronize time from server. Use completion block if you want:

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [[NHNetworkClock sharedNetworkClock] syncWithComplete:nil];
    return YES;
}
```

then get network time when sync complete in everywhere in your source code:

```
NSDate *networkDate = [NSDate networkDate];
```
#### More from NHNetworkClock

- Use `NSNotifcationCenter` to add observer `kNHNetworkTimeSyncCompleteNotification` to receive notification when time sync complete
- Property `isSynchronized`: Check network time synchronized or not
- Property `shouldUseSavedSynchronizedTime`: Should use offset time saved in the last synchronization before sync from server. Default is YES.
- Property `isAutoSynchronizedWhenUserChangeLocalTime`: Is auto sync when user change local time. Default is YES.

#### Custom time server
Add to project file name `ntp.hosts`, with content is time server address in every line. If file is not exist, it will use default time server. Example for `ntp.hosts` file:

```
asia.pool.ntp.org
europe.pool.ntp.org
north-america.pool.ntp.org
```


### About this source
NHNetworkClock is build from ios ntp open source from jbenet. NHNetworkClock fixed a critical bug get wrong time from origin source, and added more improvements:

- Sync function with complete block, you can
- Post notification when sync complete
- Property make you know whether sync complete or not
- Save offset time local to use immediately right after launch app, don't have to waiting for server
- Auto sync when user change local time