#ifndef PlacesView_H
#define PlacesView_H
#include <iostream>
#include "View.cpp"
using namespace std;

class PlacesView: public View {
    public:
        PlacesView(Place* place) : View(place) {}
        PlacesView* start() {
            return this;
        }
};

#endif
