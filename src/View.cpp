#include "View.h"
using namespace std;

string View::getAddress(int rejectEmpty) {
    string address;
    do {
        cout << "<\tPlease enter an address: ";
        getline(cin, address);
    } while (rejectEmpty == 1 && address == "");
    return address;
}
Place* View::getPlace() {
	Place* place = NULL;

	do {
		Node<Place>* matched = hashTable->get(getAddress(1));

        if (matched != NULL) {
            OptionsViewPlaces view(matched);
            int selected = view.display()->getOption();

            for (int i = 0; i < selected; i += 1) {
                matched = matched->getNext();
            }

            place = matched->getData();
        }
	} while (place == NULL);

	return place;
}
View::View(Place* place, HashTable* hTable) {
    rootPlace = place;
    hashTable = hTable;
}