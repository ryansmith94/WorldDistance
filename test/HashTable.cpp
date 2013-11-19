#ifndef TestHashTable_H
#define TestHashTable_H
#include "../src/HashTable.h"
#include "igloo/igloo_alt.h"
using namespace igloo;

Describe(HashTable_class){
    It(should_expose_a_add_method){
        Assert::That(!!(&HashTable::add), Equals(1));
    }
    It(should_expose_a_remove_method){
        Assert::That(!!(&HashTable::remove), Equals(1));
    }
    It(should_expose_a_get_method){
        Assert::That(!!(&HashTable::get), Equals(1));
    }
    Describe(add_method) {
        It(should_add_a_place) {
            HashTable hashTable;
            Assert::That(hashTable.add(new Place("earth", 0.0, 0.0)) == &hashTable, Equals(1));
        }
        It(should_not_add_a_place_that_already_exists) {
            HashTable hashTable;
            hashTable.add(new Place("earth", 0.0, 0.0));
            Assert::That(hashTable.add(new Place("earth", 0.0, 0.0)) == NULL, Equals(1));
        }
    };
    Describe(remove_method) {
        It(should_remove_an_existing_place) {
            HashTable hashTable;
            Place place("earth", 0.0, 0.0);
            hashTable.add(&place);
            Assert::That(hashTable.remove(&place), Equals(&hashTable));
        }
    };
    Describe(get_method) {
        It(should_return_places_that_contain_the_given_address) {
            HashTable hashTable;
            Place place("earth", 0.0, 0.0);
            hashTable.add(&place);
            Assert::That(!!hashTable.get("e"), Equals(1));
            Assert::That(hashTable.get("earth")->getData(), Equals(&place));
        }
        It(should_return_null_if_no_places_contain_the_given_address) {
            HashTable hashTable;
            Place place("earth", 0.0, 0.0);
            hashTable.add(&place);
            Assert::That(hashTable.get("c") == NULL, Equals(1));
        }
    };
};

#endif
