//
//  ANVideoPicturesList.h
//  DASH Player
//
//  Created by DataArt Apps on 20.08.14.
//  Copyright (c) 2014 DataArt Apps. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"

@class PicturesListElement;
@class VideoFrameYUV;

@interface PicturesListElement : NSObject {
    VideoFrameYUV *yuvFrame;
    PicturesListElement *next;
}

@property (nonatomic, strong) PicturesListElement *next;

@property (nonatomic, strong) VideoFrameYUV *yuvFrame;

@end


@interface VideoPicturesList : NSObject

@property (nonatomic, assign) NSUInteger count;

- (void)putPictureElement:(PicturesListElement *)videoPicture;
- (PicturesListElement *)getPictureElement;
- (void)endOfList;
- (BOOL)isEndOfList;

@end


