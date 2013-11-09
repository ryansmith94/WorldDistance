#ifndef PlacesView_H
#define PlacesView_H
#include <iostream>
#include "View.cpp"
using namespace std;

class PlacesView: public View {
    public:
        PlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}
        PlacesView* start() {
            return this;
        }
};

#endif
