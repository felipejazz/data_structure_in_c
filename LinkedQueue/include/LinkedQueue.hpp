
#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP
#include "NodeType.hpp"


class LinkedQueue {
    public: 
        LinkedQueue();
        ~LinkedQueue();
        bool isEmpty() const;
        bool isFull() const;
        void print() const;

        void enqueue(ItemType item);
        int dequeue();

    private:
        NodeType* front;
        NodeType* back;
};

#endif