#include "PlacesView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

PlacesView::PlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}
PlacesView* PlacesView::start() {
    
	cout << rootPlace->getName() << "\tcontains " << rootPlace->getNbrChildren() << " Children:" << endl << endl;

	cout << "Name" << "\t\t| " << "Longitude" << "\t| " << "Latitude" << endl;

	for (int i=0; i < rootPlace->getNbrChildren(); i++) {
		Place* child = rootPlace->getChild(i);

		// Tab Aesthetics for longer names (Greater than tab width (8) - 2 (see cout's second param))
		string n = (child->getName().length()<6) ? (child->getName()+"\t"):(child->getName());

		cout << ". " << n << "\t| " << child->getLongitude() << "\t| " << child->getLatitude() << endl;
	}

	return this;
}
