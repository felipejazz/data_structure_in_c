
add_library(queue ${CMAKE_SOURCE_DIR}/src/queue.cpp)

target_include_directories(queue PUBLIC ${CMAKE_SOURCE_DIR}/include)
