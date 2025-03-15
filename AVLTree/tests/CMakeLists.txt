add_executable(TestAVLTree TestAVLTree.cpp)
target_include_directories(TestAVLTree PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(TestAVLTree PRIVATE AVLTree)


add_test(NAME TestAVLTree COMMAND TestAVLTree)
