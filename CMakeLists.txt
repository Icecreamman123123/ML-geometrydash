cmake_minimum_required(VERSION 3.27)

project(GDAIBot VERSION 1.0.0 LANGUAGES CXX)

# Tell CMake exactly where the GitHub Action installs the SDK files
list(APPEND CMAKE_PREFIX_PATH "C:/Users/runneradmin/AppData/Local/Geode/sdk")

find_package(Geode REQUIRED)

add_geode_mod(
    ID daniedy.gd_ai_bot
    NAME "GD Genetic AI Bot"
    DEVELOPER "Daniel"
    VERSION 1.0.0
    SOURCES src/main.cpp
)
