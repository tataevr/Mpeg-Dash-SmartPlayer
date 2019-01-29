//
//  Support.h
//  DASH Player
//
//  Created by DataArt Apps on 06.08.14.
//  Copyright (c) 2014 DataArt Apps. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef void (^SuccessWithResponseCompletionBlock)(id response);
typedef void (^CompletionBlockWithData)(BOOL success, NSError* error, id data);
typedef void (^CompletionBlock)(BOOL success, NSError* error);
typedef void (^FailureCompletionBlock)(NSError *error);

typedef unsigned long long int MYTimeInterval;

void mat4f_LoadOrtho(float left, float right, float bottom, float top, float near, float far, float* mout);

//GLuint compileShader(GLenum type, NSString *shaderString);
//BOOL validateProgram(GLuint prog);

static double const TimerIntervalLagreValue = 1024.0;

static NSString * const UserDefaultsHistoryKey = @"UsegDefaultsHistoryKey";


@interface Support : NSObject

+ (void)showInfoAlertWithMessage:(NSString *)message;

@end
