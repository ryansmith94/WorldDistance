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
		Place* children[];	/* Should we place a limit on this?	*/
	public:
		Place(string newName, float newLongitude, float newLatitude, Place* newParent) {
			name = newName;
			longitude = newLongitude;
			latitude = newLatitude;
			parent = newParent;
		}
		
		~Place() {

		}
		
		string getName() {
			return name;
		}
		
		float getLongitude() {
			return longitude;
		}
		
		float getLatitude() {
			return latitude;
		}
		
		Place* setName(string newName) {
			/* name = newName	*/
			this->name = newName;
			return this;
		}
		
		Place* getParent() {
			return parent;
		}
		
		Place* getChildren(){
			/* Should this return an array/list? 		*/
			return this;
		}
		
		Place* getChild() {
			/* Is this the return for an empty list? 	*/
			return new Place("", 0.0, 0.0, this);
		}
		
		int getNbrChildren() {
			/* 	sizeof(array) / sizeof(one_element) = number of elements in array	*/
					
			return((int)(&children+1)-(int)children)/(sizeof(children[0]));
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
