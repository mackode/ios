//
//  PeerChannelBuilder.h
//  StreamrootSDK
//
//  Created by Maxime Bokobza on 28/11/16.
//  Copyright © 2016 Streamroot. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PeerChannelBuilderDelegate.h"


@interface PeerChannelBuilder : NSObject

@property (nonatomic, weak, nullable) id<PeerChannelBuilderDelegate> delegate;
@property (nonatomic, strong, nonnull, readonly) NSString *remotePeerId;

+ (void)setup;

- (instancetype _Nonnull)initWithRemotePeerId:(NSString * _Nonnull)remotePeerId
                                 connectionId:(NSString * _Nonnull)connectionId
                                      timeout:(NSTimeInterval)timeout
                                   isInitator:(BOOL)isInitator;

- (void)offer;
- (void)answerFromOfferedSdp:(NSString * _Nonnull)sdp;
- (void)answerDeclined;
- (void)receivedAcceptedAnswerSdp:(NSString * _Nonnull)sdp;
@end
