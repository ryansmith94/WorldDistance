#include "View.h"
using namespace std;

string View::getAddress(int rejectEmpty, string message) {
    string address;
    do {
        if (message == "") {
            cout << "<\tPlease enter an address: ";
        } else {
            cout << "<\t" << message << ": ";
        }
        getline(cin, address);
    } while (rejectEmpty == 1 && address == "");
    return address;
}
Place* View::getPlace(Place* rtPlace, string message) {
	Place* place = NULL;

	do {
        LList<Place>* matched = hashTable->get(getAddress(1, message), rtPlace);

        if (matched->getSize() != 0) {
            OptionsViewPlaces view(matched);
            int selected = view.display()->getOption();
            place = matched->getData(selected);
        }
	} while (place == NULL);

	return place;
}
View::View(Place* place, HashTable* hTable) {
    rootPlace = place;
    hashTable = hTable;
}
