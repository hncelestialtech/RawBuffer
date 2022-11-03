cmake_minimum_required(VERSION 3.10)
project(test)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../src)
add_executable(test_api test.cc)
