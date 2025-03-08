#include "queue.hpp"
#include <iostream>

using namespace std;

Queue::Queue() {

    structure = new ItemType[MAX_SIZE];
    front = 0;
    back = 0;
};

Queue::~Queue(){
    delete [] structure;
};


bool Queue::isEmpty() const {
    return front == back;
};

bool Queue::isFull() const {

    return ( back - front ) == MAX_SIZE;

};

void Queue::enqueue(ItemType item) {
    if(!isFull()){
        structure[back % MAX_SIZE] = item;
        back++;
        return;
    }
    throw "Queue is full...";
};

ItemType Queue::dequeue() {
    if(!isEmpty()) {
        front++;
        return structure[(front - 1) % MAX_SIZE];
    };
    throw "Queue is empty!";
};

void Queue::print() const {
    for (int i = front; i < back; i++ ) {
        cout << structure[i%MAX_SIZE];

    }
    cout << endl;
}

 