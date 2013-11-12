#include "HashTable.h"
#define LOWER_A 97
#define LOWER_Z 122
#define UPPER_A 65
#define UPPER_Z 90
#define SPACE 32
#define NUL 0
#define COMMA 44
#define LIMIT 30


int HashTable::hash(char value) {
    int asciiChar = value;

    if (asciiChar >= LOWER_A && asciiChar <= LOWER_Z) {
        return asciiChar - LOWER_A;
    } else if (asciiChar >= UPPER_A && asciiChar <= UPPER_Z) {
        return asciiChar - UPPER_A;
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
    int key = hash(address[index]);

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
        HashTable* ht = hashTable[key]->addPlace(address, place);
        if (ht != NULL) {
            count += 1;
        }
        return ht;
    }

    count += 1;
    placeTable[key] = place;
    return this;
}

// Return the hashtable that the place was removed from.
HashTable* HashTable::removePlace(string address, Place* place) {
    int key = hash(address[index]);

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
    Node<Place>* firstNode = NULL;

    if (lastNode == NULL) {
        lastNode = new Node<Place>();
        firstNode = lastNode;
    }

    for (int i = 0; i < LIMIT; i += 1) {
        if (hashTable[i] != NULL) {
            lastNode = hashTable[i]->tableToNodes(lastNode);
        } else if (placeTable[i] != NULL) {
            Node<Place>* tmp = new Node<Place>();
            lastNode->setData(placeTable[i]);
            lastNode->setNext(tmp);
            lastNode = tmp;
        }
    }

    return (firstNode == NULL) ? lastNode : firstNode;
}

HashTable::HashTable(int nIndex) {
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
    int key = hash(address[index]);

    // Get from hashtable.
    if (hashTable[key] != NULL) {
        if (address[index + 1] != NUL) {
            return hashTable[key]->get(address);
        } else {
            return hashTable[key]->tableToNodes();
        }
    } else if (placeTable[key] != NULL) {
        if (address[index + 1] == NUL) {
            return new Node<Place>(placeTable[key]);
        } else{
			string foundAddress = placeTable[key]->getAddress();
			int i = index;
			while (address[i] != NUL && hash(foundAddress[i]) == hash(address[i])) {
				i += 1;
			}
			if (hash(foundAddress[i - 1]) == hash(address[i - 1])) {
				return new Node<Place>(placeTable[key]);
			}
            return NULL;
        }
    }

    return NULL;
}