#ifndef ModifyPlacesView_CPP
#define ModifyPlacesView_CPP
#include <iostream>
#include "ModifyPlaceView.h"
#include "View.h"
using namespace std;

ModifyPlacesView::ModifyPlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}
ModifyPlacesView* ModifyPlacesView::start() {
    return this;
}

#endif
