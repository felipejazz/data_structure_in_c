add_executable(TestLinkedStack TestLinkedStack.cpp)
target_include_directories(TestLinkedStack PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(TestLinkedStack PRIVATE LinkedStack)


add_test(NAME TestLinkedStack COMMAND TestLinkedStack)
