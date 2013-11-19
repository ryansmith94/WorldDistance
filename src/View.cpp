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
    /* Can I suggest an escape character of some kind? */
    /* while ((rejectEmpty == 1 && address == "") || address != "cancel"); */
    return address;
}
Place* View::getPlace(Place* rtPlace, string message) {
	Place* place = NULL;

	do {
        Node<Place>* matched = hashTable->get(getAddress(1, message));

        if (matched != NULL && (matched->getData() != rtPlace || matched->getNext() != NULL)) {
            OptionsViewPlaces view(matched);
            int selected = view.display(rtPlace)->getOption();

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
