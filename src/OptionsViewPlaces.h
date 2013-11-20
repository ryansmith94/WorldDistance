#ifndef OptionsViewPlaces_H
#define OptionsViewPlaces_H
#include <iostream>
#include "OptionsView.h"
#include "Place.h"
#include "LList.h"
#ifndef LF
#define LF (char)0x0A
#endif

class OptionsViewPlaces: public OptionsView<LList<Place> > {
    protected:
        LList<Place>* options;
    public:
        OptionsViewPlaces(LList<Place>* opts);
        OptionsViewPlaces* display();
};

#endif
