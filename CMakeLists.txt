cmake_minimum_required(VERSION 3.27)

project(GDAIBot VERSION 1.0.0 LANGUAGES CXX)

# Force CMake to load Geode's configuration directly from the cloud clone directory
include("${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone/loader/CMakeLists.txt")

add_geode_mod(
    ID daniedy.gd_ai_bot
    NAME "GD Genetic AI Bot"
    DEVELOPER "Daniel"
    VERSION 1.0.0
    SOURCES src/main.cpp
)
