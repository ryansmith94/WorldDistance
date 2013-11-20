#include "OptionsViewPlaces.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

OptionsViewPlaces::OptionsViewPlaces(Node<Place>* opts) : OptionsView<Node<Place> >(opts, 0) {
    options = opts;
}
OptionsViewPlaces* OptionsViewPlaces::display() {
    Node<Place>* option = options;
    int i = 0;

    while (option != NULL && option->getData() != NULL) {
        cout << "\t" << ++i << ". " << option->getData()->getAddress() << LF;
        option = option->getNext();
    }

    numberOfOptions = i;
    return this;
}
