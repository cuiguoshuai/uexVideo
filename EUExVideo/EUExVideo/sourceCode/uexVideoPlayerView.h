/**
 *
 *	@file   	: uexVideoPlayerView.h  in EUExVideo Project .
 *
 *	@author 	: CeriNo.
 * 
 *	@date   	: Created on 16/3/15.
 *
 *	@copyright 	: 2016 The AppCan Open Source Project.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#import <Foundation/Foundation.h>


@protocol uexVideoPlayerViewDelegate;

typedef  NS_ENUM(NSInteger,uexVideoPlayerViewStatus){
    uexVideoPlayerViewStatusPaused = 0,
    uexVideoPlayerViewStatusBuffering,
    uexVideoPlayerViewStatusPlaying,
    uexVideoPlayerViewStatusFailed
};

@interface uexVideoPlayerView : UIView

//以下这些只读参数都可用于KVO
@property (nonatomic,assign,readonly)BOOL isFullScreen;//当前是否是全屏模式
@property (nonatomic,assign,readonly)BOOL isPlaying;//当前是否正在播放
@property (nonatomic,assign)BOOL isAutoEndFullScreen;
@property (nonatomic,assign,readonly)NSTimeInterval currentTime;//当前播放时间
@property (nonatomic,assign,readonly)NSTimeInterval duration;//总播放时长
@property (nonatomic,assign,readonly)NSTimeInterval bufferedDuration;//已缓冲时长
@property (nonatomic,assign,readonly)uexVideoPlayerViewStatus status;//当前状态
@property (nonatomic,assign)NSTimeInterval endTime;

@property (nonatomic,weak)id<uexVideoPlayerViewDelegate> delegate;




- (instancetype)initWithFrame:(CGRect)frame URL:(NSURL *)url;

- (void)seekToTime:(NSTimeInterval)time;
- (void)setCloseButtonHidden:(BOOL)isHidden;
- (void)setFullScreenBottonHidden:(BOOL)isHidden;
- (void)forceFullScreen;//进入全屏并且隐藏缩放按钮
- (void)playWhenPrepared;//执行此方法后player会在准备完毕之时立即开始播放；
- (void)pause;
- (void)close;

- (void)rotateToOrientation:(UIInterfaceOrientation)orientation;
@end

@protocol uexVideoPlayerViewDelegate <NSObject>

@optional
//由delegate去实现进去/退出全屏的操作
- (void)playerViewEnterFullScreenButtonDidClick:(uexVideoPlayerView *)playerView;
- (void)playerViewExitFullScreenButtonDidClick:(uexVideoPlayerView *)playerView;
    


//播放完成;
- (void)playerViewDidFinishPlaying:(uexVideoPlayerView *)playerView;


//播放器会先暂停并退出全屏,然后调用此回调方法
//通过此回调处理关闭按钮的点击事件
- (void)playerViewCloseButtonDidClick:(uexVideoPlayerView *)playerView;



//time boundary监听
- (void)playerViewDidReachEndTime:(uexVideoPlayerView *)playerView;
@end


