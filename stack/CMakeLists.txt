cmake_minimum_required(VERSION 3.10)

project(Stack)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)
