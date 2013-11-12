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

class DistanceApp {
        Place rootPlace;
        HashTable hashTable;
        string dataLocation;
    public:
        DistanceApp(string loadLocation = "data.txt", string saveLocation = "data.txt");
        ~DistanceApp();
        DistanceApp* start();
};

#endif
