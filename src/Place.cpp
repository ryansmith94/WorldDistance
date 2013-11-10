#ifndef Place_H
#define Place_H
#include <fstream>
#include <sstream>
#include <string>
#include "LList.cpp"
#include "HashTable.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

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
				newAddress = newAddress + ", " + parent->getAddress();
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

		Place* loadPlace(string dataLocation, HashTable* ht){
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
                    ht->add(lastPlaceAdded);
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

#endif
