cmake_minimum_required(VERSION 3.12)
project(behavior_planning)

set(CMAKE_CXX_STANDARD 11)

add_executable(behavior_planning main.cpp cost.cpp cost.h)