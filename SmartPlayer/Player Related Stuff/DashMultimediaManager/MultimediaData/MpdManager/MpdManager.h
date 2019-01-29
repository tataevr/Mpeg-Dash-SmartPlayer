//
//  SegmentLoader.h
//  DASH Player
//
//  Created by DataArt Apps on 28.07.14.
//  Copyright (c) 2014 DataArt Apps. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../../../Support.h"
@class MPD;
@class HttpClient;

@protocol  MpdManagerDelegate;

@interface MpdManager : NSObject

@property (nonatomic, weak) id<MpdManagerDelegate> delegate;

@property (nonatomic, strong) NSThread *currentThread;

- (id)initWithMpdUrl:(NSURL *)mpdUrl;
- (id)initWithMpdUrl:(NSURL *)mpdUrl parserThread:(NSThread *)thread;

- (void)checkMpdWithCompletionBlock:(CompletionBlock)completion;
- (void)updateMpd;
- (BOOL)isVideoRanged;
@end

@protocol  MpdManagerDelegate <NSObject>
@optional
-(void)mpdManager:(MpdManager *)manager didFinishParsingMpdFile:(MPD *)mpd;

@end
