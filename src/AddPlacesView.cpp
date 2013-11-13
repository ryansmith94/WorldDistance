#ifndef AddPlacesView_H
#define AddPlacesView_H
#include <iostream>
#include "View.cpp"
using namespace std;

class AddPlacesView: public View {
private:
    float inputFloat(String out){
        float selected;
        string input;
        
        do {
            cout << "<\t" << out << ": ";
            getline(cin, input);
            stringstream myStream(input);
        } while (!(myStream >> selected));
        
        return selected;
    }
    
public:
    AddPlacesView(Place* place, HashTable* hTable) : View(place) {}
    AddPlacesView* start() {
        string sInput;
        float lInput1, lInput2;

        cout << "Adding a child to " << rootPlace->getName() << "..." << endl;

        cout << endl << "New child name:\t ";
        sInput = getAddress();

        lInput1 = inputFloat("New child longitude");
        lInput2 = inputFloat("New child latitude");

        Place* p = new Place(sInput, lInput1, lInput2);

        rootPlace->addChild(p);
        hTable->add(p);
        return this;
    }
};

#endif
