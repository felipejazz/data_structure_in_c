add_library(Graph
    ${CMAKE_SOURCE_DIR}/src/Graph.cpp
    ${CMAKE_SOURCE_DIR}/src/Vertex.cpp
)

target_include_directories(Graph PUBLIC ${CMAKE_SOURCE_DIR}/include)
