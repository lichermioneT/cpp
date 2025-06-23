
cmake_minimum_required(VERSION 3.0)

project(test)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp) 

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(calc ${SRC}) # 取值


