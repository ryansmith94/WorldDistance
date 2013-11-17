#include "ModifyPlaceView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

ModifyPlacesView::ModifyPlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}
ModifyPlacesView* ModifyPlacesView::start() {
        int menuSelection;

        cout << endl << "Modifying place: " << rootPlace->getName() << endl;

        cout << "Edit\nName\t\t\t1\nLongitude\t\t2\nLatitude\t\t3\n\n  > ";
        cin >> menuSelection;

        if (menuSelection == 1) {
            cout << "New Name: ";
            string newString;
            cin >> newString;
            rootPlace->setName(newString);
            
        } else if (menuSelection == 2) {
            cout << "New Longitude: ";
            float newFloat;
            cin >> newFloat;
            rootPlace->setLongitude(newFloat);
            
        } else if (menuSelection == 3) {
            cout << "New Latitude: ";
            float newFloat;
            cin >> newFloat;
            rootPlace->setLatitude(newFloat);
            
        } else {
            cout << "Bad selection. Returning to menu."<<endl;
            
        }

        return this;
    }
