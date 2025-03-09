#include "HashTable.hpp"
#include "BaseObject.hpp"
#include <iostream>


HashTable::HashTable(int max){
    length = 0;
    max_itens = max;
    structure = new BaseObject[max_itens];
};

HashTable::~HashTable(){
    delete [] structure;
};

int HashTable::getHash(BaseObject baseObject) {
    return baseObject.getCode() % max_itens;
}

void HashTable::print() const {
    for (int i = 0; i < length; i++) {
        cout << i << "| " << structure[i].getCode() << ": " << structure[i].getNome()<< endl;
    };
};

void HashTable::insertItem(BaseObject item){
    int location = getHash(item);

    while (structure[location].getCode() > 0 ) {
        location = (location + 1) % max_itens;
    }
    structure[location] = item;
    length++;
    return;
}


void HashTable::retrieveItem(BaseObject& baseObject, bool& found) {
    int startLocation = getHash(baseObject);
    int location = startLocation;
    
    while (true) {
    
        if (structure[location].getCode() == baseObject.getCode()) {
            found = true;
            baseObject = structure[location];
            return;
        }
        if (structure[location].getCode() == -1) {
            found = false;
            return;
        }
        location = (location + 1) % max_itens;

        if (location == startLocation) {
            break;
        }
    }
    found = false;
}



void HashTable::deleteItem(BaseObject baseObject) {
    int startLocation = getHash(baseObject);
    int location = startLocation;
    
    while (true) {
        if (structure[location].getCode() == baseObject.getCode()) {
            structure[location] = BaseObject(-2, "");
            length--;
            return;
        }
        if (structure[location].getCode() == -1) {
            return;
        }
        location = (location + 1) % max_itens;
        if (location == startLocation) {
            break;
        }
    }
}



