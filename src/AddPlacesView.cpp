#include "AddPlacesView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

float AddPlacesView::inputFloat(string message){
	float selected;
    string input;

	do {
        cout << "<\t" << message << ": ";
        getline(cin, input);
        stringstream myStream(input);
        myStream >> selected;
	} while (selected == 0 && input != "0");

    return selected;
}
AddPlacesView::AddPlacesView(Place* place, HashTable* hashTable) : View(place, hashTable){}
AddPlacesView* AddPlacesView::start() {
    Place* parent = getPlace();
    string name = getAddress(1, "Please enter the name");
    float longitude = inputFloat("Please enter the longitude");
    float latitude = inputFloat("Please enter the latitude");

    Place* p = new Place(name, longitude, latitude);
	parent->addChild(p);
	cout << "Place added" << LF;
	
    //if (hashTable->add(p) != NULL) {
    //    parent->addChild(p);
    //    cout << "Place added" << LF;
    //} else {
    //    cout << "Place could not be added" << LF;
    //}



    return this;
}
