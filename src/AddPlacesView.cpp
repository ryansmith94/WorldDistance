#ifndef AddPlacesView_H
#define AddPlacesView_H
#include <iostream>
#include "View.cpp"
using namespace std;

class AddPlacesView: public View {
    public:
        AddPlacesView(Place* place, HashTable* hTable) : View(place, hTable){}
        AddPlacesView* start() {
            return this;
        }
};

#endif
