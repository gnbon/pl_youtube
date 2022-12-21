#include "videostattech.h"

VideoStatTech::VideoStatTech(VideoInfo *vInfo, LikesIndicator likes, CommentsIndicator comments,
                             ViewsIndicator views)
    : VideoStat(vInfo, likes, comments, views) {
}

void VideoStatTech::calculateWeight() {
    double weight = getReactivity() * 6.37 + getLikes() * 3 - getViews() * 0.0098;
    setWeight(weight);
}
