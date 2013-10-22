#include <iostream>
#include <string>
using namespace std;

template <class T>
class LinkedList {
        private:
                T *data;
                LinkedList *next;
                
                T getData(){
                        return *data;
                }
                T* getDataRef(){
                        return data;
                }
                LinkedList* getNext(){
                        return next;
                }
        public:
                LinkedList(){
                        data = NULL;
                        next = NULL;
                }
                LinkedList (T nextData){
                        data = new T(nextData);
                        next = NULL;
                }
                LinkedList (T *nextData){
                        data = nextData;
                        next = NULL;
                }
                ~LinkedList(){
                        delete data;
                        delete next;
                }
                void append(T nextData){
                        if (data == NULL) data = new T(nextData);
                        else {
                                if (next == NULL) next = new LinkedList(nextData);
                                else next->append(nextData);
                        }                
                }
                void append(T *nextData){
                        if (data == NULL) data = nextData;
                        else{
                                if (next == NULL) next = new LinkedList(*nextData);
                                else next->append(*nextData);
                        }
                }
                int getLength(){
                        int result;
                        if (data == NULL) result = 0;
                        else result = 1;
                        if (next != NULL) result += next->getLength();
                        return result;
                }
                T getData(int index){
                        T result;
                        if (index) result = getNext()->getData(--index);
                        else result = *data;
                        return result;
                }
                T* getDataRef(int index){
                        T *result;
                        if (index) result = getNext()->getDataRef(--index);
                        else result = data;
                        return result;
                }
                void insert(T newData, int index){
                        if(index == 1 && next == NULL){
                                next = new LinkedList(newData);
                                next->next = NULL;
                        }
                        else if(index) getNext()->insert(newData,--index);
                        else{
                                LinkedList *newNext = new LinkedList(data);
                                newNext->next = next;
                                data = new T(newData);
                                next = newNext;
                        }
                }
                void insert(T *newData, int index){
                        if(index == 1 && next ==NULL){
                                next = new LinkedList(newData);
                                next->next = NULL;
                        }
                        else if(index) getNext()->insert(newData,--index);
                        else{
                                LinkedList *newNext = new LinkedList(data);
                                newNext->next = next;
                                data = newData;
                                next = newNext;
                        }
                                
                }
                void remove(int index){
                        //special case for end of list(remove last element)
                        if (index == 1 && next->next == NULL){
                                delete next;
                                next = NULL;
                        }
                        //recurse if not at element to remove
                        else if (index) getNext()->remove(--index);
                        //special case for first element is last element(cant remove first link)
                        else if (!index && next == NULL){
                                delete data;
                                data = NULL;
                        }
                        //normal case
                        else{
                                LinkedList *temp = next;
                                delete data;
                                data = temp->data;
                                temp->data = NULL;
                                next = temp->next;
                                temp->next = NULL;
                                delete temp;
                        }
                }
};


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
		LinkedList<Place>* children;
	public:
		Place(string newName, float newLongitude, float newLatitude, Place* newParent) {
			name = newName;
			longitude = newLongitude;
			latitude = newLatitude;
			parent = newParent;
			children = new LinkedList<Place>();
		}

		/* Super Parent constructor */
		Place(string newName, float newLongitude, float newLatitude) {
			name = newName;
			longitude = newLongitude;
			latitude = newLatitude;
			//parent = earth ?
			children = new LinkedList<Place>();
		}
		
		~Place() {

			delete children;
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
		
		Place* getChild(int index) {
			if (!getNbrChildren()) return NULL;
			else return children->getDataRef(index);
		}
		
		int getNbrChildren() {
			/* 	sizeof(array) / sizeof(one_element) = number of elements in array	*/
					
			//return ((int)(&children+1)-(int)children)/(sizeof(children[0]));
			return children->getLength();
		}
		
		void addChild(Place newPlace) {
			cout<<"appending newPlace..."<<endl;cin.get();
			children->append(newPlace);
			cout<<"done"<<endl;cin.get();
		}
		
		Place* removeChild(int index){
			children->remove(index);
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
		PlacesView(Place* newPlace) {
			place = newPlace;
		}
		~PlacesView() {

		}
		PlacesView* start() {
			int r = place->getNbrChildren();

			cout << r << endl;
			
			for (int i=0; i < r; i++){
				Place* child = place->getChild(i);
				cout << "Name: " << child->getName() <<
					"\t| " << child->getLongitude() <<
					"\t| " << child->getLatitude() << endl;
			}
			
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
		ModifyPlacesView(Place* newPlace) {

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



/* Only a temp main */
int main() {
	Place *Austria = 	new Place("Austria",	14.301758,48.283787);
	
	Place *Vienna = 	new Place("Vienna",	16.400146,48.210627,Austria);
	Place *Linz = 		new Place("Linz",		14.312744,48.327633,Austria);
	Place *Salzburg = 	new Place("Salzburg",	13.047256,47.808221,Austria);

	// addChild doesnt do anything yet!
	cout<<"Now on Vienna..."<<endl;cin.get();
	Austria->addChild(*Vienna);
	cout<<"Now on Linz..."<<endl;cin.get();
	Austria->addChild(*Linz);
	Austria->addChild(*Salzburg);

	PlacesView con = PlacesView(Austria);

	con.start();
	
	return 0;
}
