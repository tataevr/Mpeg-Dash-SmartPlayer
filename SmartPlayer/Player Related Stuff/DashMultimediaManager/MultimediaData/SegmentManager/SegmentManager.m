//
//  SegmentsManager.m
//  DASH Player
//
//  Created by DataArt Apps on 28.07.14.
//  Copyright (c) 2014 DataArt Apps. All rights reserved.
//

#import "SegmentManager.h"
#import "MPD.h"
#import "HttpClient.h"
#import "../../../Support.h"

typedef enum {
    SegmentTypeVideo = 0,
    SegmentTypeAudio = 1
} SegmentType;

@interface SegmentsManager ()
@property (nonatomic, strong) HttpClient *client;

@property (nonatomic, strong) NSData *initialVideoSegmentData;

@property (nonatomic, strong) NSURL *videoSegmentUrl;
@property (nonatomic, strong) NSString *prelastVideoSegmentPath;

@property (nonatomic, strong) NSData *initialAudioSegmentData;

@property (nonatomic, strong) NSURL *audioSegmentUrl;
@property (nonatomic, strong) NSString *prelastAudioSegmentPath;

@end

@implementation SegmentsManager

- (id)init {
    self = [super init];
    if (self){
        self.client = [HttpClient sharedHttpClient];
    }
    return self;
}

#pragma mark
#pragma mark - initial segments

- (void)downloadInitialVideoSegment:(NSURL *)segmentUrl
                withCompletionBlock:(CompletionBlockWithData)completion
{
    [self.client downloadFile:segmentUrl
                  withSuccess:^(id response){
                      self.initialVideoSegmentData = response;
                      if (completion){
                          
                          completion(YES, nil, response);
                      }
                  }
                      failure:^(NSError *error){
                          if (completion){
                              completion(NO, error, nil);
                          }
                      }];
}

- (void)downloadInitialVideoSegment:(NSURL *)segmentUrl
                           witRange:(NSString *)range
                 andCompletionBlock:(CompletionBlockWithData)completion
{
    [self.client downloadFile:segmentUrl
                      atRange:range
                  withSuccess:^(id response){
                      self.initialVideoSegmentData = response;
                      if (completion){
                          
                          completion(YES, nil, response);
                      }
                  }
                      failure:^(NSError *error){
                          if (completion){
                              completion(NO, error, nil);
                          }
                      }];
}

- (void)downloadData:(NSURL *)segmentUrl
             atRange:(NSString *)range
 withCompletionBlock:(CompletionBlockWithData)completion
{
    [self.client downloadFile:segmentUrl
                      atRange:range
                  withSuccess:^(id response){
                      if (completion){
                          
                          completion(YES, nil, response);
                      }
                  }
                      failure:^(NSError *error){
                          if (completion){
                              completion(NO, error, nil);
                          }
                      }];
}

- (void)downloadInitialAudioSegment:(NSURL *)segmentUrl
                           witRange:(NSString *)range
                 andCompletionBlock:(CompletionBlockWithData)completion
{
    [self.client downloadFile:segmentUrl
                      atRange:range
                  withSuccess:^(id response){
                      self.initialAudioSegmentData = response;
                      if (completion){
                          
                          completion(YES, nil, response);
                      }
                  }
                      failure:^(NSError *error){
                          if (completion){
                              completion(NO, error, nil);
                          }
                      }];
}

- (void)downloadInitialAudioSegment:(NSURL *)segmentUrl
                withCompletionBlock:(CompletionBlock)completion
{
    [self.client downloadFile:segmentUrl
                  withSuccess:^(id response){
                      self.initialAudioSegmentData = response;
                      if (completion){
                          completion(YES, nil);
                      }
                  }
                      failure:^(NSError *error){
                          if (completion){
                              completion(NO, error);
                          }
                      }];
}

#pragma mark - media segments
- (void)downloadVideoSegment:(NSURL *)segmentUrl
         withCompletionBlock:(CompletionBlock)completion
{
    self.videoSegmentUrl = segmentUrl;
    __weak SegmentsManager *theWeakSelf = self;
    NSLog(@"SEGMENT_MAGER - Start downloading video segment: %@", segmentUrl);
    [self.client downloadFile:segmentUrl
                  withSuccess:^(id response){
                      __strong SegmentsManager * theStrongSelf = theWeakSelf;
                      theStrongSelf.lastVideoSegmentData = response;
                      
                      NSLog(@"SEGMENT_MAGER - Downloaded videoSegment: %@", segmentUrl);
                      if (completion){
                          completion(YES, nil);
                      }
                  }
                      failure:^(NSError *error){
                          if (completion){
                              completion(NO, error);
                          }
                      }];
}

- (void)downloadAudioSegment:(NSURL *)segmentUrl
         withCompletionBlock:(CompletionBlock)completion
{
    self.audioSegmentUrl = segmentUrl;
    __weak SegmentsManager *theWeakSelf = self;
    NSLog(@"SEGMENT_MAGER - Start downloading audio segment: %@", segmentUrl);
    [self.client downloadFile:segmentUrl
                  withSuccess:^(id response){
                      NSLog(@"SEGMENT_MAGER - Downloaded audio segment: %@", segmentUrl);
                      __strong SegmentsManager * theStrongSelf = theWeakSelf;
                      NSMutableData *newData = [NSMutableData dataWithData:theStrongSelf.initialAudioSegmentData];
                      [newData appendData:response];
                      theStrongSelf.lastAudioSegmentData = newData;
                      
                      if (completion){
                          completion(YES, nil);
                      }
                  }
                      failure:^(NSError *error){
                          if (completion){
                              completion(NO, error);
                          }
                      }];
}

@end
