#ifndef AddPlacesView_CPP
#define AddPlacesView_CPP
#include <iostream>
#include "AddPlacesView.h"
#include "Place.h"
#include "HashTable.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

AddPlacesView::AddPlacesView(Place* place, HashTable* hTable) : View(place, hTable){}
AddPlacesView* AddPlacesView::start() {
    return this;
}

#endif
