add_executable(pl_youtube main.cpp
    videoinfo.cpp
    videostat.cpp
    videostatmanager.cpp
    videofactory.cpp
    videostattech.cpp
    videostattechapple.cpp
    videostattechgoogle.cpp
    videostatgaming.cpp
    videostatgamingminecraft.cpp
    videostatgamingnintendo.cpp
    videostatgamingxbox.cpp
)

target_include_directories(pl_youtube PRIVATE ${CMAKE_SOURCE_DIR}/include)
