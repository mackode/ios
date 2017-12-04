//
//  DataChannelState.h
//  StreamrootSDK
//
//  Created by Maxime Bokobza on 08/02/16.
//  Copyright © 2016 Streamroot. All rights reserved.
//


typedef NS_ENUM(NSUInteger, DataChannelState) {
    DataChannelStateConnecting = 0,
    DataChannelStateOpen,
    DataChannelStateClosing,
    DataChannelStateClosed
};
