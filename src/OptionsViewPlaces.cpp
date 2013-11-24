#include "OptionsViewPlaces.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

OptionsViewPlaces::OptionsViewPlaces(LList<Place>* opts) : OptionsView<LList<Place> >(opts, opts->getSize()) {
    options = opts;
}
OptionsViewPlaces* OptionsViewPlaces::display() {
    // Output the addresses of all of the places to cout.
    for (int i = 0; i < numberOfOptions; i += 1) {
        cout << "\t" << i + 1 << ". " << options->getData(i)->getAddress() << LF;
    }

    // Output the Exit option to cout.
    cout << "\t" << numberOfOptions + 1 << ". Exit" << LF;

    return this;
}
