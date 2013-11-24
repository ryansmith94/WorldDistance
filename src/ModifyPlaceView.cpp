#include "ModifyPlaceView.h"
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
float ModifyPlacesView::inputFloat(string message){
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

/**Constructor takes a pointer to a Place Object
 * Said Place Object is to have certain properties modified by the ModifyPlacesView::start() method
 *
 * @see	ModifyPlacesView::start()
 */
ModifyPlacesView::ModifyPlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}

/**Operational method for the class;
 * Called to prompt the user to specificy the Place Object's attribute they wish to change, and
 * the value to set it to.
 *
 * @return	Returns a pointer to itself (this)
 */
ModifyPlacesView* ModifyPlacesView::start() {
    Place* place = getPlace(rootPlace);
    string opts[3] = {"Name", "Longitude", "Latitude"};
    OptionsView<string> view(opts, 3);
    int menuSelection = 0;

    do {
        cout << LF << "\tWhat would you like to modify?" << LF;
        switch (menuSelection = view.display()->getOption()) {
            case 0:
                place->setName(getAddress(1, "Please enter the name"));
                break;
            case 1:
                place->setLongitude(inputFloat("Please enter the longitude"));
                break;
            case 2:
                place->setLatitude(inputFloat("Please enter the latitude"));
                break;
        }
    } while (menuSelection != 3);

    return this;
}
