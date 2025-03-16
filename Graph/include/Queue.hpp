#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
public: 
    Queue();
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    void print() const;

    void enqueue(T item);
    T dequeue();

private:
    static const int MAX_SIZE = 100;
    int front;
    int back;
    T* structure;
};


template <typename T>
Queue<T>::Queue() {
    structure = new T[MAX_SIZE];
    front = 0;
    back = 0;
}

template <typename T>
Queue<T>::~Queue() {
    delete [] structure;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return front == back;
}

template <typename T>
bool Queue<T>::isFull() const {
    return (back - front) == MAX_SIZE;
}

template <typename T>
void Queue<T>::enqueue(T item) {
    if(!isFull()) {
        structure[back % MAX_SIZE] = item;
        back++;
        return;
    }
    throw std::runtime_error("Queue is full...");
}

template <typename T>
T Queue<T>::dequeue() {
    if(!isEmpty()) {
        front++;
        return structure[(front - 1) % MAX_SIZE];
    }
    throw std::runtime_error("Queue is empty!");
}

template <typename T>
void Queue<T>::print() const {
    for (int i = front; i < back; i++) {
        std::cout << structure[i % MAX_SIZE] << " ";
    }
    std::cout << std::endl;
}

#endif // QUEUE_HPP
