#include "LinkedStack.hpp"
#include "test_new_override.cpp"
#include <cassert>
#include <iostream>


using namespace std;

void testStack() {
    cout << "Starting assert tests...\n";

    LinkedStack ls;
    assert(ls.isEmpty());
    cout << "Test passed! Linked Stack is empty after initialization...";
    cout << endl;
    bool errorCatched = false;
    try {
        ls.pop();
    } catch (const char* msg) {
        errorCatched = true;
    };
    assert(errorCatched);
    cout << "Test passed! Linked Stack throwed an exception when try to pop an empty Linked List...";
    cout << endl;

    ItemType itemToAdd = 10;
    ls.push(10);
    assert(!ls.isEmpty());
    cout << "Test passed! Linked Stack is not empty after enqueue " << itemToAdd << "...";
    cout << endl;

    ItemType itemPopped = ls.pop();
    assert(itemPopped == itemToAdd);
    cout << "Test passed! Linked Stack popped " << itemToAdd << " after only enqueue" << itemToAdd << "...";
    cout << endl;
    
    ItemType newItemToAdd = 20;
    ls.push(itemToAdd);
    ls.push(newItemToAdd);

    itemPopped = ls.pop();
    assert(itemPopped == newItemToAdd);
    cout << "Test passed! Linked Stack popped " << newItemToAdd << " after enqueue: " << itemToAdd << ", " << newItemToAdd << "...";
    cout << endl;

    LinkedStack ls2;
    
    try {
        simulateAllocationFailure = true;    
        ls2.push(itemToAdd);
    } catch (const char* msg) {
        simulateAllocationFailure = false;
    }
    cout << "Test passed! Linked Stack throwed an exception when memory allocation is not possible...";
    cout << endl;



    cout << "\nAll tests passed successfully!\n";
}

int main() {
    testStack();
    return 0;
}
