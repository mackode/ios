//
//  PeerChannel.h
//  StreamrootSDK
//
//  Created by Maxime Bokobza on 04/02/16.
//  Copyright © 2016 Streamroot. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PeerChannelDelegate.h"
#import "DataChannelState.h"


@class SRRTCSessionDescription;
@class SRRTCICECandidate;
@class RTCDataChannel;


@interface PeerChannel : NSObject

@property (nonatomic, weak, nullable) id<PeerChannelDelegate> delegate;
@property (nonatomic, strong, readonly, nonnull) NSString *connectionId;

- (instancetype _Nonnull)initWithChannel:(RTCDataChannel * _Nonnull)channel connectionId:(NSString * _Nonnull)connectionId;
- (void)sendMessage:(NSString * _Nonnull)message;
- (void)sendData:(NSData * _Nonnull)data;
- (void)close;

@end
