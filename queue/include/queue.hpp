#include "itemType.hpp"
#ifndef QUEUE_HPP
#define QUEUE_HPP


const int MAX_SIZE = 100;

class Queue {
    public: 
        Queue();
        ~Queue();
        bool isEmpty() const;
        bool isFull() const;
        void print() const;

        void enqueue(ItemType item);
        int dequeue();

    private:
        int front;
        int back;
        ItemType* structure;
};

#endif