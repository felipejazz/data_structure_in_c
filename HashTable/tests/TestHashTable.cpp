#include "HashTable.hpp"
#include "BaseObject.hpp"
#include <cassert>
#include <iostream>

using namespace std;

void testHashTable() {
    cout << "Starting tests for HashTable..." << endl;
    
    HashTable ht(5);
    
    // Test 1: Insert and retrieve without collision.
    // For code 10, hash = 10 % 5 = 0.
    BaseObject obj1(10, "Object10");
    ht.insertItem(obj1);
    
    bool found = false;
    BaseObject search1(10, "");
    ht.retrieveItem(search1, found);
    assert(found && search1.getNome() == "Object10");
    cout << "Test 1 passed: Insert and retrieve without collision." << endl;
    
    // Test 2: Insertion with collision.
    // For code 15, hash = 15 % 5 = 0, causing a collision with obj1.
    BaseObject obj2(15, "Object15");
    ht.insertItem(obj2);
    
    BaseObject search2(15, "");
    ht.retrieveItem(search2, found);
    assert(found && search2.getNome() == "Object15");
    cout << "Test 2 passed: Insert and retrieve with collision (Object15)." << endl;
    
    // Test 3: Insertion of another object that collides.
    // For code 20, hash = 20 % 5 = 0, collision with obj1 and obj2.
    BaseObject obj3(20, "Object20");
    ht.insertItem(obj3);
    
    BaseObject search3(20, "");
    ht.retrieveItem(search3, found);
    assert(found && search3.getNome() == "Object20");
    cout << "Test 3 passed: Insert and retrieve with collision (Object20)." << endl;
    
    // Test 4: Deletion of an object in case of collision.
    ht.deleteItem(obj2);
    
    BaseObject searchDeleted(15, "");
    ht.retrieveItem(searchDeleted, found);
    assert(!found);
    cout << "Test 4 passed: Delete an object with collision." << endl;
    
    // Test 5: Insertion after deletion (slot reuse).
    // For code 25, hash = 25 % 5 = 0.
    BaseObject obj4(25, "Object25");
    ht.insertItem(obj4);
    
    BaseObject search4(25, "");
    ht.retrieveItem(search4, found);
    assert(found && search4.getNome() == "Object25");
    cout << "Test 5 passed: Insert after deletion." << endl;
    
    cout << "\nAll tests passed successfully!" << endl;
    

    HashTable arbitraryHT(10);
    arbitraryHT.insertItem(BaseObject(1, "One"));
    arbitraryHT.insertItem(BaseObject(2, "Two"));
    arbitraryHT.insertItem(BaseObject(3, "Three"));
    arbitraryHT.insertItem(BaseObject(4, "Four"));
    arbitraryHT.insertItem(BaseObject(5, "Five"));
    
    cout << "\nPrinting HashTable with 5 arbitrary items:" << endl;
    arbitraryHT.print();
}

int main() {
    testHashTable();
    return 0;
}
