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
            Place place1("placeA", 0.0, 0.0);
            Place place2("placeB", 0.0, 0.0);
            hashTable.add(&place1);
            hashTable.add(&place2);

            LList<Place>* get1 = hashTable.get("");
            Assert::That(get1->getSize() == 2 && (get1->getData(0) == &place1 || get1->getData(1) == &place1), Equals(1));
            Assert::That(get1->getSize() == 2 && (get1->getData(0) == &place2 || get1->getData(1) == &place2), Equals(1));

            LList<Place>* get2 = hashTable.get("p");
            Assert::That(get2->getSize() == 2 && (get2->getData(0) == &place1 || get2->getData(1) == &place1), Equals(1));
            Assert::That(get2->getSize() == 2 && (get2->getData(0) == &place2 || get2->getData(1) == &place2), Equals(1));

            LList<Place>* get3 = hashTable.get("placeA");
            Assert::That(get3->getSize() == 1 && (get3->getData(0)) == &place1, Equals(1));
        }
        It(should_return_no_places_if_no_places_contain_the_given_address) {
            HashTable hashTable;
            Place place1("placeA", 0.0, 0.0);
            hashTable.add(&place1);
            Assert::That(hashTable.get("c")->getSize(), Equals(0));
            Assert::That(hashTable.get("cat")->getSize(), Equals(0));
            Assert::That(hashTable.get("placeC")->getSize(), Equals(0));
            Assert::That(hashTable.get("p", &place1)->getSize(), Equals(0));
            Assert::That(hashTable.get("", &place1)->getSize(), Equals(0));
            Assert::That(hashTable.get("placeAB", &place1)->getSize(), Equals(0));
        }
    };
};

#endif
