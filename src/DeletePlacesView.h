#ifndef DeletePlacesView_H
#define DeletePlacesView_H
#include "View.h"
#include <iostream>
#include "Place.h"
#include "HashTable.h"

class DeletePlacesView: public View {
    public:
        DeletePlacesView(Place* place, HashTable* hTable);
        DeletePlacesView* start();
};

#endif
