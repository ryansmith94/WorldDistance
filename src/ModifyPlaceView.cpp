#ifndef ModifyPlaceView_CPP
#define ModifyPlaceView_CPP
#include <iostream>
#include "ModifyPlaceView.h"
#include "View.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

ModifyPlacesView::ModifyPlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}
ModifyPlacesView* ModifyPlacesView::start() {
    return this;
}

#endif
