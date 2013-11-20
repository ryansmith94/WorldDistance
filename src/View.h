#ifndef View_H
#define View_H
#include <iostream>
#include <sstream>
#include <string>
#include "Place.h"
#include "HashTable.h"
#include "LList.h"
#include "OptionsViewPlaces.h"
using namespace std;

class View {
    protected:
        Place* rootPlace;
        HashTable* hashTable;
        string getAddress(int rejectEmpty = 0, string message = "");
        Place* getPlace(Place* rootPlace = NULL, string message = "");
    public:
        View(Place* place, HashTable* hTable);
        virtual View* start() =0;
};

#endif
