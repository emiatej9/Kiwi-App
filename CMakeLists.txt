cmake_minimum_required(VERSION 3.19)

project(Kiwi-App LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_CXX_FLAGS_DEBUG "-O0")

add_executable(kiwi-analyzer ${PROJECT_SOURCE_DIR}/src/main.cc)

target_include_directories(kiwi-analyzer PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(kiwi-analyzer ${PROJECT_SOURCE_DIR}/lib/libkiwi_static.a)

