//
//  DownloadOperation.h
//  DASH Player
//
//  Created by DataArt Apps on 07.08.14.
//  Copyright (c) 2014 DataArt Apps. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../Operation/Operation.h"
#import "../Support.h"

@interface DownloadOperation : NSObject

-(id)initWithUrl:(NSURL *)url;

@property (nonatomic, strong) SuccessWithResponseCompletionBlock success;
@property (nonatomic, strong) FailureCompletionBlock failure;
@property (nonatomic, strong) void (^statisticBlock)();

@property (nonatomic, strong) NSCondition *condition;

@property (nonatomic, assign) NSUInteger bytesDownloaded;
@property (nonatomic, assign) double timeForDownload;

@property (nonatomic, strong) NSMutableURLRequest *urlRequest;

- (void)lauchDownloading;
- (void)cancelDownloading;
@end
