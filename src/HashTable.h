#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "Place.h"
#include "LList.h"
#define LIMIT 30
using namespace std;

/**
 * @author Ryan Smith, Oliver Parker
 */
class HashTable {
    private:
        Place* placeTable[LIMIT];
        HashTable* hashTable[LIMIT];
        int index;
        int count;
		LList<Place> searchResults;

        /**
         * Calculates an index from the given character (value).
         * @param value the character to be hashed.
         * @return index/hash calculated from the given character (value).
         */
        int hash(char value);

        /**
         * Adds a place to the hash table or sub hash tables.
         * @pre place != NULL.
         * @pre place must not already exist in the hash table.
         * @param address the address of the place (passed to avoid calling getAddress again).
         * @param place the place to be added.
         * @return hash table that the place was added to (or NULL if it wasn't).
         */
        HashTable* addPlace(string address, Place* place);
        
        /**
         * Removes a place from the hash table or sub hash tables.
         * @pre place != NULL.
         * @pre place must exist in the hash table.
         * @param address the address of the place (passed to avoid calling getAddress again).
         * @param place the place to be removed.
         * @return hash table that the place was removed from (or NULL if it wasn't).
         */
        HashTable* removePlace(string address, Place* place);
        
        /**
         * Outputs the places contained in the hash table in a linked List (LList).
         * @param rootPlace (optional) a place which if set is not returned if found. Defaults to NULL.
         * @return a LList of places in the hash table.
         */
        LList<Place>* tableToNodes(Place* rootPlace = NULL);
    public:
        /**
         * Constructs a HashTable.
         * @param nIndex the index of the character to be hashed.
         * @pre nIndex >= 0.
         * @post constructed HashTable with an index.
         */
        HashTable(int nIndex = 0);
        
        /**
         * Destructs a HashTable.
         * @post cleared searchResults and deleted sub-HashTables.
         */
        ~HashTable();
        
        /**
         * Adds a place to the hash table.
         * @pre place != NULL.
         * @pre place must not already exist in the hash table.
         * @post place added to the hash table.
         * @param place the place to be added.
         * @return HashTable that the place was added to (or NULL if it wasn't).
         */
        HashTable* add(Place* place);
        
        /**
         * Removes a place from the hash table.
         * @pre place != NULL.
         * @pre place must exist in the hash table.
         * @post place removed from hash table.
         * @param place the place to be removed.
         * @return hash table that the place was removed from (or NULL if it wasn't).
         */
        HashTable* remove(Place* place);
        
        /**
         * Gets all the places with addresses similar to the given address.
         * @param address the address to be found.
         * @param rootPlace (optional) a place which if set is not returned if found. Defaults to NULL.
         * @return a LList of places that match the given address.
         */
        LList<Place>* get(string address, Place* rootPlace = NULL);
};

#endif