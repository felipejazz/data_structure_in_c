add_executable(TestGraph TestGraph.cpp)
target_include_directories(TestGraph PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(TestGraph PRIVATE Graph)


add_test(NAME TestGraph COMMAND TestGraph)
