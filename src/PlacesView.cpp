#ifndef PlacesView_H
#define PlacesView_H
#include <iostream>
#include "View.cpp"
using namespace std;

class PlacesView: public View {
public:
    PlacesView(Place* place) : View(place) {}
    PlacesView* start() {

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
};

#endif
