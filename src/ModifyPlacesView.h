#ifndef ModifyPlacesView_H
#define ModifyPlacesView_H
#include <iostream>
#include "View.h"
using namespace std;

class ModifyPlacesView: public View {
    public:
        ModifyPlacesView(Place* place) : View(place) {}
        ModifyPlacesView* start() {
            return this;
        }
};

#endif
