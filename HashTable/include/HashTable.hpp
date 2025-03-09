#include "BaseObject.hpp"
#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

class HashTable {
    public:
        HashTable(int max_itens = 100);
        ~HashTable();
        bool isFull() const;
        int getLength() const;
        void print() const;

        void retrieveItem(BaseObject& baseObject, bool& found);
        void insertItem(BaseObject);
        void deleteItem(BaseObject);
        ; 
    private:
        int max_itens;
        int length;
        int getHash(BaseObject baseObject);
        BaseObject* structure;
};

#endif