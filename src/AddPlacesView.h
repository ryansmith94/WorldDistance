#ifndef AddPlacesView_H
#define AddPlacesView_H
#include "View.h"

class Place;
class HashTable;

class AddPlacesView: public View {
    public:
        AddPlacesView(Place* place, HashTable* hTable);
        AddPlacesView* start();
};

#endif
