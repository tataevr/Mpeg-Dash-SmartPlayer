
#import <Foundation/Foundation.h>

#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavutil/time.h"

@class VideoPicturesList;
@class VideoData;
@protocol VideoDecoderDelegate;

static NSString *const RuleAskNext    = @"ANRuleAskNext";
static NSString *const RuleEndDecode  = @"ANRuleEndDecode";

typedef enum {
    MovieFrameTypeAudio = 0,
    MovieFrameTypeVideo,
    MovieFrameTypeArtwork,
    MovieFrameTypeSubtitle,
} MovieFrameType;

typedef enum {
    VideoFrameFormatRGB,
    VideoFrameFormatYUV,
} VideoFrameFormat;


#pragma mark - ANVideoFrameYUV
@interface VideoFrameYUV : NSObject
@property (nonatomic) float pts;

@property (nonatomic) NSUInteger width;
@property (nonatomic) NSUInteger height;

@property (nonatomic, assign) Byte *luma;
@property (nonatomic, assign) Byte *chromaB;
@property (nonatomic, assign) Byte *chromaR;

@property (nonatomic, assign) NSUInteger lumaLength;
@property (nonatomic, assign) NSUInteger chromaBLength;
@property (nonatomic, assign) NSUInteger chromaRLength;

@end


#pragma mark - VideoFrameExtractor

@interface VideoDecoder : NSObject {
    AVFormatContext *formatContex;
    AVCodecContext *codecContext;
    
    AVFrame *pFrame;
    AVPacket packet;
    AVPicture picture;
    
    BOOL quit;
    
    int bytesRead;
    int bytesLeft;
}

@property (nonatomic, strong, readonly) VideoData *videoData;

@property (nonatomic, assign, readonly) NSInteger framesCount;

@property (nonatomic, assign, getter = isVideoFinished) BOOL videoIsFinished;

@property (nonatomic, strong) VideoPicturesList *videoPicturesList;

@property (nonatomic, weak) id <VideoDecoderDelegate> delegate;

@property (nonatomic, readonly) int sourceWidth, sourceHeight;

@property (nonatomic, readonly) double duration;

- (id)initWithVideoData:(VideoData *)videoData;

- (AVRational)movieFramerate;

- (void)startWork;

- (void)quit;
@end

@protocol VideoDecoderDelegate <NSObject>

- (void)decoderDidFinishDecoding:(VideoDecoder *)video;

@end
