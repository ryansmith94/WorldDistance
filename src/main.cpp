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
			delete[] options;
			delete numberOfOptions;
		}
		OptionsView* display() {
			for (int i = 0; i < numberOfOptions; i += 1) {
				cout << i + 1 << ". " << options[i] << endl;
			}
			cout << endl;
			return this;
		}
		OptionType getOption() {
			return options[0];
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

int main() {
	cout << "I work... for now >;)" << endl;

	// Demonstration of OptionsView
	cout << endl << "Just testing the OptionsView class ;)" << endl;
	string opts[] = {"Option 1", "Option 2", "Quit"};
	OptionsView<string>* o = new OptionsView<string>(opts, sizeof(opts) / sizeof(string));
	cout << o->display()->getOption() << endl; // Notice that you can chain calls `display()->getOption()`

	return 0;
}