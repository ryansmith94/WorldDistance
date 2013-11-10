#ifndef View_H
#define View_H
#include <iostream>
#include <sstream>
#include <string>
#include "Place.h"
#include "OptionsViewPlaces.cpp"
#include "HashTable.h"
using namespace std;

class View {
    protected:
        Place* rootPlace;
        HashTable* hashTable;
        string getAddress(int rejectEmpty = 0) {
            string address;
            do {
                cout << "<\tPlease enter an address: ";
                getline(cin, address);
            } while (rejectEmpty == 1 && address == "");
            return address;
        }
        Place* getPlace() {
        	Place* place = NULL;

        	do {
        		Node<Place>* matched = hashTable->get(getAddress(1));

                if (matched != NULL) {
                    OptionsViewPlaces view(matched);
                    int selected = view.display()->getOption();

                    for (int i = 0; i < selected; i += 1) {
                        matched = matched->getNext();
                    }

                    place = matched->getData();
                }
        	} while (place == NULL);

        	return place;
        }
    public:
        View(Place* place, HashTable* hTable) {
            rootPlace = place;
            hashTable = hTable;
        }
        virtual View* start() =0;
};

#endif
