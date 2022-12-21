#ifndef VIDEOSTATMANAGER_H
#define VIDEOSTATMANAGER_H

#include <vector>

#include "rapidcsv.h"
#include "videostat.h"

typedef std::string FilePath;
typedef rapidcsv::Document Document;
typedef std::vector<VideoStat *> VideoStatVector;
typedef unsigned int Index;
typedef unsigned int VideoCount;

class VideoStatManager {
  private:
    VideoStatVector *vStats;

    VideoInfo *makeVideoInfoAtIndex(Document doc, Index index);
    VideoStat *makeVideoStatAtIndex(Document doc, VideoInfo *vInfo, Index index);
    void displayRecommandTitle();
    void displayVideoInfoAndStat(VideoInfo *vInfo, VideoStat *vStat);

  public:
    VideoStatManager();
    ~VideoStatManager();
    void registerStatsInCsv(FilePath csvFilePath);
    void recommandTopVideos(VideoCount vCnt);
};

#endif  // VIDEOSTATMANAGER_H
