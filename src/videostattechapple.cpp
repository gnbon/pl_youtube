#include "videostattechapple.h"

VideoStatTechApple::VideoStatTechApple(VideoInfo *vInfo, LikesIndicator likes,
                                       CommentsIndicator comments, ViewsIndicator views)
    : VideoStatTech(vInfo, likes, comments, views) {
}

void VideoStatTechApple::calculateWeight() {
    double weight = getReactivity() * 34.48 + getLikes() * 3.32 + getViews() * 0.43;
    setWeight(weight);
}
