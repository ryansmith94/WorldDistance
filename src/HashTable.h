#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "HashTable.h"
#include "Place.h"
#include "Node.cpp"
#define LIMIT 30

class Place;

class HashTable {
    private:
        Place* placeTable[LIMIT];
        HashTable* hashTable[LIMIT];
        int index;
        int count;

        int hash(string value);
        HashTable* addPlace(string address, Place* place);
        HashTable* removePlace(string address, Place* place);
        Node<Place>* tableToNodes(Node<Place>* lastNode = NULL);
    public:
        HashTable(int nIndex = 0);
        ~HashTable();
        HashTable* add(Place* place);
        HashTable* remove(Place* place);
        Node<Place>* get(string address);
};

#endif