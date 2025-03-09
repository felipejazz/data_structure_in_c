add_library(Tree
    ${CMAKE_SOURCE_DIR}/src/Tree.cpp
    ${CMAKE_SOURCE_DIR}/src/BaseObject.cpp
)

target_include_directories(Tree PUBLIC ${CMAKE_SOURCE_DIR}/include)
