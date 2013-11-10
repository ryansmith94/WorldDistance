#ifndef DistanceApp_H
#define DistanceApp_H
#include <string>

class Place;
class hashTable;

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
