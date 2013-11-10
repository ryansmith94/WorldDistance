#ifndef OptionsViewPlaces_H
#define OptionsViewPlaces_H
#include <iostream>
#include "OptionsView.h"
#include "Node.h"

class Place;

class OptionsViewPlaces: public OptionsView<Node<Place> > {
    protected:
        Node<Place>* options;
    public:
        OptionsViewPlaces(Node<Place>* opts);
        OptionsViewPlaces* display();
};

#endif
