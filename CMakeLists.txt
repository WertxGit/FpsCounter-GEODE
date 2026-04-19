cmake_minimum_required(VERSION 3.13)
project(WERTX_FPS)

find_package(Geode REQUIRED)

add_geode_mod(
    wertx.fps_counter
    SOURCES main.cpp
)
