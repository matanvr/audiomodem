//
//  AMPlayer.h
//  AudioModem
//
//  Created by Tarek Belkahia on 11/01/13.
//
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <NHNetworkTime/NHNetworkTime.h>
#define kNumberBuffers 3

typedef struct {
    AudioStreamBasicDescription mDataFormat;
    AudioQueueRef mQueue;
    AudioQueueBufferRef mBuffers[kNumberBuffers];
    SInt64 mCurrentPacket;
    UInt32 mNumPacketsToRead;
    UInt32 bufferByteSize;
    bool mIsRunning;
    const char * mMessage;
    UInt32 mMessageLength;
    float mTheta;
    id mSelf;
} AQPlayState;

@interface AMPlayer : NSObject
@property (nonatomic, assign) AQPlayState playState;
@property (retain, nonatomic) IBOutlet UIButton *recordButton;
@property (retain, nonatomic) IBOutlet UIButton *playButton;
@property (retain, nonatomic) IBOutlet UILabel *elapsed;
@property (retain, nonatomic) IBOutlet UITextView *messageTextView;
@property (retain, nonatomic) IBOutlet UILabel *timerBox;
- (IBAction)playMessage:(id)sender;
- (void)play:(NSString *)message;
- (void) playMusic;
@end
