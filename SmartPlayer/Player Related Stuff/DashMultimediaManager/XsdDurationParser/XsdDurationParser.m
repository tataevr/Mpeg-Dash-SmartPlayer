//
//  XsdDurationParser.m
//  DASH Player
//
//  Created by DataArt Apps on 29.07.14.
//  Copyright (c) 2014 DataArt Apps. All rights reserved.
//

#import "XsdDurationParser.h"
@interface XsdDurationParser ()
@property (nonatomic, strong) NSNumber * years;
@property (nonatomic, strong) NSNumber * months;
@property (nonatomic, strong) NSNumber * days;
@property (nonatomic, strong) NSNumber * hours;
@property (nonatomic, strong) NSNumber * minutes;
@property (nonatomic, strong) NSNumber * seconds;

@end

/*
 * Parser doesn't check input string to be valid.
 * It assumes that string represents duration in correct format.
 */

@implementation XsdDurationParser

#pragma mark - public
- (void)parseDurationFromString:(NSString *)durationString {
    NSString *upperCaseString = [durationString uppercaseString];
    if ([upperCaseString characterAtIndex:0] != 'P'){
        return;
    }
    
    int i = 0;
    
    unichar ch = 0;
    XsdState prevState = 0;
    XsdState prevNotDigitState = 0;
    XsdState state = 0;
    
    NSMutableArray *digitsArray;
    
    while (i < upperCaseString.length) {
        ch = [upperCaseString characterAtIndex:i++];
        state = [self stateForChar:ch];
        
        switch (state) {
            case XsdStateBegin:{
                prevNotDigitState = XsdStateBegin;
                digitsArray = [NSMutableArray array];
            }
                break;
            case XsdStateYear:{
                prevNotDigitState = XsdStateYear;
                NSAssert(digitsArray.count, @"digitsArray cannot be empty.");
                self.years = [self numberFromArray:digitsArray];
                digitsArray = [NSMutableArray array];
            }
                break;
            case XsdStateMonth:{
                prevNotDigitState = XsdStateMonth;
                NSAssert(digitsArray.count, @"digitsArray cannot be empty.");
                self.months = [self numberFromArray:digitsArray];
                digitsArray = [NSMutableArray array];
            }
                break;
            case XsdStateDay:{
                prevNotDigitState = XsdStateDay;
                NSAssert(digitsArray.count, @"digitsArray cannot be empty.");
                self.days = [self numberFromArray:digitsArray];
                digitsArray = [NSMutableArray array];
            }
                break;
            case XsdStateT:{
                prevNotDigitState = XsdStateT;
            }
                break;
            case XsdStateHours:{
                prevNotDigitState = XsdStateHours;
                NSAssert(digitsArray.count, @"digitsArray cannot be empty.");
                self.hours = [self numberFromArray:digitsArray];
                digitsArray = [NSMutableArray array];
            }
                break;
            case XsdStateMinutes:{
                prevNotDigitState = XsdStateMinutes;
                NSAssert(digitsArray.count, @"digitsArray cannot be empty.");
                self.minutes = [self numberFromArray:digitsArray];
                digitsArray = [NSMutableArray array];
            }
                break;
            case XsdStateSeconds:{
                prevNotDigitState = XsdStateSeconds;
                NSAssert(digitsArray.count, @"digitsArray cannot be empty.");
                self.seconds = [self numberFromArray:digitsArray];
                digitsArray = [NSMutableArray array];
            }
                break;
            case XsdStateDot:{
                [digitsArray addObject:@((short)ch)];
            }
                break;
            case XsdStateDigit:{
                [digitsArray addObject:@((short)ch)];
            }
                break;
                
            default:
                break;
        }
        prevState = state;
    }
}

- (NSTimeInterval)timeIntervalFromString:(NSString *)string {
    [self parseDurationFromString:string];
    NSTimeInterval duration = 0.0;
    duration += [self.hours   floatValue] * 3600.0f;
    duration += [self.minutes floatValue] * 60.0f;
    duration += [self.seconds floatValue];
    return duration;
}

#pragma mark - private
- (XsdState)stateForChar:(unichar)ch {
    static BOOL tOccured = NO;
    if( ch >= (unichar)'0' && ch <= (unichar)'9'){
        return XsdStateDigit;
    } else {
        XsdState s = 0;
        switch (ch) {
            case 'T':
                s = XsdStateT;
                tOccured = YES;
                break;
                
            case 'P':
                s = XsdStateBegin;
                break;
                
            case 'Y':
                s = XsdStateYear;
                break;
                
            case 'M':
                s = tOccured ? XsdStateMinutes : XsdStateMonth;
                break;
                
            case 'D':
                s = XsdStateDay;
                break;
                
            case 'H':
                s = XsdStateHours;
                break;
                
            case 'S':
                s = XsdStateSeconds;
                break;
                
            case '.':
                s = XsdStateDot;
                break;
                
            default:
                s = 0;
                break;
        }
        return s;
    }
    return 0;
}

- (NSNumber *)numberFromArray:(NSArray *)array {
    unichar *chars = calloc(array.count, sizeof(unichar));
    for (int i = 0; i < array.count; ++i){
        NSNumber *num = array[i];
        chars[i] = [num shortValue];
    }
    NSString *str = [NSString stringWithCharacters:chars length:array.count];
    free(chars);
    return @([str floatValue]);
}

@end
