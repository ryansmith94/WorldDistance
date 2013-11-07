#ifndef View_H
#define View_H
#include <iostream>
#include <sstream>
#include <string>
#include "Place.cpp"
#include "OptionsViewPlaces.cpp"
using namespace std;

class View {
    protected:
        Place* rootPlace;
        string getAddress(int rejectEmpty = 0) {
            string address;
            do {
                cout << "<\tPlease enter an address: ";
                cin.clear();
                cin.ignore();
                getline(cin, address);
            } while (rejectEmpty == 1 && address == "");
            return address;
        }
        Place* getPlace() {
        	Place* place = NULL;


        	do {
        		LList<Place>* matched = rootPlace->getMatchedChildren(getAddress(1));
        		int size = matched->getSize();

        		if (size == 1) {
        			place = matched->getData(0);
        		} else if (size > 1) {
                    OptionsViewPlaces view(matched);
        			place = matched->getData(view.display()->getOption());
        		}
        	} while (place == NULL);

        	return place;
        }
    public:
        View(Place* place) {
            rootPlace = place;
        }
        virtual View* start() =0;
};

#endif
