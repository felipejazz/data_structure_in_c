#ifndef STACK_HPP
#define STACK_HPP

const int MAX_SIZE = 100;

class Stack  {
private:
    int *structure;
    int size;
    int length;
public:
    
    Stack();
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    void push(int value);
    int pop();
    void print() const;
};

#endif 
