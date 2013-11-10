#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP
#include <string>
#include "HashTable.h"
#include "Place.cpp"
#include "Node.cpp"
#define A 97
#define Z 122
#define SPACE 32
#define NUL 0
#define COMMA 44
#define LIMIT 30


int HashTable::hash(string value) {
    int asciiChar = value[index];

    if (asciiChar >= A && asciiChar <= Z) {
        return asciiChar - A;
    } else if (asciiChar == SPACE) {
        return 26;
    } else if (asciiChar == NUL) {
        return 27;
    } else if (asciiChar == COMMA) {
        return 28;
    }

    return 29;
}

// Return the hashtable that the place is added to.
HashTable* HashTable::addPlace(string address, Place* place) {
    int key = hash(address);

    // Add to hashtable.
    if (placeTable[key] != NULL) {
        if (address == placeTable[key]->getAddress()) {
            return NULL;
        }
        HashTable* ht = new HashTable(index + 1);
        hashTable[key] = ht;
        ht->addPlace(placeTable[key]->getAddress(), placeTable[key]);
        placeTable[key] = NULL;
        count += 1;
        return ht->addPlace(address, place);
    } else if (hashTable[key] != NULL) {
        count += 1;
        return hashTable[key]->addPlace(address, place);
    }

    count += 1;
    placeTable[key] = place;
    return this;
}

// Return the hashtable that the place was removed from.
HashTable* HashTable::removePlace(string address, Place* place) {
    int key = hash(address);

    if (hashTable[key] != NULL) {
        if (address[index + 1] != NUL) {
            HashTable* ht = hashTable[key]->removePlace(address, place);
            if (ht != NULL) {
                count -= 1;
                if (hashTable[key]->count == 0) {
                    delete hashTable[key];
                    hashTable[key] = NULL;
                    return this;
                }
            }
            return ht;
        }
    } else if (placeTable[key] != NULL) {
        if (placeTable[key] == place) {
            placeTable[key] = NULL;
            count -= 1;
            return this;
        }
    }

    return NULL;
}
Node<Place>* HashTable::tableToNodes(Node<Place>* lastNode) {
    Node<Place>* firstNode = lastNode;

    for (int i = 0; i < LIMIT; i += 1) {
        Node<Place>* tmp;
        if (hashTable[i] != NULL) {
            tmp = hashTable[i]->tableToNodes(lastNode);
            if (lastNode != NULL) {
                lastNode->setNext(tmp);
            } else {
                firstNode = tmp;
            }
            lastNode = tmp;
        } else if (placeTable[i] != NULL) {
            tmp = new Node<Place>(placeTable[i]);
            if (lastNode != NULL) {
                lastNode->setNext(tmp);
            } else {
                firstNode = tmp;
            }
            lastNode = tmp;
        }
    }

    return firstNode;
}

HashTable::HashTable(int nIndex = 0) {
    index = nIndex;
    count = 0;
	for (int i = 0;i<LIMIT;i++){
		placeTable[i] = NULL;
		hashTable[i] = NULL;
	}
}

HashTable::~HashTable() {
    for (int i = 0; i < LIMIT; i += 1) {
        if (hashTable[i] != NULL) {
            delete hashTable[i];
        }
    }
}

HashTable* HashTable::add(Place* place) {
    return addPlace(place->getAddress(), place);
}

HashTable* HashTable::remove(Place* place) {
    return removePlace(place->getAddress(), place);
}

Node<Place>* HashTable::get(string address) {
    int key = hash(address);

    // Get from hashtable.
    if (hashTable[key] != NULL) {
        if (address[index + 1] != NUL) {
            return hashTable[key]->get(address);
        } else {
            return hashTable[key]->tableToNodes(NULL);
        }
    } else if (placeTable[key] != NULL) {
        return new Node<Place>(placeTable[key]);
    }

    return NULL;
}

#endif