cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(lab-chess VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "-O2")

file(GLOB SOURCES src/*/*.cpp )
file(GLOB HEADERS src/*/*.h)

add_executable(scacchiera ./exes/scacchiera.cpp ${SOURCES} ${HEADERS})
add_executable(replay ./exes/replay.cpp ${SOURCES} ${HEADERS})