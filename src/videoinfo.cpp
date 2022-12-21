#include "videoinfo.h"

KeywordMap VideoInfo::keywordTable = {
    {Keyword::Tech, "tech"},     {Keyword::Apple, "apple"},         {Keyword::Google, "google"},
    {Keyword::Gaming, "gaming"}, {Keyword::Minecraft, "minecraft"}, {Keyword::Nintendo, "nintendo"},
    {Keyword::Xbox, "xbox"},
};

VideoInfo::VideoInfo(Title title, Keyword keyword) : title(title), keyword(keyword) {
}

Title VideoInfo::getTitle() {
    return title;
}

void VideoInfo::setTitle(Title title) {
    this->title = title;
}

Keyword VideoInfo::getKeyword() {
    return keyword;
}

KeywordString VideoInfo::getKeywordString() {
    KeywordString resolvedKeywordStr;

    auto it = keywordTable.find(keyword);
    if (it != keywordTable.end()) {
        resolvedKeywordStr = it->second;
    } else {
        resolvedKeywordStr = "undefined";
    }

    return resolvedKeywordStr;
}

void VideoInfo::setKeyword(Keyword keyword) {
    this->keyword = keyword;
}
