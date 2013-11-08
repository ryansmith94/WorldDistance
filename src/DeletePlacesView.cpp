#ifndef DeletePlacesView_H
#define DeletePlacesView_H
#include <iostream>
#include "View.cpp"
using namespace std;

class DeletePlacesView: public View {
public:
    DeletePlacesView(Place* place) : View(place) {}
    DeletePlacesView* start() {
        cout << endl << "Are you sure you want to delete " << rootPlace->getName() << "?" << endl;
        cout << "Y/N   > ";
        string menuSelection;
        cin >> menuSelection;
        cout << endl;

        if (menuSelection == "y" || menuSelection == "Y") {
            //old :: int childPos = rootPlace->getParent()->getIndexOfChild(rootPlace->getName());
            int childPos = rootPlace->getParent()->getIndexOfChild(rootPlace);
            cout<<"Child: "<<rootPlace->getName()<<"\t Parent: "<<rootPlace->getParent()->getName()<< "\t Child Index is "<<childPos<<endl<<endl;
            rootPlace->getParent()->removeChild(childPos);

        } else if (menuSelection == "n" || menuSelection == "N") {
            cout << "User abort. Returning to menu."<<endl;
        } else {
            cout << "Bad selection. Returning to menu."<<endl;
        }

        return this;
    }
};

#endif
