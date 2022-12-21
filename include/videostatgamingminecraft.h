#ifndef VIDEOSTATGAMINGMINECRAFT_H
#define VIDEOSTATGAMINGMINECRAFT_H

#include "videostatgaming.h"

class VideoStatGamingMinecraft : public VideoStatGaming {
  public:
    VideoStatGamingMinecraft(VideoInfo *vInfo, LikesIndicator likes, CommentsIndicator comments,
                             ViewsIndicator views);
    virtual void calculateWeight();
};

#endif  // VIDEOSTATGAMINGMINECRAFT_H
