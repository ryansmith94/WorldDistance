#ifndef DeletePlacesView_H
#define DeletePlacesView_H
#include <iostream>
#include "View.cpp"
using namespace std;

class DeletePlacesView: public View {
    public:
        DeletePlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}
        DeletePlacesView* start() {
            return this;
        }
};

#endif
