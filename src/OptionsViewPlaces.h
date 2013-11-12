#ifndef OptionsViewPlaces_H
#define OptionsViewPlaces_H
#include <iostream>
#include "OptionsView.h"
#include "Place.h"
#include "Node.h"
#ifndef LF
#define LF (char)0x0A
#endif

class OptionsViewPlaces: public OptionsView<Node<Place> > {
    protected:
        Node<Place>* options;
    public:
        OptionsViewPlaces(Node<Place>* opts);
        OptionsViewPlaces* display();
};

#endif
