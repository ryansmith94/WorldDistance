#include "DeletePlacesView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

DeletePlacesView::DeletePlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}
DeletePlacesView* DeletePlacesView::start() {
    string opts[2] = {"Yes", "No"};
    OptionsView<string> view(opts, 2);
    Place* place = getPlace(rootPlace);

    cout << "\tAre you sure you want to delete?" << LF;
    if (view.display()->getOption() == 0) {
        place->getParent()->removeChild(place->getParent()->getIndexOfChild(place));
        cout << "Place deleted" << LF;
    } else {
        cout << "User abort" << LF;
    }

	return this;
}
