//
//  XsdDurationParser.h
//  DASH Player
//
//  Created by DataArt Apps on 29.07.14.
//  Copyright (c) 2014 DataArt Apps. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum {
    XsdStateBegin = 0,
    XsdStateDigit,
    XsdStateYear,
    XsdStateMonth,
    XsdStateDay,
    XsdStateT,
    XsdStateHours,
    XsdStateMinutes,
    XsdStateSeconds,
    XsdStateDot
} XsdState;

@interface XsdDurationParser : NSObject
- (NSTimeInterval)timeIntervalFromString:(NSString *)string;
@end
