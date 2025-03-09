add_library(HashTable 
    ${CMAKE_SOURCE_DIR}/src/HashTable.cpp
    ${CMAKE_SOURCE_DIR}/src/BaseObject.cpp
)

target_include_directories(HashTable PUBLIC ${CMAKE_SOURCE_DIR}/include)
