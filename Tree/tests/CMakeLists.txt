add_executable(TestTree TestTree.cpp)
target_include_directories(TestTree PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(TestTree PRIVATE Tree)


add_test(NAME TestTree COMMAND TestTree)
