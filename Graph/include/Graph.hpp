#include "Vertex.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#ifndef GRAPH_HPP
#define GRAPH_HPP

class Graph {
    private:
        int NULL_EDGE;
        int maxVertexes;
        int numVertexes;
        Vertex* vertexes;
        int** edges; // adjacency matrix
        bool* marks;
        int getIndex(Vertex);
    
    public:
        Graph(int max = 50, int null = 0);
        ~Graph();

        void addVertex(Vertex);
        void addEdge(Vertex, Vertex, int);
        int getWeight(Vertex, Vertex);
        void getAdjacents(Vertex, Queue<Vertex>&);
        void clearMarks();
        void markVertex(Vertex);
        bool isMarked(Vertex);
        void printMatrix();
        bool depthFirstSearch(Graph&, Vertex, Vertex);
        bool breadthFoundSearch(Graph&, Vertex, Vertex);

 };

#endif