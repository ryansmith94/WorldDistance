#ifndef DistanceApp_H
#define DistanceApp_H
#include <string>
#include "OptionsView.cpp"
#include "Place.cpp"
#include "DistanceView.cpp"
#include "PlacesView.cpp"
#include "AddPlacesView.cpp"
#include "ModifyPlacesView.cpp"
#include "DeletePlacesView.cpp"
using namespace std;

class DistanceApp {
        Place rootPlace;
        string dataLocation;
    public:
        DistanceApp() : rootPlace("Earth", 0.0, 0.0) {
            dataLocation = "data.txt";
            rootPlace.loadPlace(dataLocation);
        }
        DistanceApp* start() {
            string opts[6] = {"Distance", "Places", "Add place", "Modify place", "Delete place", "Quit"};
            OptionsView<string> optionsView(opts, 6);
            DistanceView distanceView(&rootPlace);
            PlacesView placesView(&rootPlace);
            AddPlacesView addPlacesView(&rootPlace);
            ModifyPlacesView modifyPlacesView(&rootPlace);
            DeletePlacesView deletePlacesView(&rootPlace);
            int selected;

            do {
                selected = optionsView.display()->getOption();

                if (selected == 0) {
                    distanceView.start();
                } else if (selected == 1) {
                    placesView.start();
                } else if (selected == 2) {
                    addPlacesView.start();
                } else if (selected == 3) {
                    modifyPlacesView.start();
                } else if (selected == 4) {
                    deletePlacesView.start();
                }
            } while (selected != 5);

            return this;
        }
};
#endif
