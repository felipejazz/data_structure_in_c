#include "Graph.hpp"
#include "Vertex.hpp"
#include "Queue.hpp"
#include <iostream>
#include <cassert>

using namespace std;

void testGraph() {
    cout << "Starting Graph tests..." << endl;

    // Create a graph with capacity for 10 vertices and null edge value set to 0.
    Graph g(10, 0);

    cout << "Test 1: Adding vertices in order." << endl;
    // Add vertices (must be inserted in order so that binary search works correctly)
    g.addVertex(Vertex(10));  // Index 0
    g.addVertex(Vertex(20));  // Index 1
    g.addVertex(Vertex(30));  // Index 2
    g.addVertex(Vertex(40));  // Index 3
    g.addVertex(Vertex(50));  // Index 4

    cout << "Test 2: Adding edges between vertices (bidirectional for undirected graphs)." << endl;
    // Add edges between vertices
    g.addEdge(Vertex(10), Vertex(20), 1);
    g.addEdge(Vertex(10), Vertex(30), 2);
    g.addEdge(Vertex(20), Vertex(40), 3);
    g.addEdge(Vertex(30), Vertex(50), 4);

    cout << "Test 3: Testing getWeight function." << endl;
    // Test getWeight function
    assert(g.getWeight(Vertex(10), Vertex(20)) == 1);
    assert(g.getWeight(Vertex(20), Vertex(10)) == 1);
    assert(g.getWeight(Vertex(10), Vertex(30)) == 2);

    cout << "Test 4: Testing getAdjacents function using a generic Queue<Vertex>." << endl;
    Queue<Vertex> q;
    g.getAdjacents(Vertex(10), q);
    
    // For the vertex with id 10, the adjacent vertices should be 20 and 30.
    assert(!q.isEmpty());
    Vertex v1 = q.dequeue();
    Vertex v2 = q.dequeue();
    // Considering the vertices were added in order, binary search returns vertices with id 20 and 30.
    assert(v1.getId() == 20);
    assert(v2.getId() == 30);
    assert(q.isEmpty());

    cout << "Test 5: Printing adjacency matrix:" << endl;
    g.printMatrix();

    cout << "Graph tests completed successfully!" << endl;
}

int main() {
    testGraph();
    return 0;
}
