#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <string>
#include "simple.h"

using namespace std;

// THis hash table implementation is intended only for the symbol table to
// use. It's not a part of the public interface.
class HashTable {

public:
    HashTable(const size_t size);
    ~HashTable();

    // throws a generic exception upon errors.
    void add(const string key, void* data, size_t size);

    // find an item in the hash table and return the data if it exists.
    void* find(const string key);

    // Iterator starts at element 0 and walks array, delving 
    // the colision trees. Used by the destructor and for 
    // debugging.
    void* walk(size_t* size); 

private:
    struct table_entry {
        void* data;
        size_t size; // if the size is !0 then use free(), otherwise use delete.
        string key;
        struct table_entry* next; // for collisions
    };

    // an array of table entries
    struct table_entry* table;
    // number of entries in the table array (should be a power of 2 for efficiency)
    size_t size;
    // Number of items that are not in the root part of the table. This can be used
    // to track the efficiency of the hash function used.
    size_t collisions;
    // Total number of items in the hash table.
    size_t items;

    // Create the hash value from the string.
    unsigned int make_hash(string key);

};


#endif /* _HASH_TABLE_H_ */