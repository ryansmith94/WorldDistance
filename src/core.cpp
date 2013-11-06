#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#define LF (char)0x0A
using namespace std;

template <class T>
class Node{
	private:
		T *data;
		Node *next;
	public:
		Node(T*,Node*);
		Node(T*);
		Node();
		~Node();
		Node* getNext();
		void setNext(Node*);
		T* getData();
		void setData(T*);
};
template <class T>
class LList{
	private:
		int size;
		Node<T> *first;
	public:
		LList();
		~LList();
		int getSize();
		void append(T*);
		void insert(T*,int);
		void remove(int);
		T* getData(int);
		void addAll(LList<T>*);
		void clear();
};

template <class T>
Node<T>::Node(T *newData, Node *nextNode){
	data = newData;
	next = nextNode;
}
template <class T>
Node<T>::Node(T *newData){
	data = newData;
	next = NULL;
}
template <class T>
Node<T>::Node(){
	data = new T();
	next = NULL;
}
template <class T>
Node<T>::~Node(){
	delete next;
	delete data;
}
template <class T>
Node<T>* Node<T>::getNext(){
	return next;
}
template <class T>
void Node<T>::setNext(Node *nextNode){
	next = nextNode;
}
template <class T>
T* Node<T>::getData(){
	return data;
}
template <class T>
void Node<T>::setData(T *newData){
	data = newData;
}

template <class T>
LList<T>::LList(){
	size = 0;
	first = NULL;
}
template <class T>
LList<T>::~LList(){
	delete first;
}
template <class T>
int LList<T>::getSize(){
	return size;
}
template <class T>
void LList<T>::append(T *newData){
	if (first == NULL){
		first = new Node<T>(newData);
	}
	else{
		Node<T> *node = first;
		while(node->getNext() != NULL){
			node = node->getNext();
		}
		node->setNext(new Node<T>(newData));
	}
	size++;
}
template <class T>
void LList<T>::insert(T *newData,int index){
	if (!index){
		Node<T> *newNode = new Node<T>(newData,first);
		first = newNode;
	}
	else if(index == size){
		this->append(newData);
		size--;
	}
	else{
		Node<T> *node = first;
		for (int i=0;i<index-1;i++){
			node = node->getNext();
		}
		Node<T> *newNode = new Node<T>(newData,node->getNext());
		node->setNext(newNode);
	}
	size++;
}
template <class T>
void LList<T>::remove(int index){
	if (!index){
		Node<T> *temp = first;
		first = first->getNext();
		temp->setNext(NULL);
		delete temp;
	}
	else{
		Node<T> *node = first;
		for (int i=0;i<index-1;i++){
			node = node->getNext();
		}
		if (node->getNext()->getNext() == NULL){
			delete node->getNext();
			node->setNext(NULL);
		}
		else{
			Node<T> *temp = node->getNext();
			node->setNext(temp->getNext());
			temp->setNext(NULL);
			delete temp;
		}
	}
	size--;
}
template <class T>
T* LList<T>::getData(int index){
	Node<T> *node = first;
	for (int i=0;i<index;i++){
		node = node->getNext();
	}
	return node->getData();
}
template <class T>
void LList<T>::addAll(LList<T> *list){
	for (int i=0;i<list->getSize();i++){
		append(list->getData(i));
	}
}
template <class T>
void LList<T>::clear(){
	if (first!=NULL){
		Node<T> *temp = first;
		for (int i=0;i<size;i++){
			temp->setData(NULL);
			temp = temp->getNext();
		}
		delete first;
		first = NULL;
		size = 0;
	}
}

template <class OptionType>
class OptionsView {
        OptionType* options;
        int numberOfOptions;
    public:
        OptionsView(OptionType* opts, int len) {
            options = opts;
            numberOfOptions = len;
        }
        OptionsView* display() {
            for (int i = 0; i < numberOfOptions; i += 1) {
                cout << i + 1 << ". " << options[i] << LF;
            }
            cout << LF;
            return this;
        }
        int getOption() {
            int selected = -1;
            string input;

            do {
                cout << "Please select an option (1-" << numberOfOptions <<  "): ";
                getline(cin, input);
                stringstream myStream(input);
                myStream >> selected;
            } while (selected < 1 || selected > numberOfOptions);

            return (selected - 1);
        }
        OptionType* getOptions() {
            return options;
        }
};

class Place {
	private:
		string name;
		float longitude;
		float latitude;
		Place* parent;
		LList<Place> children;
		string address;
		LList<Place> *matches;

		void setAddress(){
			string newAddress = name;
			if (parent!=NULL){
				newAddress = parent->getAddress() + ", " + newAddress;
			}
			address = newAddress;
			for (int i=0;i<children.getSize();i++){
				children.getData(i)->setAddress();
			}
		}

		void saveConstructor(ofstream *data,int depth){
			*data << depth << '\t' << name << '\t' << longitude << '\t' << latitude << LF;
			for (int i = 0; i<children.getSize();i++){
				children.getData(i)->saveConstructor(data,depth+1);
			}
		}

	public:
		Place(string newName, float newLongitude, float newLatitude) {
			name = newName;
			longitude = newLongitude;
			latitude = newLatitude;
			parent = NULL;
			setAddress();
			matches = new LList<Place>();
		}

		~Place() {
			matches->clear();
			delete matches;
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
			this->name = newName;
			setAddress();
			return this;
		}

		Place* getParent() {
			return parent;
		}

