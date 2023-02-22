cmake_minimum_required(VERSION 3.10)

project(perf_test)
# set(CMAKE_CXX_COMPILER /usr/local/linaro-aarch64-2020.09-gcc10.2-linux5.4/bin/aarch64-linux-gnu-g++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -rdynamic -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(BUILD_OUTPUT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/output)
set(EXECUTABLE_OUTPUT_PATH ${BUILD_OUTPUT_ROOT}/bin/)
include_directories(${PROJECT_SOURCE_DIR}/inc)

file(GLOB_RECURSE SRC_FILE "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*")

add_executable(${PROJECT_NAME} perf_test.cpp ${SRC_FILE})
target_link_libraries(${PROJECT_NAME}
                      rt
                      pthread)
