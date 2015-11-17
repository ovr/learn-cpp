cmake_minimum_required(VERSION 3.2)
project(json_parse)


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost 1.58.0 REQUIRED COMPONENTS program_options system filesystem)
include_directories(${Boost_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp)
add_executable(json_parse ${SOURCE_FILES})

target_link_libraries(json_parse ${Boost_LIBRARIES})