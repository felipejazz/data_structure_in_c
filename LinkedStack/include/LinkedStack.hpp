#ifndef STACK_HPP
#define STACK_HPP
#include "NodeType.hpp"

class LinkedStack  {
private:
    NodeType* structure;
public:
    
    LinkedStack();
    ~LinkedStack();
    bool isEmpty() const;
    bool isFull() const;
    void push(ItemType item);
    int pop();
    void print() const;
};

#endif 
