#ifndef VIDEOSTATTECHGOOGLE_H
#define VIDEOSTATTECHGOOGLE_H

#include "videostattech.h"

class VideoStatTechGoogle : public VideoStatTech {
  public:
    VideoStatTechGoogle(VideoInfo *vInfo, LikesIndicator likes, CommentsIndicator comments,
                        ViewsIndicator views);
};

#endif  // VIDEOSTATTECHGOOGLE_H
