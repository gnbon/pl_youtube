#ifndef VIDEOSTATTECHAPPLE_H
#define VIDEOSTATTECHAPPLE_H

#include "videostattech.h"

class VideoStatTechApple : public VideoStatTech {
  public:
    VideoStatTechApple(VideoInfo *vInfo, LikesIndicator likes, CommentsIndicator comments,
                       ViewsIndicator views);
    virtual void calculateWeight();
};

#endif  // VIDEOSTATTECHAPPLE_H
