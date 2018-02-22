cmake_minimum_required(VERSION 3.9)
project(LiranProject_Oren_ C)

set(CMAKE_C_STANDARD 99)
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "C/Code/*.c" "C/Headers/*.h")
add_executable(projectApp main.c ${SOURCES})
target_link_libraries(projectApp rt -pthread)


