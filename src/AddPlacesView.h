#ifndef AddPlacesView_H
#define AddPlacesView_H
#include <iostream>
#include "View.h"
using namespace std;

class AddPlacesView: public View {
    public:
        AddPlacesView(Place* place) : View(place) {}
        AddPlacesView* start() {
            return this;
        }
};

#endif
