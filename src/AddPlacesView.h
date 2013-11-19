#ifndef AddPlacesView_H
#define AddPlacesView_H
#include <iostream>
#include "AddPlacesView.h"
#include "Place.h"
#include "HashTable.h"
#include "View.h"

class AddPlacesView: public View {
    private:
        float inputFloat(string message);
    public:
        AddPlacesView(Place* place, HashTable* hashTable);
        AddPlacesView* start();
};

#endif
