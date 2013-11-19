#include "OptionsViewPlaces.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

OptionsViewPlaces::OptionsViewPlaces(Node<Place>* opts) : OptionsView<Node<Place> >(opts, 0) {
    options = opts;
}
OptionsViewPlaces* OptionsViewPlaces::display(Place* rootPlace) {
    Node<Place>* option = options;
    int i = 0;

    while (option != NULL && option->getData() != NULL) {
        if (option->getData() != rootPlace) {
            cout << "\t" << i + 1 << ". " << option->getData()->getAddress() << LF;
        }
        option = option->getNext();
        i += 1;
    }

    numberOfOptions = i;
    return this;
}
