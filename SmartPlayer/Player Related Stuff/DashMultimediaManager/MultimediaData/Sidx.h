//
//  sidx.h
//  DASH Player
//
//  Created by DataArt Apps on 09.11.14.
//  Copyright (c) 2014 DataArt Apps. All rights reserved.
//

#import <Foundation/Foundation.h>
static NSString *const SidxConstantSize       = @"size";
static NSString *const SidxConstantType       = @"type";
static NSString *const SidxConstantOffset     = @"offset";
static NSString *const SidxConstantDuration   = @"duration";
static NSString *const SidxConstantTime       = @"time";
static NSString *const SidxConstantTimescale  = @"timescale";

@interface Sidx : NSObject
@property (nonatomic, assign) uint8_t version;
@property (nonatomic, assign) uint32_t timescale;
@property (nonatomic, assign) uint32_t earliestPresentationTime;
@property (nonatomic, assign) uint32_t firstOffset;
@property (nonatomic, assign) uint16_t referenceCount;
@property (nonatomic, strong) NSArray *references;

@property (nonatomic, strong) NSError *error;

- (NSTimeInterval)scaledDurationForReferenceNumber:(NSUInteger)referenceNumber;

-(instancetype)parseSidx:(NSData *)sidxData withFirstByteOffset:(uint32_t)byteOffset;

@end
