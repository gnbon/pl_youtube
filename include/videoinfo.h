#ifndef VIDEOINFO_H
#define VIDEOINFO_H

#include <map>
#include <string>

typedef std::string Title;
typedef enum class _Keyword {
    Tech,
    Apple,
    Google,
    Gaming,
    Minecraft,
    Nintendo,
    Xbox,
    Undefined,
} Keyword;
typedef std::string KeywordString;
typedef std::map<Keyword, KeywordString> KeywordMap;

class VideoInfo {
  private:
    Title title;
    Keyword keyword;
    static KeywordMap keywordTable;

  public:
    VideoInfo(Title title, Keyword keyword);
    Title getTitle();
    void setTitle(Title title);
    Keyword getKeyword();
    KeywordString getKeywordString();
    void setKeyword(Keyword);
};

#endif  // VIDEOINFO_H
