#include "videostat.h"

void VideoStat::calculateParticipation() {
    participation = likes + comments;
}

void VideoStat::calculateReactivity() {
    reactivity = static_cast<double>(participation) / views;
}

VideoStat::VideoStat(VideoInfo* vInfo, LikesIndicator likes, CommentsIndicator comments,
                     ViewsIndicator views)
    : vInfo(vInfo), likes(likes), comments(comments), views(views) {
    calculateParticipation();
    calculateReactivity();
    weight = 0;
}

VideoStat::~VideoStat() {
    delete vInfo;
}

VideoInfo* VideoStat::getVideoInfo() {
    return vInfo;
}

LikesIndicator VideoStat::getLikes() {
    return likes;
}

CommentsIndicator VideoStat::getComments() {
    return comments;
}

ViewsIndicator VideoStat::getViews() {
    return views;
}

void VideoStat::setLikes(LikesIndicator likes) {
    this->likes = likes;
}

void VideoStat::setComments(CommentsIndicator comments) {
    this->comments = comments;
}

void VideoStat::setViews(ViewsIndicator views) {
    this->views = views;
}

ParticipationIndicator VideoStat::getParticipation() {
    return participation;
}

ReactivityIndicator VideoStat::getReactivity() {
    return reactivity;
}

WeightIndicator VideoStat::getWeight() {
    return weight;
}

void VideoStat::setParticipation(ParticipationIndicator partition) {
    this->participation = partition;
}

void VideoStat::setReactivity(ReactivityIndicator reactivity) {
    this->reactivity = reactivity;
}

void VideoStat::setWeight(WeightIndicator weight) {
    this->weight = weight;
}
