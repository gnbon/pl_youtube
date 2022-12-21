#include <iostream>

#include "videostatmanager.h"

using namespace std;

int main() {
    VideoStatManager manager;
    manager.registerStatsInCsv("res/videos-stats.csv");

    manager.recommandTopVideos(10);
};
