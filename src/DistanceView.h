#ifndef DistanceView_H
#define DistanceView_H
#include "View.h"

class Place;
class HashTable;

class DistanceView: public View {
        double calculateDistance(Place* from, Place* to);
    public:
        DistanceView(Place* place, HashTable* hTable);
        DistanceView* start();
};

#endif
