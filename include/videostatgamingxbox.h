#ifndef VIDEOSTATGAMINGXBOX_H
#define VIDEOSTATGAMINGXBOX_H

#include "videostatgaming.h"

class VideoStatGamingXbox : public VideoStatGaming {
  public:
    VideoStatGamingXbox(VideoInfo *vInfo, LikesIndicator likes, CommentsIndicator comments,
                        ViewsIndicator views);
};

#endif  // VIDEOSTATGAMINGXBOX_H
