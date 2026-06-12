cmake_minimum_required(VERSION 3.27)

project(GDAIBot VERSION 1.0.0 LANGUAGES CXX)

# Pull the official build rules directly from the path handed over by our terminal script
include(${GEODE_MOD_INCLUDE_FILE})

add_geode_mod(
    ID daniedy.gd_ai_bot
    NAME "GD Genetic AI Bot"
    DEVELOPER "Daniel"
    VERSION 1.0.0
    SOURCES src/main.cpp
)
