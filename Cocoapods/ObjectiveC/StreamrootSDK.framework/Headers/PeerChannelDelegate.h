//
//  PeerChannelDelegate.h
//  StreamrootSDK
//
//  Created by Maxime Bokobza on 08/02/16.
//  Copyright © 2016 Streamroot. All rights reserved.
//

#import "DataChannelState.h"

@class SRRTCSessionDescription;
@class SRRTCICECandidate;
@class PeerChannel;


@protocol PeerChannelDelegate <NSObject>

- (void)dataChannelDidReceiveMessage:(NSData * _Nonnull)data
                            isBinary:(BOOL)binary
                        connectionId:(NSString * _Nonnull)connectionId;
- (void)dataChannel:(PeerChannel * _Nonnull)channel
       stateChanged:(DataChannelState)state;

@end
