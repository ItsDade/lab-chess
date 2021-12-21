cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(lab-chess VERSION 1.0)

file( GLOB LIB_SOURCES lib/*.cpp )
file( GLOB LIB_HEADERS lib/*.h )
add_library( MyLib ${LIB_SOURCES} ${LIB_HEADERS} )

add_executable(scacchiera Scacchiera.cpp)
target_link_libraries(scacchiera MyLib)
add_executable(replay Replay.cpp)
target_link_libraries(replay MyLib)