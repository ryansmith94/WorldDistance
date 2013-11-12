#ifndef AddPlacesView_H
#define AddPlacesView_H
#include <iostream>
#include "AddPlacesView.h"
#include "Place.h"
#include "HashTable.h"
#include "View.h"

class AddPlacesView: public View {
    public:
        AddPlacesView(Place* place, HashTable* hTable);
        AddPlacesView* start();
};

#endif
