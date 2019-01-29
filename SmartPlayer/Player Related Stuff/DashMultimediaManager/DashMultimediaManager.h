//
//  DashMultimediaManager.h
//  DASH Player
//
//  Created by DataArt Apps on 07.08.14.
//  Copyright (c) 2014 DataArt Apps. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "Operation.h"
typedef NS_ENUM(NSUInteger, StreamType) {
    StreamTypeStatic,
    StreamTypeDynamic,
    StreamTypeNone
};

@class AudioData;
@class VideoData;
@protocol DashMultimediaMangerDelegate;

@interface DashMultimediaManager : NSObject

@property (nonatomic, weak) id <DashMultimediaMangerDelegate> delegate;

@property (nonatomic, assign) StreamType streamType;

@property (nonatomic, assign) BOOL stopped;

- (id)initWithMpdUrl:(NSURL *)mpdUrl;

- (void)launchManager;

- (void)dynamic_downloadNextVideoSegment;
- (void)dynamic_downloadNextAudioSegment;

- (void)static_downloadNextVideoSegment;
- (void)static_downloadNextAudioSegment;

- (NSTimeInterval)totalMediaDuration;
- (void)shiftVideoToPosition:(NSTimeInterval)pos;

+ (NSThread *)dashMultimediaThread;
@end

@protocol DashMultimediaMangerDelegate <NSObject>
@optional

- (void)dashMultimediaManger:(DashMultimediaManager *)manager didDownloadFirstVideoSegment:(VideoData *)videData firstAudioSegment:(AudioData *)audioData;

- (void)dashMultimediaManger:(DashMultimediaManager *)manager didDownloadVideoData:(VideoData *)videoData;

- (void)dashMultimediaManger:(DashMultimediaManager *)manager didDownloadAudioData:(AudioData *)audioData;

- (void)dashMultimediaManger:(DashMultimediaManager *)manager didFailWithMessage:(NSString *)failMessage;


@end
