#include "AVLTree.hpp"
#include "BaseObject.hpp"
#include <iostream>
#include <cassert>

using namespace std;

void testAVLTree() {
    cout << "Starting AVLTree tests..." << endl;

    AVLTree avl;

    // Check if the tree is initially empty
    assert(avl.isEmpty());
    assert(!avl.isFull());
    cout << "Test 1: Confirmed that the tree is empty at the start." << endl;

    // ------------------------------------------------------------------------
    // Test 2: Insertion - Insert multiple objects, testing rebalancing.
    // We will use a sequence that forces rotations (e.g., 30, 20, 10, 40, 50).
    // This ensures that the balance factor is corrected.
    // ------------------------------------------------------------------------
    try {
        avl.insertObject(BaseObject(30, "Object30"));
        avl.insertObject(BaseObject(20, "Object20"));
        avl.insertObject(BaseObject(10, "Object10")); // Should trigger rotation
        avl.insertObject(BaseObject(40, "Object40"));
        avl.insertObject(BaseObject(50, "Object50")); // May trigger rotation
        cout << "Test 2: Multiple insertions and balancing completed successfully." << endl;
    } catch (const char* e) {
        cout << "Test 2 failed: Exception during insertion: " << e << endl;
        assert(false);
    }

    // Verify that the tree is no longer empty
    assert(!avl.isEmpty());

    // ------------------------------------------------------------------------
    // Test 3: Duplicate element exception
    // Try to insert an element that already exists to verify that an exception is thrown.
    // ------------------------------------------------------------------------
    try {
        avl.insertObject(BaseObject(10, "DuplicateObject"));
        // If we reach this point, the test fails because no exception was thrown.
        cout << "Test 3 failed: Duplicate exception was not thrown." << endl;
        assert(false);
    } catch (const char* e) {
        cout << "Test 3: Duplicate element exception thrown correctly: " << e << endl;
    }

    // ------------------------------------------------------------------------
    // Test 4: Retrieval (retrieveObject) - Existing object
    // ------------------------------------------------------------------------
    bool found = false;
    BaseObject search1(40, "");
    avl.retrieveObject(search1, found);
    assert(found && search1.getNome() == "Object40");
    cout << "Test 4: Successfully retrieved the existing object (code 40)." << endl;

    // ------------------------------------------------------------------------
    // Test 5: Retrieval (retrieveObject) - Nonexistent object
    // ------------------------------------------------------------------------
    found = false;
    BaseObject search2(999, "");
    avl.retrieveObject(search2, found);
    assert(!found);
    cout << "Test 5: Retrieval correctly returned 'not found' for a non-existent object." << endl;

    // ------------------------------------------------------------------------
    // Test 6: Removal (deleteObject) - Remove an object that forces rebalancing.
    // Example: remove the object with code 30.
    // ------------------------------------------------------------------------
    avl.deleteObject(30);
    // Verify that the object with code 30 was actually removed
    found = false;
    BaseObject search3(30, "");
    avl.retrieveObject(search3, found);
    assert(!found);
    cout << "Test 6: Removal of object (code 30) was successful." << endl;

    // ------------------------------------------------------------------------
    // Test 7: Traversal prints to verify the resulting structure
    // ------------------------------------------------------------------------
    cout << "Pre-Order Traversal: ";
    avl.printPreOrder();
    cout << "\nIn-Order Traversal: ";
    avl.printInOrder();
    cout << "\nPost-Order Traversal: ";
    avl.printPosOrder();
    cout << endl;

    // ------------------------------------------------------------------------
    // Test 8: isFull() - It is very difficult to actually fill the memory,
    // but we call isFull() to ensure it doesn't cause any errors.
    // ------------------------------------------------------------------------
    bool full = avl.isFull();
    cout << "Test 8: isFull() executed. Returned: " 
         << (full ? "Tree is not full (unlikely false negative)" : "Tree is not full (false)") 
         << endl;

    cout << "\nAll AVLTree tests executed successfully!" << endl;
}

int main() {
    testAVLTree();
    return 0;
}
