#ifndef VIDEOSTATGAMING_H
#define VIDEOSTATGAMING_H

#include "videostat.h"

class VideoStatGaming : public VideoStat {
  public:
    VideoStatGaming(VideoInfo *vInfo, LikesIndicator likes, CommentsIndicator comments,
                    ViewsIndicator views);
    virtual void calculateWeight();
};

#endif  // VIDEOSTATGAMING_H
