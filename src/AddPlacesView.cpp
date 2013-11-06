#ifndef AddPlacesView_H
#define AddPlacesView_H
#include <iostream>
#include "View.cpp"
using namespace std;

class AddPlacesView: public View {
public:
    AddPlacesView(Place* place) : View(place) {}
    AddPlacesView* start() {
        string sInput;
        string slInput1, slInput2;
        float lInput1, lInput2;

        cout << "Adding a child to " << rootPlace->getName() << "..." << endl;

        cout << endl << "New child name:\t ";
        getline(cin, sInput);

        cout << endl << "New child longitude:\t ";
        cin >> lInput1;
        cout << endl << "New child latitude:\t ";
        cin >> lInput2;

        rootPlace->addChild(new Place(sInput, lInput1, lInput2));
        return this;
    }
};

#endif
