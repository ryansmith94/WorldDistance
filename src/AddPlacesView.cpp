#include "AddPlacesView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

float AddPlacesView::inputFloat(string out){
    float selected;
    string input;
    stringstream* myStream;

    do {
        cout << "<\t" << out << ": ";
        getline(cin, input);
        myStream = new stringstream(input);
    } while (!((*myStream) >> selected));

    return selected;
}
AddPlacesView::AddPlacesView(Place* place, HashTable* hashTable) : View(place, hashTable){}
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
    hashTable->add(p);
    return this;
}
