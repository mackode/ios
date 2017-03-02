//
//  ViewController.swift
//  SwiftDemo
//
//  Created by Maxime Bokobza on 02/03/17.
//  Copyright © 2017 Streamroot. All rights reserved.
//

import AVFoundation
import StreamrootSDK
import AVKit

class ViewController: AVPlayerViewController, StreamrootSDKDelegate {

    internal var streamrootSDK: StreamrootSDK?
    internal let manifestUrl = "https://wowza-cloudfront.streamroot.io/liveorigin/stream4/playlist.m3u8"

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)

        self.streamrootSDK = StreamrootSDK(streamrootKey: <#streamrootKey#>, manifestURL: self.manifestUrl)
        self.streamrootSDK?.delegate = self

        do {
            try self.streamrootSDK?.start()
        } catch let error {
            print("\(error)")
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        if let localPath = self.streamrootSDK?.manifestLocalURL() {
            if let url = URL(string: localPath) {
                self.player = AVPlayer(url: url)
                self.player!.play()
            }
        }
    }

    func playbackTime() -> Double {
        if let player = self.player {
            return CMTimeGetSeconds(player.currentTime())
        }
        return 0
    }

    func loadedTimeRanges() -> [NSValue] {
        guard let player = self.player else {
            return []
        }

        let timeRanges = player.currentItem!.loadedTimeRanges
        return timeRanges.map { (value) -> NSValue in
            NSValue(timeRange: TimeRange(range: value.timeRangeValue))
        }
    }

}
