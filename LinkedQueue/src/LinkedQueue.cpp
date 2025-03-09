#include "LinkedQueue.hpp"
#include <cstddef>
#include <new>


LinkedQueue::LinkedQueue() {
    front = NULL;
    back = NULL;
}

LinkedQueue::~LinkedQueue(){
    back = NULL;
    NodeType* tempPtr;
    while (front != NULL){
        front = tempPtr;
        front = front -> next;
        delete tempPtr;
    };
}

bool LinkedQueue::isEmpty() const {
    return front == NULL;
};

bool LinkedQueue::isFull() const {
    NodeType* tempLocation;
    try {
        tempLocation = new NodeType;
        delete tempLocation;
        return false;  
   } catch (std::bad_alloc exeception) {
    return true;
   };
};

void LinkedQueue::enqueue(ItemType item) {
    if(!isFull()){
        NodeType* newNode =  new NodeType;
        newNode->info = item;
        newNode->next = NULL;

        if (back == NULL) {
            front = newNode;
            return;
        }
        back->next = newNode;
        return;
    };
    throw "Linked Queue is already full!";
};

ItemType LinkedQueue::dequeue() {
    if(!isEmpty()) {
        NodeType* tempPtr;
        tempPtr = front;
        ItemType item = front->info;
        front = front->next;
        delete tempPtr;
        return item;
    };

    throw "LinkedQueue is empty!";
};