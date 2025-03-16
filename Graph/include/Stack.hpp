#include  <iostream>
#ifndef STACK_HPP
#define STACK_HPP

using namespace std;

const int MAX_SIZE = 100;

template <typename T>

class Stack  {
private:
    T *structure;
    int size;
    int length;
public:
    
    Stack();
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    void push(T value);
    T pop();
    void print() const;
};

#endif 



template <typename T>
Stack<T>::Stack() {
    structure = new T[MAX_SIZE];
    size = MAX_SIZE;
    length = 0;
}

template <typename T>
Stack<T>::~Stack() {
    delete[] structure;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return length == 0;
}

template <typename T>
bool Stack<T>::isFull() const {
    return length == size;
}
template <typename T>
void Stack<T>::push(T value ) {
    
    if (isFull()) {
        throw "Stack is full";
    };
    
    structure[length] = value;
    
    length++;
}
template <typename T>
T Stack<T>::pop(){
    if (isEmpty()) {
        throw "Stack is empty";
    }
    return structure[--length];
}
template <typename T>
void Stack<T>::print() const {
    for (int i = 0; i < length; i++) {
        cout << structure[i] << " ";
    }
    cout << endl;
}
