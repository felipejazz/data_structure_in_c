// TestTree.cpp
#include "Tree.hpp"
#include "BaseObject.hpp"
#include <cassert>
#include <iostream>

using namespace std;

void testTree() {
    cout << "Starting tests for Tree..." << endl;
    
    Tree tree;
    
    // Test 1: Insertion - Insert multiple objects
    try {
        tree.insertObject(BaseObject(10, "Object10"));
        tree.insertObject(BaseObject(5, "Object5"));
        tree.insertObject(BaseObject(15, "Object15"));
        tree.insertObject(BaseObject(3, "Object3"));
        tree.insertObject(BaseObject(7, "Object7"));
        cout << "Test 1 passed: Insertion successful." << endl;
    } catch (const char* e) {
        cout << "Test 1 failed: Exception during insertion: " << e << endl;
        assert(false);
    }
    
    // Test 2: Retrieval - Retrieve an existing object
    bool found = false;
    BaseObject search(7, "");
    tree.retrieveObject(search, found);
    assert(found && search.getNome() == "Object7");
    cout << "Test 2 passed: Retrieval of existing object successful." << endl;
    
    // Test 3: Retrieval - Try retrieving a non-existent object
    found = false;
    BaseObject searchNonExistent(8, "");
    tree.retrieveObject(searchNonExistent, found);
    assert(!found);
    cout << "Test 3 passed: Retrieval returns false for non-existent object." << endl;
    
    // Test 4: Deletion - Delete an object
    // Public interface expects a pointer reference. Create a pointer for the object to delete.
    // (Ensure your deleteObject implementation is consistent with the header.)
    BaseObject* objToDelete = new BaseObject(10, "Object10");
    tree.deleteObject(objToDelete->getCode());

    // Try retrieving the deleted object
    found = false;
    BaseObject searchDeleted(10, "");
    tree.retrieveObject(searchDeleted, found);
    assert(!found);
    cout << "Test 4 passed: Deletion of object successful." << endl;
    delete objToDelete; // Clean up if necessary
    
    // Test 5: Tree Traversals - Print tree orders
    cout << "Pre-Order Traversal: ";
    tree.printPreOrder();
    cout << "\nIn-Order Traversal: ";
    tree.printInOrder();
    cout << "\nPost-Order Traversal: ";
    tree.printPosOrder();
    cout << endl;
    
    cout << "\nAll tests for Tree passed successfully!" << endl;
}

int main() {
    testTree();
    return 0;
}
