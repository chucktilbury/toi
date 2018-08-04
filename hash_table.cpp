
#include "simple.h"

using namespace std;

HashTable::HashTable(const size_t size) {

}

HashTable::~HashTable() {

}

// throws a generic exception upon errors.
void HashTable::add(const string key, void* data, size_t size) {

}

// find an item in the hash table and return the data if it exists.
void* HashTable::find(const string key) {
    return nullptr;
}

// Iterator starts at element 0 and walks array, delving 
// the colision trees. Used by the destructor and for 
// debugging.
void* HashTable::walk(size_t* size) {
    return nullptr;
}

// Create the hash value from the string.
unsigned int HashTable::make_hash(string key) {
    return 0;
}
