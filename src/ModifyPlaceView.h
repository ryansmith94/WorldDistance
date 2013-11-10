#ifndef ModifyPlacesView_H
#define ModifyPlacesView_H
#include "View.h"
using namespace std;

class ModifyPlacesView: public View {
    public:
        ModifyPlacesView(Place* place, HashTable* hTable);
        ModifyPlacesView* start();
};

#endif
