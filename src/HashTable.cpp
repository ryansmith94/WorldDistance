#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "Place.cpp"
#include "Node.cpp"
#define A 97
#define Z 122
#define SPACE 32
#define NUL 0
#define COMMA 44
#define LIMIT 29

class HashTable {
    private:
        Place* placeTable[LIMIT];
        HashTable* hashTable[LIMIT];
        int index;
        int count = 0;

        int hash(string value) {
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

            return 0;
        }
        // Return the hashtable that the place is added to.
        HashTable* addPlace(string address, Place* place) {
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
        Node<Place>* tableToNodes(Node<Place>* lastNode) {
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
        int getNbrPlaces() {
            return count;
        }
    public:
        HashTable(int nIndex = 0) {
            index = nIndex;
        }
        HashTable* add(Place* place) {
            return addPlace(place->getAddress(), place);
        }
        HashTable* remove(string address) {
            return this;
        }
        Node<Place>* get(string address) {
            int key = hash(address);

            // Get from hashtable.
            if (hashTable[key] != NULL) {
                if (address[index + 1] != NUL) {
                    return hashTable[key]->get(address);
                } else {
                    return hashTable[key]->tableToNodes(NULL);
                }
            }

            return new Node<Place>(placeTable[key]);
        }
};

int main() {
    HashTable ht;

    Place* place1 = new Place("earth", 0.0, 0.0);
    Place* place2 = new Place("uk", 0.0, 0.0);
    Place* place3 = new Place("birmingham", 0.0, 0.0);
    Place* place4 = new Place("us", 0.0, 0.0);
    Place* place5 = new Place("alabama", 0.0, 0.0);
    Place* place6 = new Place("birmingham", 0.0, 0.0);

    place1->addChild(place2);
    place2->addChild(place3);
    place1->addChild(place4);
    place4->addChild(place5);
    place5->addChild(place6);

    cout << ht.add(place1) << (char)0x0A;
    cout << ht.add(place2) << (char)0x0A;
    cout << ht.add(place3) << (char)0x0A;
    cout << ht.add(place4) << (char)0x0A;
    cout << ht.add(place5) << (char)0x0A;
    cout << ht.add(place6) << (char)0x0A;

    Node<Place>* p = ht.get("b");
    while (p != NULL) {
        cout << p->getData()->getAddress() << (char)0x0A;
        p = p->getNext();
    }

    return 0;
}

#endif