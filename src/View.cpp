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
Place* View::getPlace(string message) {
	Place* place = NULL;

	do {
		int includeEarth = 0;
		if (message == "includeEarth"){includeEarth = 1; message = "";}
		Node<Place>* matched = NULL;
		string address = getAddress(1, message);
		if (includeEarth == 1 && rootPlace->getName().find(address)!=string::npos){
			matched = new Node<Place>(rootPlace);
		}
		if(matched == NULL){
			matched = hashTable->get(address);
		}
		else{
			matched->setNext(hashTable->get(address));
		}

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