cmake_minimum_required(VERSION 3.30)
project(endstone_shuffle)

set(CMAKE_CXX_STANDARD 17)

set(ENDSTONE_SOURCES
        src/endstone_shuffle.cpp
        src/json/json_loader.cpp
        src/include/json_loader.h
        src/include/endstone_shuffle.h
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

add_executable(endstone_shuffle_executable ${ENDSTONE_SOURCES})

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -fPIC")
    target_link_libraries(${target_name} PRIVATE -static-libgcc -static-libstdc++ libc++.a libc++abi.a)
endif ()

add_library(${PROJECT_NAME} SHARED ${ENDSTONE_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} PRIVATE endstone::headers)
