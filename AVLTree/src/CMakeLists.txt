add_library(AVLTree
    ${CMAKE_SOURCE_DIR}/src/AVLTree.cpp
    ${CMAKE_SOURCE_DIR}/src/BaseObject.cpp
)

target_include_directories(AVLTree PUBLIC ${CMAKE_SOURCE_DIR}/include)
