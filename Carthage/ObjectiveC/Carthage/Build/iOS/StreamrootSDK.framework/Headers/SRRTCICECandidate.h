//
//  SRRTCICECandidate.h
//  StreamrootSDK
//
//  Created by Maxime Bokobza on 05/02/16.
//  Copyright © 2016 Streamroot. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RTCIceCandidate;

@interface SRRTCICECandidate : NSObject

@property (nonatomic, copy, readonly) NSString *sdpMid;
@property (nonatomic, readonly) int sdpMLineIndex;
@property (nonatomic, copy, readonly) NSString *sdp;

- (id)initWithMid:(NSString *)sdpMid index:(int)sdpMLineIndex sdp:(NSString *)sdp;
- (NSDictionary *)JSON;
- (RTCIceCandidate *)RTCICECandidate;

@end
