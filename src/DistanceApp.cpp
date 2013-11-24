#include "DistanceApp.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

DistanceApp::DistanceApp(string loadLocation, string saveLocation) : rootPlace("Earth", 0.0, 0.0) {
    dataLocation = saveLocation;
    rootPlace.loadPlace(loadLocation, &hashTable);
}
DistanceApp::~DistanceApp() {
    rootPlace.savePlace(dataLocation);

}
DistanceApp* DistanceApp::start() {
    // Setup menu.
    string opts[5] = {"Distance", "Places", "Add place", "Modify place", "Delete place"};
    OptionsView<string> optionsView(opts, 5);
    int selected;

    // Construct views.
    DistanceView distanceView(&rootPlace, &hashTable);
    PlacesView placesView(&rootPlace, &hashTable);
    AddPlacesView addPlacesView(&rootPlace, &hashTable);
    ModifyPlacesView modifyPlacesView(&rootPlace, &hashTable);
    DeletePlacesView deletePlacesView(&rootPlace, &hashTable);

    // Provide menu and start/run views.
    do {
        cout << "WORLD DISTANCE" << LF;
        selected = optionsView.display()->getOption();
        cout << LF;

        if (selected == 0) {
            cout << "DISTANCE" << LF;
            distanceView.start();
        } else if (selected == 1) {
            cout << "PLACES" << LF;
            placesView.start();
        } else if (selected == 2) {
            cout << "ADD PLACE" << LF;
            addPlacesView.start();
        } else if (selected == 3) {
            cout << "MODIFY PLACE" << LF;
            modifyPlacesView.start();
        } else if (selected == 4) {
            cout << "DELETE PLACE" << LF;
            deletePlacesView.start();
        }
        cout << LF;
    } while (selected != 5);

    return this;
}
