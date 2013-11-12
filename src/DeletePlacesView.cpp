#include "DeletePlacesView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

DeletePlacesView::DeletePlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}
DeletePlacesView* DeletePlacesView::start() {
    return this;
}
