#include "videostatmanager.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

#include "rapidcsv.h"
#include "videofactory.h"

VideoStatManager::VideoStatManager() {
    vStats = new VideoStatVector();
}

VideoStatManager::~VideoStatManager() {
    for (auto it : *vStats) {
        delete it;
    }
    delete vStats;
}

VideoInfo *VideoStatManager::makeVideoInfoAtIndex(Document doc, Index index) {
    Title title = doc.GetCell<Title>("Title", index);
    KeywordString keywordstr = doc.GetCell<KeywordString>("Keyword", index);

    return VideoFactory::createVideoInfo(title, keywordstr);
}

VideoStat *VideoStatManager::makeVideoStatAtIndex(Document doc, VideoInfo *vInfo, Index index) {
    LikesIndicator likes = doc.GetCell<LikesIndicator>("Likes", index);
    CommentsIndicator comments = doc.GetCell<CommentsIndicator>("Comments", index);
    ViewsIndicator views = doc.GetCell<ViewsIndicator>("Views", index);

    return VideoFactory::createVideoStat(vInfo, likes, comments, views);
}

void VideoStatManager::displayRecommandTitle() {
    std::cout << R"(
  ___    ___ ________  ___  ___  _________  ___  ___  ________  _______
 |\  \  /  /|\   __  \|\  \|\  \|\___   ___\\  \|\  \|\   __  \|\  ___ \
 \ \  \/  / | \  \|\  \ \  \\\  \|___ \  \_\ \  \\\  \ \  \|\ /\ \   __/|
  \ \    / / \ \  \\\  \ \  \\\  \   \ \  \ \ \  \\\  \ \   __  \ \  \_|/__
   \/  /  /   \ \  \\\  \ \  \\\  \   \ \  \ \ \  \\\  \ \  \|\  \ \  \_|\ \
 __/  / /      \ \_______\ \_______\   \ \__\ \ \_______\ \_______\ \_______\
|\___/ /        \|_______|\|_______|    \|__|  \|_______|\|_______|\|_______|
\|___|/

)" << std::endl;
    std::cout << "[!] Recommand Videos for you" << std::endl << std::endl;
}

void VideoStatManager::displayVideoInfoAndStat(VideoInfo *vInfo, VideoStat *vStat) {
    std::cout << "[*] Title/Keyword: " << vInfo->getTitle() << " / " << vInfo->getKeywordString()
              << std::endl;
    std::cout << "[*] Views/Likes/Comments: " << vStat->getViews() << " / " << vStat->getLikes()
              << " " << vStat->getComments() << std::endl;
    std::cout << "[*] Participation/Reactivity/Weight: " << vStat->getParticipation() << " "
              << vStat->getReactivity() << " / " << vStat->getWeight() << std::endl;
    std::cout << std::endl;
}

void VideoStatManager::registerStatsInCsv(FilePath csvFilePath) {
    Document doc(csvFilePath);

    for (int i = 0; i < doc.GetRowCount(); i++) {
        VideoInfo *vInfo = makeVideoInfoAtIndex(doc, i);
        if (!vInfo)
            continue;

        VideoStat *vStat = makeVideoStatAtIndex(doc, vInfo, i);
        if (!vStat)
            continue;

        vStats->push_back(vStat);
    }
}

void VideoStatManager::recommandTopVideos(VideoCount vCnt) {
    if (vCnt > vStats->size()) {
        std::cout << "videoStats index out of range" << std::endl;
        return;
    }

    std::sort(vStats->begin(), vStats->end(),
              [](VideoStat *a, VideoStat *b) -> bool { return a->getWeight() > b->getWeight(); });

    displayRecommandTitle();

    for (int i = 0; i < vCnt; i++) {
        VideoStat *vStatAtI = vStats->at(i);
        VideoInfo *vInfoAtI = vStatAtI->getVideoInfo();
        displayVideoInfoAndStat(vInfoAtI, vStatAtI);
    }
}
