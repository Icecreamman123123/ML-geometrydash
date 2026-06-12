cmake_minimum_required(VERSION 3.27)

project(GDAIBot VERSION 1.0.0 LANGUAGES CXX)

# This is the official Geode macro that forces the compiler to hook 
# into the runner's automatically installed SDK directory.
include($ENV{GEODE_SDK}/cmake/GeodeMod.cmake)

add_geode_mod(
    ID daniedy.gd_ai_bot
    NAME "GD Genetic AI Bot"
    DEVELOPER "Daniel"
    VERSION 1.0.0
    SOURCES src/main.cpp
)
