#ifndef Place_H
#define Place_H
#include <fstream>
#include <string>
#include <sstream>
#include "LList.h"
using namespace std;

class HashTable;

class Place {
	private:
		string name;
		float longitude;
		float latitude;
		Place* parent;
		LList<Place> children;
		string address;
		LList<Place> *matches;

		void setAddress();
		void saveConstructor(ofstream *data,int depth);
	public:
		Place(string newName, float newLongitude, float newLatitude);
		~Place();
		string getName();
		float getLongitude();
		float getLatitude();
		void setLongitude(float newLongitude);
		void setLatitude(float newLatitude);
		Place* setName(string newName);
		Place* getParent();
		LList<Place>* getMatchedChildren(string searchTerm);
		Place* getChild(int index);
		int getNbrChildren();
		Place* addChild(Place* newPlace);
		Place* removeChild(int index);
		Place* loadPlace(string dataLocation, HashTable* ht);
		int getIndexOfChild(string searchTerm);
		Place* savePlace(string dataLocation);
		string getAddress();
};

#endif
