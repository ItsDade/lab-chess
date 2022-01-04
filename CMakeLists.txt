cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(lab-chess VERSION 1.0 LANGUAGES CXX)

file( GLOB SOURCES lib/*/*.cpp lib/*.cpp)
file( GLOB HEADERS lib/*/*.h lib/*.h)
add_library( chess ${SOURCES} ${HEADERS} )

add_executable(replay ./src/replay/Replay.cpp)
add_executable(scacchiera ./src/scacchiera/Scacchiera.cpp)

target_link_libraries(replay chess)
target_link_libraries(scacchiera chess)