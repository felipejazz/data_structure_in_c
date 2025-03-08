#include "LinkedStack.hpp"
#include <cstddef>
#include <new>



LinkedStack::LinkedStack(){
    structure = NULL;
};

LinkedStack::~LinkedStack(){
    NodeType* tempPtr;
    while (structure != NULL){
        tempPtr = structure;
        structure = structure -> next;
        delete tempPtr;
    }
}

bool LinkedStack::isEmpty() const {
    return structure == NULL;
}

bool LinkedStack::isFull() const {
    NodeType* location;
    try {
        location = new NodeType;
        return false;
    } catch (std::bad_alloc exception) {
        return true;
    };
};

void LinkedStack::push(ItemType item) {
    if(!isFull()){
        NodeType* location = new NodeType;
        location -> info = item;
        location -> next = structure;
        structure = location;
        return;
    };
    throw "Linked Stack is already full!";
}

ItemType LinkedStack::pop() {
    if(!isEmpty()) {
        NodeType* tempPtr;
        tempPtr = structure;
        ItemType item = structure -> info;
        structure = structure -> next;
        delete tempPtr;
        return item;
    }

    throw "Linked Stack is empty!";
};
