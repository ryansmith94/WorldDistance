#include "DeletePlacesView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

DeletePlacesView::DeletePlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}
DeletePlacesView* DeletePlacesView::start() {
    cout << endl << "Are you sure you want to delete " << rootPlace->getName() << "?" << endl;
	cout << "Y/N   > ";
	string menuSelection;
	cin >> menuSelection;
	cout << endl;

	if (menuSelection == "y" || menuSelection == "Y") {
		//old :: int childPos = rootPlace->getParent()->getIndexOfChild(rootPlace->getName());
		int childPos = rootPlace->getParent()->getIndexOfChild(rootPlace->getName());
		cout<<"Child: "<<rootPlace->getName()<<"\t Parent: "<<rootPlace->getParent()->getName()<< "\t Child Index is "<<childPos<<endl<<endl;
		rootPlace->getParent()->removeChild(childPos);

	} else if (menuSelection == "n" || menuSelection == "N") {
		cout << "User abort. Returning to menu."<<endl;
	} else {
		cout << "Bad selection. Returning to menu."<<endl;
	}

	cin.clear();
	return this;
}
