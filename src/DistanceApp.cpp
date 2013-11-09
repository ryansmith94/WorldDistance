#ifndef DistanceApp_H
#define DistanceApp_H
#include <iostream>
#include <string>
#include "OptionsView.cpp"
#include "Place.cpp"
#include "DistanceView.cpp"
#include "PlacesView.cpp"
#include "AddPlacesView.cpp"
#include "ModifyPlacesView.cpp"
#include "DeletePlacesView.cpp"
#include "HashTable.cpp"
using namespace std;

class DistanceApp {
        Place rootPlace;
        HashTable hashTable;
        string dataLocation;
    public:
        DistanceApp(string loadLocation = "data.txt", string saveLocation = "data.txt") : rootPlace("Earth", 0.0, 0.0) {
            dataLocation = saveLocation;
            rootPlace.loadPlace(loadLocation);
        }
        ~DistanceApp() {
            rootPlace.savePlace(dataLocation);
        }
        DistanceApp* start() {
            string opts[6] = {"Distance", "Places", "Add place", "Modify place", "Delete place", "Quit"};
            OptionsView<string> optionsView(opts, 6);
            DistanceView distanceView(&rootPlace, &hashTable);
            PlacesView placesView(&rootPlace, &hashTable);
            AddPlacesView addPlacesView(&rootPlace, &hashTable);
            ModifyPlacesView modifyPlacesView(&rootPlace, &hashTable);
            DeletePlacesView deletePlacesView(&rootPlace, &hashTable);
            int selected;

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
};
#endif
