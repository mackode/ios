    //
    //  ViewController.m
    //  ObjectiveCDemo
    //
    //  Created by Maxime Bokobza on 03/03/17.
    //  Copyright © 2017 Streamroot. All rights reserved.
    //

#import "ObjCSampleViewController.h"
#import <AVFoundation/AVFoundation.h>
#import <StreamrootSDK/StreamrootSDK-Swift.h>

@interface ObjCSampleViewController() <DNAClientDelegate>

@property (nonatomic, strong) DNAClient *dnaClient;

@end


@implementation ObjCSampleViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //NSURL *manifestUrl = [NSURL URLWithString: @"https://demo-live.streamroot.io/index.m3u8"];
    NSURL *manifestUrl = [NSURL URLWithString: @"http://usp-demo.cf.castlabs.com/video/piff/31245689abb7c52a3d0721447bddd6cd_Tears_Of_Steel.ism/31245689abb7c52a3d0721447bddd6cd_Tears_Of_Steel.m3u8"];
    NSError *error;
    self.dnaClient = [[[DNAClient.builder dnaClientDelegate: self] latency: 30] start:manifestUrl error: &error];
    if (error || !self.dnaClient) {
        NSLog(@"error: %@", error);
    }
    
    NSURL *url = [[NSURL alloc] initWithString: self.dnaClient.manifestLocalURLPath];
    self.player = [[AVPlayer alloc] initWithURL:url];
    [self.player play];
    self.player.actionAtItemEnd = AVPlayerActionAtItemEndNone;

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(playerItemDidReachEnd:) name:AVPlayerItemDidPlayToEndTimeNotification object:[self.player currentItem]];

    [self.view setNeedsLayout];
    [self.view layoutIfNeeded];
    [self.dnaClient displayStatsOnView: self.contentOverlayView];
}

- (void)playerItemDidReachEnd:(NSNotification *)notification {
    AVPlayerItem *playerItem = [notification object];
    [playerItem seekToTime:kCMTimeZero];
}

- (void)viewDidDisappear:(BOOL)animated {
    [self.dnaClient stop];
}

- (double)playbackTime {
    return CMTimeGetSeconds([self.player currentTime]);
}

- (NSArray<NSValue *> *)loadedTimeRanges {
    if (self.player == nil) {
        return [NSArray array];
    }
    
    NSMutableArray *timeRanges = [NSMutableArray array];
    for (NSValue *value in [[self.player currentItem] loadedTimeRanges]) {
        TimeRange *timeRange = [[TimeRange alloc] initWithRange:[value CMTimeRangeValue]];
        [timeRanges addObject:[[NSValue alloc] initWithTimeRange:timeRange]];
    }
    
    return timeRanges;
}

- (void)updatePeakBitRate:(double)bitRate {
    self.player.currentItem.preferredPeakBitRate = bitRate;
}

@end
