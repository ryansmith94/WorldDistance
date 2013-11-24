#include "Place.h"
#include "HashTable.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

void Place::setAddress(){
	if (hashTable!=NULL){hashTable->remove(this);}
	string newAddress = name;
	if (parent!=NULL){
		newAddress = newAddress + ", " + parent->getAddress();
	}
	address = newAddress;
	if (hashTable!=NULL){hashTable->add(this);}
	for (int i=0;i<children.getSize();i++){
		children.getData(i)->setAddress();
	}
}

void Place::saveConstructor(ofstream *data,int depth){
	*data << depth << '\t' << name << '\t' << latitude << '\t' << longitude << LF;
	for (int i = 0; i<children.getSize();i++){
		children.getData(i)->saveConstructor(data,depth+1);
	}
}

Place::Place(string newName, float newLongitude, float newLatitude) {
	hashTable = NULL;
	name = newName;
	longitude = newLongitude;
	latitude = newLatitude;
	parent = NULL;
	setAddress();
	matches = new LList<Place>();
}

Place::~Place() {
	if (hashTable != NULL){hashTable->remove(this);}
	matches->clear();
	delete matches;
}

string Place::getName() {
	return name;
}

float Place::getLongitude() {
	return longitude;
}

float Place::getLatitude() {
	return latitude;
}

void Place::setLongitude(float newLongitude){
	longitude = newLongitude;
}

void Place::setLatitude(float newLatitude){
	latitude = newLatitude;
}

Place* Place::setName(string newName) {
	this->name = newName;
	setAddress();
	return this;
}

Place* Place::getParent() {
	return parent;
}

LList<Place>* Place::getMatchedChildren(string searchTerm){
	matches->clear();
	if (name.find(searchTerm)!=string::npos||(searchTerm.find(name)!=string::npos && address.find(searchTerm)!=string::npos)){
		matches->append(this);
	}
	for(int i=0;i<children.getSize();i++){
		matches->addAll(children.getData(i)->getMatchedChildren(searchTerm));
	}
	return matches;
}

Place* Place::getChild(int index) {
	return children.getData(index);
}

int Place::getNbrChildren() {
	return children.getSize();
}

Place* Place::addChild(Place* newPlace) {
	newPlace->hashTable = hashTable;
	newPlace->parent = this;
	children.append(newPlace);
	newPlace->setAddress();
	return this;
}

Place* Place::removeChild(int index){
	children.remove(index);
	return this;
}

Place* Place::loadPlace(string dataLocation, HashTable* ht){
	hashTable = ht;
    ht->add(this);

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
			lastPlaceAdded = new Place(name,lon, lat);
			placeToAddTo->addChild(lastPlaceAdded);
			lastDepth = depth;
		}
	}
	return this;
}

int Place::getIndexOfChild(Place* searchPlace) {
	{
		int n;
		int len;
		for(n = 0,len = children.getSize(); n<len; n++) {
			if (children.getData(n) == searchPlace) {
				return n;
			}
		}
	}
	return -1;
}


Place* Place::savePlace(string dataLocation){
	ofstream myfile(dataLocation.c_str());
	if (myfile.is_open()){
		for (int i=0;i<children.getSize();i++){
			children.getData(i)->saveConstructor(&myfile,0);
		}
		myfile.close();
	}

	return this;
}

string Place::getAddress(){
	return address;
}
