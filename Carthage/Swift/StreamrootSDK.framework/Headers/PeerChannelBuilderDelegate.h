//
//  PeerChannelBuilderDelegate.h
//  StreamrootSDK
//
//  Created by Maxime Bokobza on 28/11/16.
//  Copyright © 2016 Streamroot. All rights reserved.
//

@class PeerChannel;
@class SRRTCICECandidate;
@class SRRTCSessionDescription;


@protocol PeerChannelBuilderDelegate <NSObject>

- (void)peerConnectionDidTimeout:(NSString * _Nonnull)remotePeerId;
- (void)iceCandidatesGathered:(NSArray<SRRTCICECandidate *> * _Nonnull)iceCandidates
              forRemotePeerId:(NSString * _Nonnull)peerId
                 connectionId:(NSString * _Nonnull)connectionId;
- (void)sendOffer:(NSString * _Nonnull)toRemotePeerId
 withConnectionId:(NSString * _Nonnull)connectionId
sessionDescription:(SRRTCSessionDescription * _Nonnull)sessionDescription;
- (void)sendAnswer:(NSString * _Nonnull)toRemotePeerId
  withConnectionId:(NSString * _Nonnull)connectionId
sessionDescription:(SRRTCSessionDescription * _Nonnull)sessionDescription;
- (void)answerDeclined:(NSString * _Nonnull)connectionId remotePeerId:(NSString * _Nonnull)remotePeerId;

- (void)dataChannelDidOpen:(PeerChannel * _Nonnull)channel remotePeerId:(NSString * _Nonnull)remotePeerId;

@end
