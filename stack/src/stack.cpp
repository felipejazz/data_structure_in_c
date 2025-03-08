#include "stack.hpp"
#include  <iostream>
using namespace std;

Stack::Stack() {
    structure = new int[MAX_SIZE];
    size = MAX_SIZE;
    length = 0;
}

Stack::~Stack() {
    delete[] structure;
}

bool Stack::isEmpty() const {
    return length == 0;
}

bool Stack::isFull() const {
    return length == size;
}

void Stack::push(int value ) {
    
    if (isFull()) {
        throw "Stack is full";
    };
    
    structure[length] = value;
    length++;
}

int Stack::pop(){
    if (isEmpty()) {
        throw "Stack is empty";
    }
    return structure[--length];
}

void Stack::print() const {
    for (int i = 0; i < length; i++) {
        cout << structure[i] << " ";
    }
    cout << endl;
}
