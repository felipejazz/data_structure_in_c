add_executable(TestHashTable TestHashTable.cpp)
target_include_directories(TestHashTable PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(TestHashTable PRIVATE HashTable)


add_test(NAME TestHashTable COMMAND TestHashTable)
