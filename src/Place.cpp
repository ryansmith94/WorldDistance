#include "Place.h"
#include "HashTable.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

void Place::setAddress(){
	// if hashTable is stored first remove this place from it
	if (hashTable!=NULL){hashTable->remove(this);}
	// start address with name of place
	string newAddress = name;
	// recurse through parents and add addresses till root place found
	if (parent!=NULL){
		newAddress = newAddress + ", " + parent->getAddress();
	}
	// assign address to place
	address = newAddress;
	// if hashTable is stored add place to hashTable with new address
	if (hashTable!=NULL){hashTable->add(this);}
	// recurse through children and update addresses
	for (int i=0;i<children.getSize();i++){
		children.getData(i)->setAddress();
	}
}

void Place::saveConstructor(ofstream *data,int depth){
	// write data of this place to data
	*data << depth << '\t' << name << '\t' << latitude << '\t' << longitude << LF;
	//recurse through children adding them to data
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
	// ensure correct address is stored and hashTable is correct
	setAddress();
	matches = new LList<Place>();
}

Place::~Place() {
	// if hashTable exists remove his item from it
	if (hashTable != NULL){hashTable->remove(this);}
	// clear all data from matches before deleting it
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
	// update name, address and hashTable with setAddress
	this->name = newName;
	setAddress();
	return this;
}

Place* Place::getParent() {
	return parent;
}

LList<Place>* Place::getMatchedChildren(string searchTerm){
	// clear matches ready for new search
	matches->clear();
	// if searchTerm is in name or both name is in searchTerm and searchTerm is in address
	// add to matches
	if (name.find(searchTerm)!=string::npos||(searchTerm.find(name)!=string::npos && address.find(searchTerm)!=string::npos)){
		matches->append(this);
	}
	//recurse through children adding results to matches
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
	// pass hashTable to children
	// child assigned this as parent
	// child added to children
	// child address is set and added to hashTable
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
	// hashTable is set
	// root added to hashTable
	hashTable = ht;
    ht->add(this);

	ifstream myfile(dataLocation.c_str());
	// check file is open
	if (myfile.is_open()){
		// store place adding to, place last added, lastDepth and depth to
		// traverse tree and add children to appropriate place
		// line used to read file data into
		// name, lat and lon used to create place
		Place* placeToAddTo = this;
		Place* lastPlaceAdded;
		int lastDepth = 0;
		int depth;
		string line;
		string name;
		double lat,lon;
		// while a line can be gotten from the file
		while(getline(myfile,line)){
			// create istringstream with line and read data from it
			istringstream iss(line);
			iss >> depth;
			iss.ignore();
			getline(iss, name, '\t');
			iss >> lat >> lon;
			//if depth increases this place is a child of the lastPlaceAdded
			if (depth > lastDepth){ placeToAddTo = lastPlaceAdded;}
			// if depth decreases place to add to is lastDepth-depth parents traversal
			else if (depth < lastDepth){
				for (int i = 0; i<(lastDepth-depth); i++){
					placeToAddTo = placeToAddTo->getParent();
				}
			}
			// create new place and add to tree
			lastPlaceAdded = new Place(name,lon, lat);
			placeToAddTo->addChild(lastPlaceAdded);
			lastDepth = depth;
		}
	}
	//close file
	myfile.close();
	return this;
}

int Place::getIndexOfChild(Place* searchPlace) {
	{
		int n;
		int len;
		// iterate through children and compare pointers to check places
		for(n = 0,len = children.getSize(); n<len; n++) {
			if (children.getData(n) == searchPlace) {
				return n;
			}
		}
	}
	return -1;
}


Place* Place::savePlace(string dataLocation){
	// set output file stream with dataLocation
	ofstream myfile(dataLocation.c_str());
	// check file is open
	if (myfile.is_open()){
		// for each child call saveConstructor to write data to file
		for (int i=0;i<children.getSize();i++){
			children.getData(i)->saveConstructor(&myfile,0);
		}
		// close file
		myfile.close();
	}
	return this;
}

string Place::getAddress(){
	return address;
}
