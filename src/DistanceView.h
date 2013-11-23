#ifndef DistanceView_H
#define DistanceView_H
#include "View.h"
#include <cmath>
#include "Place.h"
#include "HashTable.h"

/**
 * @author Ryan Smith
 */
class DistanceView: public View {
	private:
		/**
		 * Calculates the distance between to places in kilometers.
		 * @param from origin.
		 * @param to destination.
		 * @pre from != NULL && to != NULL.
		 * @return distance between to places in kilometers.
		 */
        double calculateDistance(Place* from, Place* to);
    public:
    	/**
    	 * Constructs a DistanceView.
    	 * @param place the root place.
    	 * @param hTable a hash table that can contains places.
    	 * @pre place != NULL && hTable != NULL.
    	 * @post constructed DistanceView with a root place and hash table.
    	 */
        DistanceView(Place* place, HashTable* hTable);

        /**
         * Starts and runs the view.
         */
        DistanceView* start();
};

#endif
