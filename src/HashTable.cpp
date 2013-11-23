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
    // Get the integer value of the character.
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
    // Hash the character at index in the address to get the key.
    int key = hash(address[index]);

    // If a place is already associated with the key, create a sub-HashTable if the addresses are not the same.
    // Else if a sub-HashTable is associated with the key, add the place to the sub-HashTable.
    // Else add the place to the current HashTable.
    if (placeTable[key] != NULL) {
        // If the address is already in use do not add (return NULL).
        if (address == placeTable[key]->getAddress()) {
            return NULL;
        }

        // If the address is not in use, create a new HashTable and associate it with the key.
        HashTable* ht = new HashTable(index + 1);
        hashTable[key] = ht;

        // Add the place that was previously associated to the key to the new HashTable.
        ht->addPlace(placeTable[key]->getAddress(), placeTable[key]);
        placeTable[key] = NULL;

        // Add the given place to the new HashTable.
        count += 1;
        return ht->addPlace(address, place);
    } else if (hashTable[key] != NULL) {
        // Add the given place to the Hashtable associated with the key.
        HashTable* ht = hashTable[key]->addPlace(address, place);
        if (ht != NULL) {
            count += 1;
        }

        // Return the sub-HashTable that the place was added to (can be NULL if not added).
        return ht;
    } else {
        // Associate the key with the given place and return the current HashTable.
        count += 1;
        placeTable[key] = place;
        return this;
    }
}

// Return the hashtable that the place was removed from.
HashTable* HashTable::removePlace(string address, Place* place) {
    // Hash the character at index in the address to get the key.
    int key = hash(address[index]);

    // If a sub-HashTable is associated with the key, remove the place from the sub-HashTable.
    // Else if a place is associated with the key, remove it from the current Hashtable.
    // Else return NULL because it could not be removed.
    if (hashTable[key] != NULL) {
        // If the given address does have more characters remove the Place from the sub-HashTable.
        if (address[index + 1] != NUL) {
            HashTable* ht = hashTable[key]->removePlace(address, place);
            if (ht != NULL) {
                count -= 1;

                // If the sub-HashTable contains no places, delete to reduce memory usage.
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
LList<Place>* HashTable::tableToNodes(Place* rootPlace) {
    // Clear the search results to reduce memory usage and so only relevant results are returned.
    searchResults.clear();

    // Get all of the places contained in the current Hashtable and add them to search results.
    for (int i = 0; i < LIMIT; i += 1) {
        // If the index (i) contains a sub-HashTable add all the places in that sub-HashTable to search results.
        // Else if the index (i) contains a place and it isn't the rootPlace, append it to the search results.
        if (hashTable[i] != NULL) {
            searchResults.addAll(hashTable[i]->tableToNodes(rootPlace));
        } else if (placeTable[i] != NULL && placeTable[i] != rootPlace) {
            searchResults.append(placeTable[i]);
        }
    }

    return &searchResults;
}

HashTable::HashTable(int nIndex) {
    index = nIndex;
    count = 0;

    // Intialise the table to contain NULL entries (no associations to keys).
    for (int i = 0;i<LIMIT;i++){
        placeTable[i] = NULL;
        hashTable[i] = NULL;
    }
}

HashTable::~HashTable() {
    // Clear the search results to avoid dangling pointers.
    searchResults.clear();

    // Delete all sub-HashTables to avoid dangling pointers.
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

LList<Place>* HashTable::get(string address, Place* rootPlace) {
    // Clear the search results to reduce memory usage and so only relevant results are returned.
    searchResults.clear();

    // Return entire hashtable.
    if (address[index] == NUL) {
        return tableToNodes(rootPlace);
    }

    // Hash the character at index in the address to get the key.
    int key = hash(address[index]);

    // If the key is associated with sub-HashTable continue searching in the sub-HashTable.
    // Else if the key is assocaited with a Place append the Place to the search results.
    if (hashTable[key] != NULL) {
        // If the address contains more characters continue searching the sub-HashTable.
        // Else return the all of the places in the sub-HashTable.
        if (address[index + 1] != NUL) {
            searchResults.addAll(hashTable[key]->get(address, rootPlace));
        } else {
            searchResults.addAll(hashTable[key]->tableToNodes(rootPlace));
        }
    } else if (placeTable[key] != NULL) {
        // If the address does not contain more characters append the place associated with the key to search results (if it's not the root).
        // Else check if the addresses are similar before appending to the search results.
        if (address[index + 1] == NUL) {
            if (placeTable[key] != rootPlace) {
                searchResults.append(placeTable[key]);
            }
        } else {
            // Don't compare the addresses if the rootPlace has been found.
            if (rootPlace != placeTable[key]) {
                string foundAddress = placeTable[key]->getAddress();
                int i = index + 1;

                // Compare the hash of the characters in the found address with the given address.
                while (address[i] != NUL && hash(foundAddress[i]) == hash(address[i])) {
                    i += 1;
                }

                // Append the found place to search results if last comparison was equal or if the end of the given address has been reached.
                if (address[i] == NUL || hash(foundAddress[i]) == hash(address[i])) {
                    searchResults.append(placeTable[key]);
                }
            }
        }
    }

    return &searchResults;
}