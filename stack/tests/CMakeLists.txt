add_executable(test_stack test_stack.cpp)
target_include_directories(test_stack PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(test_stack PRIVATE stack)


add_test(NAME test_stack COMMAND test_stack)
