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
    // We'll add 10, 20, 30, 40, 50 as connected, then 60, 70 as isolated
    g.addVertex(Vertex(10));  // Index 0
    g.addVertex(Vertex(20));  // Index 1
    g.addVertex(Vertex(30));  // Index 2
    g.addVertex(Vertex(40));  // Index 3
    g.addVertex(Vertex(50));  // Index 4
    g.addVertex(Vertex(60));  // Index 5 (isolated)
    g.addVertex(Vertex(70));  // Index 6 (isolated)

    cout << "Test 2: Adding edges between vertices (bidirectional for undirected graphs)." << endl;
    // Add edges between some vertices
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
    // Considering the vertices were added in ascending order, the binary search returns 20, then 30.
    assert(v1.getId() == 20);
    assert(v2.getId() == 30);
    assert(q.isEmpty());

    cout << "Test 5: Printing adjacency matrix:" << endl;
    g.printMatrix();

    // --------------------------------------------------------------
    // TEST 6: Depth-First Search (DFS)
    // --------------------------------------------------------------
    cout << "Test 6: Depth-First Search (DFS) from 10 to 50." << endl;
    bool foundDFS = g.depthFirstSearch(g, Vertex(10), Vertex(50));
    assert(foundDFS && "DFS should find a path from 10 to 50");
    cout << "Test 6 passed: DFS found a path from 10 to 50." << endl;

    // Also check a vertex that doesn't exist in the graph
    cout << "Test 6.1: DFS from 10 to 999 (non-existent) => Expect not found." << endl;
    bool foundDFS2 = g.depthFirstSearch(g, Vertex(10), Vertex(999));
    assert(!foundDFS2 && "DFS should NOT find a path from 10 to 999");
    cout << "Test 6.1 passed: DFS did not find a path to a non-existent vertex." << endl;

    // --------------------------------------------------------------
    // TEST 7: Breadth-First Search (BFS)
    // --------------------------------------------------------------
    cout << "Test 7: Breadth-First Search (BFS) from 10 to 50." << endl;
    bool foundBFS = g.breadthFoundSearch(g, Vertex(10), Vertex(50));
    assert(foundBFS && "BFS should find a path from 10 to 50");
    cout << "Test 7 passed: BFS found a path from 10 to 50." << endl;

    // Also check a vertex that doesn't exist
    cout << "Test 7.1: BFS from 10 to 999 (non-existent) => Expect not found." << endl;
    bool foundBFS2 = g.breadthFoundSearch(g, Vertex(10), Vertex(999));
    assert(!foundBFS2 && "BFS should NOT find a path from 10 to 999");
    cout << "Test 7.1 passed: BFS did not find a path to a non-existent vertex." << endl;

    // --------------------------------------------------------------
    // TEST 8: Search when both vertices exist but are NOT connected
    // --------------------------------------------------------------
    cout << "Test 8: DFS and BFS from 10 to 60 (both exist, but there's no edge to 60)." << endl;

    bool foundDFS3 = g.depthFirstSearch(g, Vertex(10), Vertex(60));
    assert(!foundDFS3 && "DFS should NOT find a path from 10 to 60 if no edge to 60");
    cout << "Test 8.1 passed: DFS did not find a path from 10 to 60 as expected." << endl;

    bool foundBFS3 = g.breadthFoundSearch(g, Vertex(10), Vertex(60));
    assert(!foundBFS3 && "BFS should NOT find a path from 10 to 60 if no edge to 60");
    cout << "Test 8.2 passed: BFS did not find a path from 10 to 60 as expected." << endl;

    cout << "\nGraph tests completed successfully!" << endl;
}

int main() {
    testGraph();
    return 0;
}