		LList<Place>* getMatchedChildren(string searchTerm){
			matches->clear();
			if (name.find(searchTerm)!=string::npos||(searchTerm.find(name)!=string::npos && address.find(searchTerm)!=string::npos)){
				matches->append(this);
			}
			for(int i=0;i<children.getSize();i++){
				matches->addAll(children.getData(i)->getMatchedChildren(searchTerm));
			}
			return matches;
		}

		Place* getChild(int index) {
			return children.getData(index);
		}

		int getNbrChildren() {
			return children.getSize();
		}

		Place* addChild(Place* newPlace) {
			newPlace->parent = this;
			children.append(newPlace);
			children.getData(children.getSize()-1)->setAddress();
			return this;
		}

		Place* removeChild(int index){
			children.remove(index);
			return this;
		}

		Place* loadPlace(string dataLocation){
			ifstream myfile(dataLocation.c_str());
			if (myfile.is_open()){
				Place* placeToAddTo = this;
				Place* lastPlaceAdded;
				int lastDepth = 0;
				int depth;
				string line;
				string name;
				double lat,lon;
				while(getline(myfile,line)){
					istringstream iss(line);
					iss >> depth;
					iss.ignore();
					getline(iss, name, '\t');
					iss >> lat >> lon;
					if (depth > lastDepth){ placeToAddTo = lastPlaceAdded;}
					else if (depth < lastDepth){
						for (int i = 0; i<(lastDepth-depth); i++){
							placeToAddTo = placeToAddTo->getParent();
						}
					}
					lastPlaceAdded = new Place(name,lat,lon);
					placeToAddTo->addChild(lastPlaceAdded);
					lastDepth = depth;
				}
			}
			return this;
		}


		Place* savePlace(string dataLocation){
			ofstream myfile(dataLocation.c_str());
			if (myfile.is_open()){
				for (int i=0;i<children.getSize();i++){
					children.getData(i)->saveConstructor(&myfile,0);
				}
				myfile.close();
			}

			return this;
		}

		string getAddress(){
			return address;
		}


};

class View {
    protected:
        Place* rootPlace;
        string getAddress(int rejectEmpty = 0) {
            string address;
            do {
                cout << "Please enter an address: ";
                cin.clear();
                cin.ignore();
                getline(cin, address);
            } while (rejectEmpty == 1 && address == "");
            return address;
        }
        Place* getPlace() {
        	Place* place = NULL;

        	do {
        		LList<Place>* matched = rootPlace->getMatchedChildren(getAddress(1));
        		int size = matched->getSize();

        		if (size == 1) {
        			place = matched->getData(0);
        		} else if (size > 1) {
        			int selected = -1;
                    string input;

        			// Output the addresses of the matched places like an options view.
        			for (int i = 0; i < size; i += 1) {
        				cout << i + 1 << ". " << matched->getData(i)->getAddress() << LF;
        			}

        			// Get a chosen place.
        			do {
        			    cout << "Please select an option (1-" << size <<  "): ";
                        getline(cin, input);
                        stringstream myStream(input);
                        myStream >> selected;
        			} while (selected < 1 || selected > size);

        			place = matched->getData(selected - 1);
        		}
        	} while (place == NULL);

        	return place;
        }
    public:
        View(Place* place) {
            rootPlace = place;
        }
        virtual View* start() =0;
};

class DistanceView: public View {
        double calculateDistance(Place* from, Place* to) {
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
    public:
        DistanceView(Place* place) : View(place) {}
        DistanceView* start() {
            Place* place1;
            Place* place2;
            place1 = getPlace();
            place2 = getPlace();
            cout << calculateDistance(place1, place2) << LF;
            return this;
        }
};

class PlacesView: public View {
    public:
        PlacesView(Place* place) : View(place) {}
        PlacesView* start() {
            return this;
        }
};

class AddPlacesView: public View {
    public:
        AddPlacesView(Place* place) : View(place) {}
        AddPlacesView* start() {
            return this;
        }
};

class ModifyPlacesView: public View {
    public:
        ModifyPlacesView(Place* place) : View(place) {}
        ModifyPlacesView* start() {
            return this;
        }
};

class DeletePlacesView: public View {
    public:
        DeletePlacesView(Place* place) : View(place) {}
        DeletePlacesView* start() {
            return this;
        }
};

class DistanceApp {
        Place rootPlace;
        string dataLocation;
    public:
        DistanceApp() : rootPlace("Earth", 0.0, 0.0) {
            dataLocation = "data.txt";
            rootPlace.loadPlace(dataLocation);
        }
        DistanceApp* start() {
            string opts[6] = {"Distance", "Places", "Add place", "Modify place", "Delete place", "Quit"};
            OptionsView<string> optionsView(opts, 6);
            DistanceView distanceView(&rootPlace);
            PlacesView placesView(&rootPlace);
            AddPlacesView addPlacesView(&rootPlace);
            ModifyPlacesView modifyPlacesView(&rootPlace);
            DeletePlacesView deletePlacesView(&rootPlace);
            int selected;

            do {
                selected = optionsView.display()->getOption();

                if (selected == 0) {
                    distanceView.start();
                } else if (selected == 1) {
                    placesView.start();
                } else if (selected == 2) {
                    addPlacesView.start();
                } else if (selected == 3) {
                    modifyPlacesView.start();
                } else if (selected == 4) {
                    deletePlacesView.start();
                }
            } while (selected != 5);

            return this;
        }
};
