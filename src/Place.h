#ifndef Place_H
#define Place_H
#include <fstream>
#include <string>
#include <sstream>
#include "LList.h"
using namespace std;

class HashTable;

/**
 * @author Oliver Parker, Ryan Smith
 */
class Place {
	private:
		string name;
		float longitude;
		float latitude;
		Place* parent;
		LList<Place> children;
		string address;
		LList<Place> *matches;
		HashTable* hashTable;

		/**
		 * Sets address of place and all children.  Uses the name
		 * of parent chain to determine the address of the place,
		 * and then cals set address on all children.
		 * @post address is set and address of all children is set
		 * @post if HashTable != NULL place is removed and added with new address
		 */
		void setAddress();
		
		/**
		 * helper method for save. Gets all data necessary for saving from this place
		 * and all children and sends to the output file stream.
		 * @pre data != NULL
		 */
		void saveConstructor(ofstream *data,int depth);
	public:
	
		/**
		 * place constructor taking name, Longitude and Latitude as parameters
		 * @post place is constructed with data passed saved
		 * @post children is set to an empty list
		 * @post parent == NULL
		 * @post setAddress is called
		 * @param newName name of place
		 * @param newLongitude longitude of place
		 * @param newLatitude latitude of place
		 */
		Place(string newName, float newLongitude, float newLatitude);
		
		/**
		 * place destructor
		 * @post if hashTable != NULL, place is removed from hashTable
		 * @post all associated data in place is destructed
		 */
		~Place();
		
		/**
		 * returns name of place
		 * @post name of place is returned
		 * @return name of place
		 */
		string getName();
		
		/**
		 * returns longitude of place
		 * @post longitude of place is returned
		 * @return longitude of place
		 */
		float getLongitude();
		
		/**
		 * returns latitude of place
		 * @post latitude of place is returned
		 * @return latitude of place
		 */
		float getLatitude();
		
		/**
		 * sets longitude of place
		 * @post longitude is set to number passed
		 * @param newLongitude longitude of place to set
		 */
		void setLongitude(float newLongitude);
		
		/**
		 * sets the latitude of a place
		 * @post latitude is set to number passed
		 * @param newLatitude latitude of place to set
		 */
		void setLatitude(float newLatitude);
		
		/**
		 * sets the name of place
		 * @post name of place is set to sting passed
		 * @param newName name of place to set
		 * @return this place
		 */
		Place* setName(string newName);
		
		/**
		 * returns parent of this place
		 * @post parent is returned
		 * @return parent of this place, NULL if parent is not set
		 */
		Place* getParent();
		
		/**
		 * returns list of children matching with names or addresses matching searchTerm
		 * @post LList of matching children is returned
		 * @depreciated HashTable provides faster search results use HashTable::get
		 * @param searchTerm name, or address of place to search for. Use empty string for all places
		 * @return LList containing all matches to searchTerm
		 */
		LList<Place>* getMatchedChildren(string searchTerm);
		
		/**
		 * returns child at given index
		 * @pre index < getNbrChildren
		 * @post child at given index is returned
		 * @param index index of child to get
		 * @return place at given index in children
		 */
		Place* getChild(int index);
		
		/**
		 * returns number of children
		 * @post number of children is returned
		 * @return number of children
		 */
		int getNbrChildren();
		
		/**
		 * adds child to list of children
		 * @pre newPlace != NULL
		 * @post newPlace is added to list of children
		 * @param newPlace place to be added to children
		 * @return this place
		 */
		Place* addChild(Place* newPlace);
		
		/**
		 * removes child at given index
		 * @pre index < getNbrChildren
		 * @post child at given index is removed from list
		 * @post child at given index is destructed
		 * @param index index of child to remove
		 * @return this place
		 */
		Place* removeChild(int index);
		
		/**
		 * loads information from a given sataLocation into the children
		 * of a place
		 * @pre datafile exists and contains correctly formatted data
		 * @post data from save file is loaded into place children
		 * @param dataLocation string containing location of file
		 * @param ht hashTable into which data is to be added
		 * @return this place
		 */
		Place* loadPlace(string dataLocation, HashTable* ht);
		
		/**
		 * returns index of given child or -1 if place is not a child.
		 * @post index of child is returned
		 * @param searchPlace place to return index of
		 * @return index of child or -1 if not a child
		 */
		int getIndexOfChild(Place* searchPlace);
		
		/**
		 * saves all data in place to file in dataLocation
		 * @pre dataLocation is a valid address to save to
		 * @post all data in place is saved to dataLocation
		 * @param dataLocation  file address to save data to
		 * @return this place
		 */
		Place* savePlace(string dataLocation);
		
		/**
		 * returns address of place
		 * @post address of place is returned
		 * @return address of place
		 */
		string getAddress();
};

#endif
