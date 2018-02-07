//
//  ViewController.m
//  ObjectiveCDemo
//
//  Created by Maxime Bokobza on 03/03/17.
//  Copyright © 2017 Streamroot. All rights reserved.
//

#import "ViewController.h"
#import <AVFoundation/AVFoundation.h>
#import <StreamrootSDK/StreamrootSDK.h>


@interface ViewController () <StreamrootSDKDelegate>

@property (nonatomic, strong) StreamrootSDK *streamrootSDK;

@end


@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    NSString *manifestUrl = @"https://wowza-cloudfront.streamroot.io/liveorigin/stream4/playlist.m3u8";
    self.streamrootSDK = [[StreamrootSDK alloc] initWithStreamrootKey:<#StreamrootKey#> manifestURL:manifestUrl];

    self.streamrootSDK.delegate = self;

    NSError *error;
    BOOL started = [self.streamrootSDK start:&error];
    if (error || !started) {
        // Handle error
        NSLog(@"error: %@", error);
    }

    NSURL *url = [[NSURL alloc] initWithString:[self.streamrootSDK manifestLocalURL]];
    self.player = [[AVPlayer alloc] initWithURL:url];
    [self.view setNeedsLayout];
    [self.view layoutIfNeeded];
    [self.streamrootSDK displayStatsOnView:self.contentOverlayView];
}

- (void)viewDidDisappear:(BOOL)animated {
  [self.streamrootSDK stop];
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
    
}


@end
