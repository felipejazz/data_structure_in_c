#include "Graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int max, int null_edge){
    NULL_EDGE = null_edge;
    maxVertexes = max;
    numVertexes = 0;

    vertexes = new Vertex[maxVertexes];
    edges = new int* [maxVertexes];
    marks = new bool[maxVertexes];


    for (int row = 0; row < maxVertexes; row++ ){
        edges[row] = new int[maxVertexes];
    };

    for (int row = 0; row < maxVertexes; row++){
        for ( int col = 0; col < maxVertexes; col++) {
            edges[row][col] = NULL_EDGE;
        }
    }

};

Graph::~Graph(){
    delete vertexes;
    delete marks;
    
    for (int row = 0; row < maxVertexes; row++){
        delete [] edges[row];
    }
    delete [] edges;
}

int Graph::getIndex(Vertex vertex) {
    //Binary Search Algorithm
    //Vertexes is an ordered array

    int low = 0;
    int high = numVertexes - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int midId = vertexes[mid].getId();
        int targetId = vertex.getId();

        if (midId == targetId) {
            return mid;
        } 
        
        if (targetId < midId) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    throw "Vertex not found in Graph";
}

void Graph::addVertex(Vertex vertex){
    vertexes[numVertexes] = vertex;
    numVertexes++;
    return;
}


void Graph::addEdge(Vertex fromVertex, Vertex toVertex, int weight = 1) {
    int row = getIndex(fromVertex);
    int col = getIndex(toVertex);

    edges[row][col] = weight;

    // remove this line in directed graph
    edges[col][row] = weight;
}

int Graph::getWeight(Vertex fromVertex, Vertex toVertex) {
    int row = getIndex(fromVertex);
    int col = getIndex(toVertex);

    return edges[row][col];
}

void Graph::getAdjacents(Vertex vertex, Queue<Vertex>& queue) {
    int fromIndex = getIndex(vertex);
    int toIndex;

    for (toIndex = 0; toIndex < numVertexes; toIndex++) {
        if (edges[fromIndex][toIndex] != NULL_EDGE){
            queue.enqueue(vertexes[toIndex]);
        }
    }
}

void Graph::clearMarks() {
    for (int i = 0; i < numVertexes; i++) {
        marks[i] = false;
    };
    return;
}

void Graph::markVertex(Vertex vertex) {
    
    int vertexIndex = getIndex(vertex);
    marks[vertexIndex] = true;
    return;
}

bool Graph::isMarked(Vertex vertex) { 
    int vertexIndex = getIndex(vertex);
    return marks[vertexIndex];
}


bool Graph::depthFirstSearch(Graph& graph, Vertex origin, Vertex destination) {
    Stack<Vertex> vertexStack;
    bool found = false;
    Vertex vertex;
    graph.clearMarks();
    vertexStack.push(origin);

    do {

        vertex = vertexStack.pop();
        if (vertex.getId() == destination.getId()) {
            cout << "Found path to: " << destination.getId() << endl;
            found = true;
            break;
        };
        if (!graph.isMarked(vertex)) {
            graph.markVertex(vertex);
            cout << "Visiting: " << vertex.getId() << endl;
            Queue<Vertex> adjacents;
            graph.getAdjacents(vertex, adjacents); 
            while (!adjacents.isEmpty()) {
                Vertex adjacent = adjacents.dequeue();
                if (!graph.isMarked(adjacent)){
                    cout << "Stacking: " << adjacent.getId() << endl;
                    vertexStack.push(adjacent);
                }
            }
        }

    } while (!vertexStack.isEmpty());

    return found;
}

bool Graph::breadthFoundSearch(Graph& graph, Vertex origin, Vertex destination) {
    Queue<Vertex> vertexQueue;
    bool found = false;
    Vertex vertex;
    graph.clearMarks();
    vertexQueue.enqueue(origin);

    do {

        vertex = vertexQueue.dequeue();
        if (vertex.getId() == destination.getId()) {
            cout << "Found path to: " << destination.getId() << endl;
            found = true;
            break;
        };
        if (!graph.isMarked(vertex)) {
            graph.markVertex(vertex);
            cout << "Visiting: " << vertex.getId() << endl;
            Queue<Vertex> adjacents;
            graph.getAdjacents(vertex, adjacents);
            while (!adjacents.isEmpty()) {
                Vertex adjacent = adjacents.dequeue();
                if (!graph.isMarked(adjacent)){
                    cout << "Stacking: " << adjacent.getId() << endl;
                    vertexQueue.enqueue(adjacent);
                }
            }
        }

    } while (!vertexQueue.isEmpty());

    return found;
}

void Graph::printMatrix() {
    for (int i = 0; i < numVertexes; i++) {
        for (int j = 0; j < numVertexes; j++) {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}


