#ifndef DeletePlacesView_H
#define DeletePlacesView_H
#include "View.h"

class Place;
class HashTable;

class DeletePlacesView: public View {
    public:
        DeletePlacesView(Place* place, HashTable* hTable);
        DeletePlacesView* start();
};

#endif
