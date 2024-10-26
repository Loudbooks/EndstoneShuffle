cmake_minimum_required(VERSION 3.30)
project(stone_shuffle)

set(CMAKE_CXX_STANDARD 17)

set(ENDSTONE_SOURCES
        src/stone_shuffle.cpp
        src/json/json_loader.cpp
        src/include/json_loader.h
        src/include/stone_shuffle.h
)

set(OUTPUT_NAME ${PROJECT_NAME})

if(WIN32)
    set(OS_NAME "windows")
elseif(UNIX)
    set(OS_NAME "linux")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    set(OUTPUT_NAME "${OUTPUT_NAME}_${OS_NAME}_debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(OUTPUT_NAME "${OUTPUT_NAME}_${OS_NAME}")
endif()

include(FetchContent)
FetchContent_Declare(
        endstone
        GIT_REPOSITORY https://github.com/EndstoneMC/endstone.git
        GIT_TAG v0.5.5
)
FetchContent_MakeAvailable(endstone)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

endstone_add_plugin(${PROJECT_NAME} ${ENDSTONE_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${OUTPUT_NAME})
