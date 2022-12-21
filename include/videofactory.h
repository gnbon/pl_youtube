#ifndef VIDEOFACTORY_H
#define VIDEOFACTORY_H

#include <map>

#include "videoinfo.h"
#include "videostat.h"

typedef std::map<KeywordString, Keyword> KeywordStringMap;

class VideoFactory {
  private:
    static KeywordStringMap keywordStrTable;

  public:
    static Keyword resolveStringtoKeyword(KeywordString keywordStr);

    static VideoInfo* createVideoInfo(Title title, KeywordString keywordStr);
    static VideoStat* createVideoStat(VideoInfo* vInfo, LikesIndicator likes,
                                      CommentsIndicator comments, ViewsIndicator views);
};

#endif  // VIDEOFACTORY_H
