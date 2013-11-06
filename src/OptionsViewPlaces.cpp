#ifndef OptionsViewPlaces_H
#define OptionsViewPlaces_H
#include <iostream>
#include "OptionsView.cpp"
#include "Place.cpp"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

class OptionsViewPlaces: public OptionsView<LList<Place> > {
    protected:
        LList<Place>* options;
    public:
        OptionsViewPlaces(LList<Place>* opts) : OptionsView<LList<Place> >(opts, opts->getSize()) {
            options = opts;
        }
        OptionsViewPlaces* display() {
            for (int i = 0; i < numberOfOptions; i += 1) {
                cout << i + 1 << ". " << options->getData(i)->getAddress() << LF;
            }
            cout << LF;
            return this;
        }
};

#endif
