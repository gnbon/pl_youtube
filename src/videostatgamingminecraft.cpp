#include "videostatgamingminecraft.h"

VideoStatGamingMinecraft::VideoStatGamingMinecraft(VideoInfo *vInfo, LikesIndicator likes,
                                                   CommentsIndicator comments, ViewsIndicator views)
    : VideoStatGaming(vInfo, likes, comments, views) {
}

void VideoStatGamingMinecraft::calculateWeight() {
    double weight = getReactivity() * 1.45 + getViews() * 0.24 - getComments() * 36.34;
    setWeight(weight);
}
