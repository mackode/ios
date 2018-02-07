//
//  SRLogger.h
//  StreamrootSDK
//
//  Created by Maxime Bokobza on 09/02/16.
//  Copyright © 2016 Streamroot. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SRLoggerLevel.h"

@interface SRLogger : NSObject

@property (nonatomic) SRLoggerLevel level;
@property (nonatomic) SRLoggerLevel httpLevel;
@property (nonatomic) SRLoggerLevel proxyLevel;
@property (nonatomic) SRLoggerLevel signalingLevel;

+ (SRLogger * _Nonnull)sharedInstance;

- (void)logWithLevel:(SRLoggerLevel)level scope:(NSString * _Nullable)scope format:(NSString * _Nonnull)format, ...;
- (void)log:(NSString * _Nonnull)message level:(SRLoggerLevel)level scope:(NSString * _Nullable)scope;

- (void)errorWithScope:(NSString * _Nullable)scope format:(NSString * _Nonnull)format, ...;
- (void)error:(NSString * _Nonnull)message scope:(NSString * _Nullable)scope;

- (void)warningWithScope:(NSString * _Nullable)scope format:(NSString * _Nonnull)format, ...;
- (void)warning:(NSString * _Nonnull)message scope:(NSString * _Nullable)scope;

@end
