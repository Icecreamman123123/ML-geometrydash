cmake_minimum_required(VERSION 3.27)

project(GDAIBot VERSION 1.0.0 LANGUAGES CXX)

if(NOT DEFINED GEODE_MOD_INCLUDE_FILE)
    if(NOT DEFINED ENV{GEODE_SDK})
        message(FATAL_ERROR "GEODE_SDK environment variable is not set!")
    endif()
    set(GEODE_MOD_INCLUDE_FILE "$ENV{GEODE_SDK}/share/geode/cmake/GeodeMod.cmake" CACHE INTERNAL "")
endif()

include(${GEODE_MOD_INCLUDE_FILE})

add_geode_mod(
    ID daniedy.gd_ai_bot
    NAME "GD Genetic AI Bot"
    DEVELOPER "Daniel"
    VERSION 1.0.0
    SOURCES src/main.cpp
)
