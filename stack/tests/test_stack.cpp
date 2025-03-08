#include "stack.hpp"
#include <cassert>
#include <iostream>

using namespace std;

void testStack() {
    cout << "Starting assert tests...\n";

    Stack s;
    assert(s.isEmpty());
    cout << "Test 1 passed: The stack is empty after creation.\n";

    s.push(10);
    assert(!s.isEmpty());
    cout << "Test 2 passed: The stack is not empty after push.\n";

    int value = s.pop();
    assert(value == 10);
    cout << "Test 3 passed: pop() returned 10.\n";

    bool exceptionCaught = false;
    try {
        s.pop();
    } catch (const char* msg) {
        exceptionCaught = true;
    }
    assert(exceptionCaught);
    cout << "Test 4 passed: pop() threw an exception when trying to pop from an empty stack.\n";

    Stack s2;
    for (int i = 0; i < MAX_SIZE; i++) {
        s2.push(i);
    }
    assert(s2.isFull());
    cout << "Test 5 passed: The stack is full after inserting " << MAX_SIZE << " elements.\n";

    exceptionCaught = false;
    try {
        s2.push(999);
    } catch (const char* msg) {
        exceptionCaught = true;
    }
    assert(exceptionCaught);
    cout << "Test 6 passed: push() threw an exception when trying to push onto a full stack.\n";

    cout << "\nAll tests passed successfully!\n";
}

int main() {
    testStack();
    return 0;
}
