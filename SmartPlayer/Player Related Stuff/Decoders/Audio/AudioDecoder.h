//
//  AudioFrameExtractor.h
//  DASH Player
//
//  Created by DataArt Apps on 22.08.14.
//  Copyright (c) 2014 DataArt Apps. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../DecodeSupport/RingBuffer/RingBuffer.h"

#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavutil/time.h"
#include "libswresample/swresample.h"
#include "libavutil/opt.h"

@class AudioData;
@protocol AudioDecoderDelegate;

@interface AudioDecoder : NSObject {
    AVFormatContext *formatContext;
    AVCodecContext *codecContext;
    
    AVFrame *frame;
    AVPacket packet;
    AVPicture picture;
    AVStream *audioStream;
    
    int audioStreamIndex;
    
    int bytesRead;
    int bytesLeft;
}

- (id)initWithAudioData:(AudioData *)audioData;

@property (nonatomic, strong) RingBuffer *ringBuffer;

@property (nonatomic, assign, readonly, getter = isAudioFinished) BOOL audioIsFinished;

@property (nonatomic, weak) id <AudioDecoderDelegate> delegate;

@property (nonatomic, readonly) double duration;

- (void)startWork;

- (int)sampleRate;
- (int)channels;

- (void)quit;
- (BOOL)isQuit;

@end

@protocol AudioDecoderDelegate <NSObject>

- (void)audioDidEnd:(AudioDecoder *)audio;

@end
