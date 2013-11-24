#ifndef OptionsViewPlaces_H
#define OptionsViewPlaces_H
#include <iostream>
#include "OptionsView.h"
#include "Place.h"
#include "LList.h"
#ifndef LF
#define LF (char)0x0A
#endif

/**
 * @author Ryan Smith
 */
class OptionsViewPlaces: public OptionsView<LList<Place> > {
    private:
        LList<Place>* options;
    public:
    	/**
    	 * Constructs a OptionsViewPlaces.
         * @param opts a linked list that may contain places.
         * @pre opts != NULL.
         * @post constructed OptionsViewPlaces with a list of places as options.
    	 */
        OptionsViewPlaces(LList<Place>* opts);

        /**
         * Displays the options (places and exit).
         * @post options (places and exit) printed to `cout`.
         */
        OptionsViewPlaces* display();
};

#endif
