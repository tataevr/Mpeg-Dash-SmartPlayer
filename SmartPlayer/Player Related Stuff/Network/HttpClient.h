//
//  HttpClient.h
//  DASH Player
//
//  Created by DataArt Apps on 06.08.14.
//  Copyright (c) 2014 DataArt Apps. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../Support.h"


@interface HttpClient : NSObject

@property (nonatomic, assign) NSUInteger bytesDownloaded;
@property (nonatomic, assign) double timeForDownload;

@property (nonatomic, assign) NSUInteger lastBytesDownloaded;
@property (nonatomic, assign) double lastTimeForDownload;


@property (nonatomic, assign) double averageNetworkSpeed;
@property (nonatomic, assign) double lastNetworkSpeed;

+ (instancetype)sharedHttpClient;

- (void)downloadFile:(NSURL *)fileUrl
         withSuccess:(SuccessWithResponseCompletionBlock)success
             failure:(FailureCompletionBlock)failure;

- (void)downloadFile:(NSURL *)fileUrl
             atRange:(NSString *)rangeString
         withSuccess:(SuccessWithResponseCompletionBlock)success
             failure:(FailureCompletionBlock)failure;

- (NSUInteger)lastDownloadSpeed;
- (void)cancelDownloading;
@end

