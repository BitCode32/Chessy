cmake_minimum_required(VERSION 3.10)
project(Chessy C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/Include)
file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/Src/*.c")

add_executable(Chessy ${SRC_FILES})

if (MSVC)
    target_compile_options(Chessy PRIVATE /W4)
else()
    target_compile_options(Chessy PRIVATE -Wall -Wextra -pedantic)
endif()