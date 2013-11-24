#include "DistanceView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

double DistanceView::calculateDistance(Place* from, Place* to) {
    // Radius of the Earth.
    double radius = 6371;

    // Get the latitude of the places.
    double lat1 = from->getLatitude();
    double lat2 = to->getLatitude();

    // Difference between the latitudes in radians.
    double dLat = (lat2 - lat1) * (M_PI / 180);

    // Difference between the longitudes in radians
    double dLon = (to->getLongitude() - from->getLongitude()) * (M_PI / 180);

    // Convert latitiudes to radians.
    lat1 = lat1 * (M_PI / 180);
    lat2 = lat2 * (M_PI / 180);

    // Calculate the distance using the haversine formula.
    double a = sin(dLat / 2) * sin(dLat / 2) + sin(dLon / 2) * sin(dLon / 2) * cos(lat1) * cos(lat2);
    return radius * (2 * atan2(sqrt(a), sqrt(1 - a)));
}
DistanceView::DistanceView(Place* place, HashTable* hTable) : View(place, hTable) {}
DistanceView* DistanceView::start() {
    // Get the places.
    Place* place1 = getPlace(rootPlace);
    Place* place2 = getPlace(rootPlace);

    // Output the distance between the two places.
    cout << LF << "\tThe distance is " << calculateDistance(place1, place2) << "km" << LF;

    return this;
}
