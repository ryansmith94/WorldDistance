#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "Place.h"
#include "Node.h"
#define LIMIT 30
using namespace std;

class HashTable {
    private:
        Place* placeTable[LIMIT];
        HashTable* hashTable[LIMIT];
        int index;
        int count;
		Node<Place>* searchResults;

		void clearResults();
        int hash(char value);
        HashTable* addPlace(string address, Place* place);
        HashTable* removePlace(string address, Place* place);
        Node<Place>* tableToNodes(Place* rootPlace = NULL, Node<Place>* lastNode = NULL);
    public:
        HashTable(int nIndex = 0);
        ~HashTable();
        HashTable* add(Place* place);
        HashTable* remove(Place* place);
        Node<Place>* get(string address, Place* rootPlace = NULL);
};

#endif