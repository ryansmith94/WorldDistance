#ifndef DistanceApp_H
#define DistanceApp_H
#include <iostream>
#include <string>
#include "OptionsView.h"
#include "Place.h"
#include "DistanceView.h"
#include "PlacesView.h"
#include "AddPlacesView.h"
#include "ModifyPlaceView.h"
#include "DeletePlacesView.h"
#include "HashTable.h"
using namespace std;

/**
 * @author Ryan Smith, Oliver Parker
 */
class DistanceApp {
        HashTable hashTable;
		Place rootPlace;
        string dataLocation;
    public:
    	/**
    	 * Constructs a DistanceApp.
    	 * @param loadLocation (optional) the file location to load places from. Defaults to "data.txt".
    	 * @param saveLocation (optional) the file location to save places to. Defaults to "data.txt".
    	 * @pre loadLocation must exist and be correctly formatted.
    	 * @pre saveLocation's directory must exist.
    	 * @post constructed DistanceApp and loaded places from loadLocation.
    	 */
        DistanceApp(string loadLocation = "data.txt", string saveLocation = "data.txt");

        /**
         * Destructs a DistanceApp.
         * @pre saveLocation's directory must exist.
         * @post destructed DistanceApp and saved places to saveLocation.
         */
        ~DistanceApp();

        /**
         * Starts and runs the app.
         */
        DistanceApp* start();
};

#endif
