#include <iostream>
#include <string>
using namespace std;

template <class OptionType>
class Options {
		OptionType options[];
	public:
		Options display() {

		}
		OptionType getOption() {

		}
		OptionType* getOptions() {

		}
};

class Place {
		string name;
		float longitude;
		float latitude;
		Place* parent;
		Place* children[];
	public:
		string getName() {
			return 0;
		}
		float getLongitude() {
			return 0;
		}
		float getLatitude() {
			return 0;
		}
		Place* setName(string newName) {
			return new Place();
		}
		Place* getParent() {
			return new Place();
		}
		Place* getChild() {
			return new Place();
		}
		int getNbrChildren() {
			return 0;
		}
		Place* addChild(Place newPlace) {
			return new Place();
		}
};

class PlacesController {
		Place places[];
	public:
		Place* getPlaces(string name, Place parent) {
			return 0;
		}
		PlacesController* addPlace(Place newPlace) {
			return this;
		}
		PlacesController* loadPlaces(string dataLocation) {
			return this;
		}
		PlacesController* savePlaces(string dataLocation) {
			return this;
		}
};

class DistanceApp {
		PlacesController* places;
	public:
		DistanceApp* start() {
			return this;
		}
};

class DistanceView {
		PlacesController* places;
	public:
		DistanceView* start() {
			return this;
		}
};

class PlacesView {
		PlacesController* places;
	public:
		PlacesView* start() {
			return this;
		}
};

class AddPlacesView {
		PlacesController* places;
	public:
		AddPlacesView* start() {
			return this;
		}
};

int main() {
	cout << "I work... for now >;)" << endl;
	return 0;
}