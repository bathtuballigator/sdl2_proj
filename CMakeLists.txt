cmake_minimum_required(VERSION 3.7)

set(SRC_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(HEADERS ${INCLUDE_DIR}/my_include.h)
set(SOURCES ${SRC_DIRECTORY}/main.cpp)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(sdl_project VERSION 1.0)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
include_directories(${SDL3_INCLUDE_DIRS})

add_executable(main ${SOURCES})

target_include_directories(main PRIVATE ${INCLUDE_DIR})
target_link_libraries(main ${SDL3_LIBRARIES})

add_custom_target(run
    COMMAND main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build
)


