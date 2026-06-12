cmake_minimum_required(VERSION 3.27)

# 1. Force CMake to bypass legacy dependency rules
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

# 2. Tell the compiler to use nightly/pre-built loader binaries (Fixes the missing loader link error)
set(GEODE_LINK_NIGHTLY ON)

project(GDAIBot VERSION 1.0.0 LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    Geode
    GIT_REPOSITORY https://github.com/geode-sdk/geode.git
    GIT_TAG v3.0.0-beta.1
)
FetchContent_MakeAvailable(Geode)

add_geode_mod(
    ID daniedy.gd_ai_bot
    NAME "GD Genetic AI Bot"
    DEVELOPER "Daniel"
    VERSION 1.0.0
    SOURCES src/main.cpp
)
