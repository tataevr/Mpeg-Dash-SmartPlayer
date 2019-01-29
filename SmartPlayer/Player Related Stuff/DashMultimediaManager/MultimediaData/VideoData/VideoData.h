//
//  VideoData.h
//  DASH Player
//
//  Created by DataArt Apps on 05.09.14.
//  Copyright (c) 2014 DataArt Apps. All rights reserved.
//

#import "MultimediaData.h"
#import "../../../Support.h"

@interface VideoData : MultimediaData

@property (nonatomic, assign, readonly) NSInteger expectedFramesNumber;

@property (nonatomic, assign) AVRational framerate;
@property (nonatomic, assign) MYTimeInterval duration;
@property (nonatomic, assign) NSTimeInterval timeSinceMediaBeginning;

@end
