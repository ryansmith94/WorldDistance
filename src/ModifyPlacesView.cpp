#ifndef ModifyPlacesView_H
#define ModifyPlacesView_H
#include <iostream>
#include "View.cpp"
using namespace std;

class ModifyPlacesView: public View {
    public:
        ModifyPlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}
        ModifyPlacesView* start() {
            return this;
        }
};

#endif
