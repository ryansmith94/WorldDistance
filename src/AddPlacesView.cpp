#include "AddPlacesView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

/**
 * @author Harley Bristow
 */

/**Interfaces with the user, prompting the entry of a float value.
 * 
 * @param	Takes a message to display in console for the user
 * @return	Returns a float 
 */
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

/**Constructor takes a pointer to a Place Object, intended to be a Parent
 * Said Object is to be the parent of the Child-Object created within AddPlacesView::Start()
 *
 * @see	AddPlacesView::start()
 */
AddPlacesView::AddPlacesView(Place* place, HashTable* hashTable) : View(place, hashTable){}

/**Operational method for the class;
 * Called to prompt the user for the properties of a new Place Object
 *
 *  @return	Returns a pointer to itself (this)
 */
AddPlacesView* AddPlacesView::start() {
	Place* parent = getPlace();
	string name = getAddress(1, "Please enter the name");
	float longitude = inputFloat("Please enter the longitude");
	float latitude = inputFloat("Please enter the latitude");

	Place* p = new Place(name, longitude, latitude);
	parent->addChild(p);
	cout << "Place added" << LF;

	return this;
}
