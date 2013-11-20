#include "PlacesView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

PlacesView::PlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}
PlacesView* PlacesView::start() {
    string address = getAddress(0, "Enter the name of a place");
    LList<Place>* matched = hashTable->get(address);
    int size = matched->getSize();

	cout << "\tAddress (Longitude, Latitude)" << LF;

    for (int i = 0; i < size; i += 1) {
        Place* place = matched->getData(i);
        cout << "\t" << place->getAddress() << " (" << place->getLongitude() << ", " << place->getLatitude() << ")" << LF;
    }

	return this;
}
