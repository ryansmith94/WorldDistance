#include "AddPlacesView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

AddPlacesView::AddPlacesView(Place* place, HashTable* hTable) : View(place, hTable){}
AddPlacesView* AddPlacesView::start() {
    return this;
}
