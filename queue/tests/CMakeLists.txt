add_executable(test_queue test_queue.cpp)
target_include_directories(test_queue PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(test_queue PRIVATE queue)


add_test(NAME test_queue COMMAND test_queue)
