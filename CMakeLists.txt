cmake_minimum_required(VERSION 3.13)

project(WERTX_FPS_Mod)

find_package(Geode REQUIRED)

add_geode_mod(
    wertx.fps_bypass
    SOURCES main.cpp
)
