#include "PlacesView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

PlacesView::PlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}
PlacesView* PlacesView::start() {
    return this;
}