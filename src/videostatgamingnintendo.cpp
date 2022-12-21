#include "videostatgamingnintendo.h"

VideoStatGamingNintendo::VideoStatGamingNintendo(VideoInfo *vInfo, LikesIndicator likes,
                                                 CommentsIndicator comments, ViewsIndicator views)
    : VideoStatGaming(vInfo, likes, comments, views) {
}

void VideoStatGamingNintendo::calculateWeight() {
    double weight = getReactivity() * 10 + getLikes() * 30 + getComments() * 0.35;
    setWeight(weight);
}
