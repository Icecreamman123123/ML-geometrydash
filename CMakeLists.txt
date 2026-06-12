cmake_minimum_required(VERSION 3.27)

# 1. SET ALL OVERRIDES FIRST (Before fetching anything)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
set(GEODE_LINK_NIGHTLY ON)

project(GDAIBot VERSION 1.0.0 LANGUAGES CXX)

# 2. NOW FETCH GEODE (It will see the variables we set above!)
include(FetchContent)

FetchContent_Declare(
    Geode
    GIT_REPOSITORY https://github.com/geode-sdk/geode.git
    GIT_TAG v3.0.0-beta.1
)
FetchContent_MakeAvailable(Geode)

# 3. BUILD THE MOD
add_geode_mod(
    ID daniedy.gd_ai_bot
    NAME "GD Genetic AI Bot"
    DEVELOPER "Daniel"
    VERSION 1.0.0
    SOURCES src/main.cpp
)
