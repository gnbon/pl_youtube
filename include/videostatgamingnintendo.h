#ifndef VIDEOSTATGAMINGNINTENDO_H
#define VIDEOSTATGAMINGNINTENDO_H

#include "videostatgaming.h"

class VideoStatGamingNintendo : public VideoStatGaming {
  public:
    VideoStatGamingNintendo(VideoInfo *vInfo, LikesIndicator likes, CommentsIndicator comments,
                            ViewsIndicator views);
    virtual void calculateWeight();
};

#endif  // VIDEOSTATGAMINGNINTENDO_H
