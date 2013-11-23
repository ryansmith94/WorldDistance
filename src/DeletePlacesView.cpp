#include "DeletePlacesView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

/**
 * @author Harley Bristow
 */

/**Constructor takes a pointer to a Place Object
 * Said Place Object is to be removed from its Parent's children and the program's memory
 *
 * @see	DeletePlacesView::start()
 */
DeletePlacesView::DeletePlacesView(Place* place, HashTable* hTable) : View(place, hTable) {}

/**Operational method for the class;
 * Called to prompt the user to confirm the deletion of the construcor's param Object
 *
 * @return	Returns a pointer to itself (this)
 */
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
