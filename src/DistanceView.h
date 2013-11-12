#ifndef DistanceView_H
#define DistanceView_H
#include "View.h"
#include <cmath>
#include "Place.h"
#include "HashTable.h"

class DistanceView: public View {
        double calculateDistance(Place* from, Place* to);
    public:
        DistanceView(Place* place, HashTable* hTable);
        DistanceView* start();
};

#endif
