#include "PlacesView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

PlacesView::PlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}
PlacesView* PlacesView::start() {
    string address = getAddress(0, "Enter the name of a place");
    Node<Place>* node = hashTable->get(address);

	cout << "\tAddress (Longitude, Latitude)" << LF;

	while (node != NULL && node->getData() != NULL) {
		Place* place = node->getData();
		cout << "\t" << place->getAddress() << " (" << place->getLongitude() << ", " << place->getLatitude() << ")" << LF;
        node = node->getNext();
	}

	return this;
}
