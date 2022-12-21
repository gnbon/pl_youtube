#include "videofactory.h"

#include "videostatgaming.h"
#include "videostatgamingminecraft.h"
#include "videostatgamingnintendo.h"
#include "videostatgamingxbox.h"
#include "videostattech.h"
#include "videostattechapple.h"
#include "videostattechgoogle.h"

KeywordStringMap VideoFactory::keywordStrTable = {
    {"tech", Keyword::Tech},     {"apple", Keyword::Apple},         {"google", Keyword::Google},
    {"gaming", Keyword::Gaming}, {"minecraft", Keyword::Minecraft}, {"nintendo", Keyword::Nintendo},
    {"xbox", Keyword::Xbox},
};

Keyword VideoFactory::resolveStringtoKeyword(KeywordString keywordStr) {
    Keyword resolvedKeyword;

    auto it = keywordStrTable.find(keywordStr);
    if (it != keywordStrTable.end()) {
        resolvedKeyword = it->second;
    } else {
        resolvedKeyword = Keyword::Undefined;
    }

    return resolvedKeyword;
}

VideoInfo *VideoFactory::createVideoInfo(Title title, KeywordString keywordStr) {
    Keyword keyword = resolveStringtoKeyword(keywordStr);
    if (keyword == Keyword::Undefined) {
        return nullptr;
    }

    VideoInfo *vInfo = new VideoInfo(title, keyword);
    if (!vInfo) {
        return nullptr;
    } else {
        return vInfo;
    }
}

VideoStat *VideoFactory::createVideoStat(VideoInfo *vInfo, LikesIndicator likes,
                                         CommentsIndicator comments, ViewsIndicator views) {
    VideoStat *vStat = nullptr;
    Keyword keyword = vInfo->getKeyword();

    switch (keyword) {
        case Keyword::Tech:
            vStat = new VideoStatTech(vInfo, likes, comments, views);
            break;

        case Keyword::Apple:
            vStat = new VideoStatTechApple(vInfo, likes, comments, views);
            break;
        case Keyword::Google:
            vStat = new VideoStatTechGoogle(vInfo, likes, comments, views);
            break;
        case Keyword::Gaming:
            vStat = new VideoStatGaming(vInfo, likes, comments, views);
            break;
        case Keyword::Minecraft:
            vStat = new VideoStatGamingMinecraft(vInfo, likes, comments, views);
            break;
        case Keyword::Nintendo:
            vStat = new VideoStatGamingNintendo(vInfo, likes, comments, views);
            break;
        case Keyword::Xbox:
            vStat = new VideoStatGamingXbox(vInfo, likes, comments, views);
            break;
        default:
            vStat = nullptr;
            break;
    }

    if (!vStat) {
        return nullptr;
    } else {
        vStat->calculateWeight();
        return vStat;
    }
}
