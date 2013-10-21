#include <iostream>
#include <string>
using namespace std;

template <class OptionType>
class OptionsView {
		OptionType *options;
		int numberOfOptions;
	public:
		OptionsView (OptionType *opts, int len = 0) {
			options = opts;
			numberOfOptions = len;
		}
		~OptionsView () {

		}
		OptionsView* display() {
			for (int i = 0; i < numberOfOptions; i += 1) {
				cout << i + 1 << ". " << options[i] << endl;
			}
			cout << endl;
			return this;
		}
		OptionType getOption() {
			int selected = -1;

			do {
				cout << "Please select an option (1-" << numberOfOptions <<  "): ";
				cin >> selected;
			} while (selected < 1 || selected > numberOfOptions);

			return options[selected - 1];
		}
		OptionType* getOptions() {
			return options;
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
		Place* getChildren(){
			return this;
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
		Place* removeChild(int index){
			return this;
		}
		Place* loadPlace(string dataLocation){
			return this;
		}
		Place* savePlace(string datalocation){
			return this;
		}

};

class DistanceApp {
		Place* place;
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
		Place* place;
	public:
		DistanceView(Place* place) {

		}
		~DistanceView() {

		}
		DistanceView* start() {
			return this;
		}
};

class PlacesView {
		Place* place;
	public:
		PlacesView(Place* place) {

		}
		~PlacesView() {

		}
		PlacesView* start() {
			return this;
		}
};

class AddPlacesView {
		Place* place;
	public:
		AddPlacesView(Place* place) {

		}
		~AddPlacesView() {

		}
		AddPlacesView* start() {
			return this;
		}
};

class ModifyPlacesView {
		Place* places;
	public:
		ModifyPlacesView(Place* place) {

		}
		~ModifyPlacesView() {

		}
		ModifyPlacesView* start() {
			return this;
		}
};

class DeletePlacesView {
		Place* place;
	public:
		DeletePlacesView(Place* place) {

		}
		~DeletePlacesView() {

		}
		DeletePlacesView* start() {
			return this;
		}
};