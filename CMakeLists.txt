cmake_minimum_required(VERSION 3.11)  
project(2d_tower_def LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(COPY ${CMAKE_SOURCE_DIR}/resources/ 
     DESTINATION ${CMAKE_BINARY_DIR}/resources)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(2d_tower_def ${SOURCES})

target_include_directories(2d_tower_def PRIVATE include)

target_link_libraries(2d_tower_def PRIVATE raylib)