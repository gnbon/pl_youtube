#ifndef VIDEOSTAT_H
#define VIDEOSTAT_H

#include "videoinfo.h"

// base features indicators
typedef unsigned int LikesIndicator;
typedef unsigned int CommentsIndicator;
typedef unsigned int ViewsIndicator;

// derived features indicators
typedef unsigned int ParticipationIndicator;
typedef double ReactivityIndicator;
typedef double WeightIndicator;

class VideoStat {
  private:
    VideoInfo *vInfo;

    LikesIndicator likes;
    CommentsIndicator comments;
    ViewsIndicator views;

    ParticipationIndicator participation;
    ReactivityIndicator reactivity;
    WeightIndicator weight;

    void calculateParticipation();
    void calculateReactivity();

  public:
    VideoStat(VideoInfo *vInfo, LikesIndicator likes, CommentsIndicator comments,
              ViewsIndicator views);
    virtual ~VideoStat();

    virtual void calculateWeight() = 0;

    VideoInfo *getVideoInfo();
    LikesIndicator getLikes();
    CommentsIndicator getComments();
    ViewsIndicator getViews();

    void setLikes(LikesIndicator likes);
    void setComments(CommentsIndicator comments);
    void setViews(ViewsIndicator views);

    ParticipationIndicator getParticipation();
    ReactivityIndicator getReactivity();
    WeightIndicator getWeight();

    void setParticipation(ParticipationIndicator partition);
    void setReactivity(ReactivityIndicator reactivity);
    void setWeight(WeightIndicator weight);
};

#endif  // VIDEOSTAT_H
