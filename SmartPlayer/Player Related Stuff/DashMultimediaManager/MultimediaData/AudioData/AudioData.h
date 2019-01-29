//
//  AudioData.h
//  DASH Player
//
//  Created by DataArt Apps on 05.09.14.
//  Copyright (c) 2014 DataArt Apps. All rights reserved.
//

#import "MultimediaData.h"

@interface AudioData : MultimediaData
// on this value in seconds decoder should shift video decoding to synchronize audio and video playback
@property (nonatomic, assign) double diffFromVideo;
@end
