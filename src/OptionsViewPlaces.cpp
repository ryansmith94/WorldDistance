#include "OptionsViewPlaces.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

OptionsViewPlaces::OptionsViewPlaces(LList<Place>* opts) : OptionsView<LList<Place> >(opts, opts->getSize()) {
    options = opts;
}
OptionsViewPlaces* OptionsViewPlaces::display() {
    for (int i = 0; i < numberOfOptions; i += 1) {
        cout << "\t" << i + 1 << ". " << options->getData(i)->getAddress() << LF;
    }
    cout << "\t" << numberOfOptions + 1 << ". Exit" << LF;

    return this;
}
