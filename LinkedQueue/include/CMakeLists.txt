add_executable(TestLinkedQueue TestLinkedQueue.cpp)
target_include_directories(TestLinkedQueue PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(TestLinkedQueue PRIVATE LinkedQueue)


add_test(NAME TestLinkedQueue COMMAND TestLinkedQueue)
