#include "ModifyPlaceView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

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
ModifyPlacesView::ModifyPlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}
ModifyPlacesView* ModifyPlacesView::start() {
        Place* place = getPlace(rootPlace);
        string opts[4] = {"Name", "Longitude", "Latitude", "Nothing"};
        OptionsView<string> view(opts, 4);
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
