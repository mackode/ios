//
//  StreamrootSDK.h
//  StreamrootSDK
//
//  Created by Maxime Bokobza on 26/01/16.
//  Copyright © 2016 Streamroot. All rights reserved.
//

#import <UIKit/UIKit.h>


//! Project version number for StreamrootSDK.
FOUNDATION_EXPORT double StreamrootSDKVersionNumber;

//! Project version string for StreamrootSDK.
FOUNDATION_EXPORT const unsigned char StreamrootSDKVersionString[];

#import "private_imports.h"


@protocol StreamrootSDKDelegate

- (double)playbackTime;
- (NSArray<NSValue *> * _Nonnull)loadedTimeRanges;

@end


@interface StreamrootSDK : NSObject

@property (nonatomic, strong, nonnull) NSString *contentId;
@property (nonatomic, strong, nonnull) NSNumber *latency;
@property (nonatomic, strong, nonnull) NSNumber *p2pUploadOn;
@property (nonatomic, strong, nonnull) NSNumber *p2pDownloadOn;
@property (nonatomic, strong, nullable) NSURL *crowUrl;

@property (nonatomic, weak, nullable) id<StreamrootSDKDelegate> delegate;

- (instancetype _Nonnull)initWithStreamrootKey:(NSString * _Nonnull)streamrootKey manifestURL:(NSString * _Nonnull)manifestURL;
- (BOOL)start:(NSError * _Nullable * _Nullable)error;
- (NSString * _Nullable)manifestLocalURL;

- (void)stats:(void(^ _Nonnull)(NSDictionary<NSString *, id> * _Nullable))completion;

+ (void)setLoggerLevel:(SRLoggerLevel)level;
+ (void)setSignalingLogLevel:(SRLoggerLevel)level;
+ (void)setHTTPLogLevel:(SRLoggerLevel)level;

@end
