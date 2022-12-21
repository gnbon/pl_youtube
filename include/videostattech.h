#ifndef VIDEOSTATTECH_H
#define VIDEOSTATTECH_H

#include "videostat.h"

class VideoStatTech : public VideoStat {
  public:
    VideoStatTech(VideoInfo *vInfo, LikesIndicator likes, CommentsIndicator comments,
                  ViewsIndicator views);
    virtual void calculateWeight();
};

#endif  // VIDEOSTATTECH_H
