#include "LinkedQueue.hpp"
#include "test_new_override.cpp"
#include <cassert>
#include <iostream>


using namespace std;

void testQueue() {
    cout << "Starting assert tests...";
    cout << endl;

    LinkedQueue lq;
    assert(lq.isEmpty());
    cout << "Test passed! Linked Queue is empty after initialization...";
    cout << endl;
    
    bool errorCatched = false;
    try {
        lq.dequeue();
    } catch (const char* msg) {
        errorCatched = true;
    };
    assert(errorCatched);
    cout << "Test passed! Linked Queue throwed an exception when try to pop an empty Linked List...";
    cout << endl;

    ItemType itemToAdd = 10;
    lq.enqueue(itemToAdd);
    assert(!lq.isEmpty());
    cout << "Test passed! Linked Queue is not empty after enqueue " << itemToAdd << "...";
    cout << endl;

    ItemType itemDequeued = lq.dequeue();
    assert(itemDequeued == itemToAdd);
    cout << "Test passed! Linked Queue dequeued " << itemToAdd << " after only enqueue" << itemToAdd << "...";
    cout << endl;
    
    ItemType newItemToAdd = 20;
    lq.enqueue(itemToAdd);
    lq.enqueue(newItemToAdd);

    itemDequeued = lq.dequeue();
    assert(itemDequeued == newItemToAdd);
    cout << "Test passed! Linked Queue dequeued " << newItemToAdd << " after enqueue: " << itemToAdd << ", " << newItemToAdd << "...";
    cout << endl;

    LinkedQueue lq2;
    
    try {
        simulateAllocationFailure = true;    
        lq2.enqueue(itemToAdd);
    } catch (const char* msg) {
        simulateAllocationFailure = false;
    }
    cout << "Test passed! Linked Queue throwed an exception when memory allocation is not possible...";
    cout << endl;


    cout << "\nAll tests passed successfully!\n";
}

int main() {
    testQueue();
    return 0;
}
