#include <iostream>
#include <string>
using namespace std;

template <class OptionType>
class OptionsView {
		OptionType options[];
	public:
		OptionsView (OptionType options[]) {

		}
		~OptionsView () {

		}
		OptionsView display() {

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
		Place(string newName, float newLongitude, float newLatitude, Place* newParent) {

		}
		~Place() {

		}
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
			return this;
		}
		Place* getParent() {
			return parent;
		}
		Place* getChild() {
			return new Place("", 0.0, 0.0, this);
		}
		int getNbrChildren() {
			return 0;
		}
		Place* addChild(Place newPlace) {
			return this;
		}
};

class PlacesController {
		Place places[];
	public:
		PlacesController() {

		}
		~PlacesController() {

		}
		Place* getPlaces(string name, Place parent) {
			return 0;
		}
		PlacesController* addPlace(Place newPlace) {
			return this;
		}
		PlacesController* deletePlace(Place newPlace) {
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
		DistanceApp() {

		}
		~DistanceApp() {

		}
		DistanceApp* start() {
			return this;
		}
};

class DistanceView {
		PlacesController* places;
	public:
		DistanceView(PlacesController* places) {

		}
		~DistanceView() {

		}
		DistanceView* start() {
			return this;
		}
};

class PlacesView {
		PlacesController* places;
	public:
		PlacesView(PlacesController* places) {

		}
		~PlacesView() {

		}
		PlacesView* start() {
			return this;
		}
};

class AddPlacesView {
		PlacesController* places;
	public:
		AddPlacesView(PlacesController* places) {

		}
		~AddPlacesView() {
			
		}
		AddPlacesView* start() {
			return this;
		}
};

class ModifyPlacesView {
		PlacesController* places;
	public:
		ModifyPlacesView(PlacesController* places) {

		}
		~ModifyPlacesView() {
			
		}
		ModifyPlacesView* start() {
			return this;
		}
};

class DeletePlacesView {
		PlacesController* places;
	public:
		DeletePlacesView(PlacesController* places) {

		}
		~DeletePlacesView() {
			
		}
		DeletePlacesView* start() {
			return this;
		}
};

int main() {
	cout << "I work... for now >;)" << endl;
	return 0;
}