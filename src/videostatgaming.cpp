#include "videostatgaming.h"

VideoStatGaming::VideoStatGaming(VideoInfo *vInfo, LikesIndicator likes, CommentsIndicator comments,
                                 ViewsIndicator views)
    : VideoStat(vInfo, likes, comments, views) {
}

void VideoStatGaming::calculateWeight() {
    WeightIndicator weight
        = getReactivity() * 100.0 + getViews() * 0.9 - getLikes() * 7.0 + getComments() * 3.0;

    setWeight(weight);
}
