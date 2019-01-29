//
//  SegmentsManager.h
//  DASH Player
//
//  Created by DataArt Apps on 28.07.14.
//  Copyright (c) 2014 DataArt Apps. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../../../Support.h"
@class HttpClient;

@interface SegmentsManager :NSObject
@property (nonatomic, strong) NSString *lastVideoSegmentPath;
@property (nonatomic, strong) NSString *lastAudioSegmentPath;

@property (nonatomic, strong) NSData *lastVideoSegmentData;
@property (nonatomic, strong) NSData *lastAudioSegmentData;

- (void)downloadInitialVideoSegment:(NSURL *)segmentUrl withCompletionBlock:(CompletionBlockWithData)completion;
- (void)downloadVideoSegment:(NSURL *)segmentUrl withCompletionBlock:(CompletionBlock)completion;

- (void)downloadInitialAudioSegment:(NSURL *)segmentUrl withCompletionBlock:(CompletionBlock)completion;
- (void)downloadAudioSegment:(NSURL *)segmentUrl withCompletionBlock:(CompletionBlock)completion;

- (void)downloadInitialVideoSegment:(NSURL *)segmentUrl
                           witRange:(NSString *)range
                 andCompletionBlock:(CompletionBlockWithData)completion;

- (void)downloadData:(NSURL *)segmentUrl
             atRange:(NSString *)range
 withCompletionBlock:(CompletionBlockWithData)completion;
@end
