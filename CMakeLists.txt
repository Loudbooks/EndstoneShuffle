cmake_minimum_required(VERSION 3.30)
project(stone_shuffle)

set(CMAKE_CXX_STANDARD 17)

set(ENDSTONE_SOURCES
        src/stone_shuffle.cpp
        src/json/json_loader.cpp
        src/include/json_loader.h
        src/include/stone_shuffle.h
)

include(FetchContent)
FetchContent_Declare(
        endstone
        GIT_REPOSITORY https://github.com/EndstoneMC/endstone.git
        GIT_TAG main
)
FetchContent_MakeAvailable(endstone)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

endstone_add_plugin(${PROJECT_NAME} ${ENDSTONE_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)