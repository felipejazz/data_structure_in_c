#include "queue.hpp"
#include <cassert>
#include <iostream>

using namespace std;

void testQueue() {
    cout << "Starting tests with assert...\n";
    
    Queue q;
    assert(q.isEmpty());
    cout << "Test passed. Queue is empty after creation...\n";

    ItemType itemToAdd = 10;
    q.enqueue(itemToAdd);
    assert(!q.isEmpty());
    cout << "Test passed. Queue is not empty after enqueue " << itemToAdd << "...\n";

    ItemType dequeued = q.dequeue();
    assert(dequeued == itemToAdd);
    cout << "Test passed. Method dequeue() returned " << itemToAdd << "...\n";


    bool exceptionCaught = false;

    try {
        q.dequeue();
    } catch (const char*){
        exceptionCaught = true;
    }
    assert(exceptionCaught);
    cout << "Test passed. Queue throwed an exception after try dequeue from an empty Queue...\n";
    

    Queue q2;

    for (int i=0; i < MAX_SIZE; i++){
        ItemType temp = i;
        q2.enqueue(temp);
    };

    assert(q2.isFull());
    cout << "Test passed. Queue is full after enqueue " << MAX_SIZE << " elements...\n";

    exceptionCaught = false;
    try {
        ItemType item = 101;
        q2.enqueue(item);
    } catch (const char* msg) {
        exceptionCaught = true;
    };
    cout << "Test passed. Fully Queue throwed an exception after try to enqueue new element...\n";

    cout<< "All tests passed!\n";
};

int main() {
    testQueue();
    return 0;
}