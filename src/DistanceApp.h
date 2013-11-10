#ifndef DistanceApp_H
#define DistanceApp_H
#include <string>
#include "HashTable.h"
#include "Place.h"
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
