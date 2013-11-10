#ifndef OptionsViewPlaces_H
#define OptionsViewPlaces_H
#include <iostream>
#include "OptionsView.cpp"
#include "Place.cpp"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

class OptionsViewPlaces: public OptionsView<Node<Place> > {
    protected:
        Node<Place>* options;
    public:
        OptionsViewPlaces(Node<Place>* opts) : OptionsView<Node<Place> >(opts, 0) {
            options = opts;
        }
        OptionsViewPlaces* display() {
            Node<Place>* option = options;
            int i = 0;

            while (option != NULL && option->getData() != NULL) {
                cout << "\t" << i + 1 << ". " << option->getData()->getAddress() << LF;
                option = option->getNext();
                i += 1;
            }

            numberOfOptions = i;
            return this;
        }
};

#endif
