#ifndef AddPlacesView_CPP
#define AddPlacesView_CPP
#include <iostream>
#include "AddPlacesView.h"
#include "Place.h"
#include "HashTable.h"
using namespace std;

AddPlacesView::AddPlacesView(Place* place, HashTable* hTable) : View(place, hTable){}
AddPlacesView* AddPlacesView::start() {
    return this;
}

#endif
