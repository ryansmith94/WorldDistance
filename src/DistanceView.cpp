#include "DistanceView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

double DistanceView::calculateDistance(Place* from, Place* to) {
    // Using the haversine forumla.
    double radius = 6371;
    double lat1 = from->getLatitude();
    double lat2 = to->getLatitude();
    double dLat = (lat2 - lat1) * (M_PI / 180);
    double dLon = (to->getLongitude() - from->getLongitude()) * (M_PI / 180);
    double a;

    lat1 = lat1 * (M_PI / 180);
    lat2 = lat2 * (M_PI / 180);

    a = sin(dLat / 2) * sin(dLat / 2) + sin(dLon / 2) * sin(dLon / 2) * cos(lat1) * cos(lat2);

    return radius * (2 * atan2(sqrt(a), sqrt(1 - a)));
}
DistanceView::DistanceView(Place* place, HashTable* hTable) : View(place, hTable) {}
DistanceView* DistanceView::start() {
    Place* place1;
    Place* place2;
    place1 = getPlace(rootPlace);
    place2 = getPlace(rootPlace);
    cout << LF << "\tThe distance is " << calculateDistance(place1, place2) << "km" << LF;
    return this;
}
