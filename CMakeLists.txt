cmake_minimum_required(VERSION 3.10)

set(SRC_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(HEADERS ${INCLUDE_DIR}/my_include.h)
set(SOURCES ${SRC_DIRECTORY}/* ${INCLUDE_DIR}/*)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(sdl_project VERSION 1.0)

add_executable(main ${SRC_DIRECTORY}/main.cpp)

target_include_directories(main PRIVATE ${INCLUDE_DIR})

add_custom_target(run
    COMMAND main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build
)


