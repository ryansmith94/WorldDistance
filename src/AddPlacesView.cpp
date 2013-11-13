#include "AddPlacesView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

float AddPlacesView::inputFloat(String out){
    float selected;
    string input;
    
    do {
        cout << "<\t" << out << ": ";
        getline(cin, input);
        stringstream myStream(input);
    } while (!(myStream >> selected));
    
    return selected;
}
AddPlacesView::AddPlacesView(Place* place, HashTable* hTable) : View(place, hTable){}
AddPlacesView* AddPlacesView::start() {
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
