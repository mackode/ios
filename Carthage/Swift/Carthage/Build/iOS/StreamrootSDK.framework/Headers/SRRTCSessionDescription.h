//
//  SRRTCSessionDescription.h
//  StreamrootSDK
//
//  Created by Maxime Bokobza on 05/02/16.
//  Copyright © 2016 Streamroot. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SRRTCSessionDescription : NSObject

@property(nonatomic, copy, readonly, nonnull) NSString *sdp;
@property(nonatomic, readonly, nonnull) NSString *type;

- (instancetype _Nullable)initWithType:(NSString * _Nonnull)type sdp:(NSString * _Nonnull)sdp;

@end
