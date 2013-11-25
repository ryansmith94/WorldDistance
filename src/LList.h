#ifndef LList_H
#define LList_H
#include "Node.h"
#include <cstddef>
using namespace std;

/**
 * @author Oliver Parker
 */
template <class T>
class LList{
	private:
		int size;
		Node<T> *first;
		Node<T> *current;
		int currentNode;
	public:
	
		/**
		 * Constructs a LList
		 * @post empty LList is constructed
		 */
		LList();
		
		/**
		 * Destructs the LList
		 * @post LList and all associated data and nodes is destructed
		 */
		~LList();
		
		/**
		 * Returns number of elements in LList
		 * @post size of LList is returned
		 * @return size of LList
		 */
		int getSize();
		
		/**
		 * Appends newData passed to the LList
		 * @pre newData passed is not NULL
		 * @post new node is added to LList containing newData
		 * @param newData data to be added to LList
		 */
		void append(T*);
		
		/**
		 * Inserts a new node containing data at index
		 * @pre index is <= size && index is >= 0
		 * @pre newData is not NULL
		 * @post new node containing newData is added to the LList at index
		 * @param newData data to be added to LList
		 * @param index index of LList at which data is to be added
		 */
		void insert(T*,int);
		
		/**
		 * Removes item at position index from LList
		 * @pre index is < size && index is >= 0
		 * @post node at index is removed
		 * @post size of LList is decremented
		 * @param index index of LList at which data is to be removed
		 */
		void remove(int);
		
		/**
		 * Gets data at given index
		 * @pre index is < size && index >= 0
		 * @post data at index is returned
		 * @param index index of data to be returned
		 * @return data at given index
		 */
		T* getData(int);
		
		/**
		 * copies and appends all elements of passed LList into this LList
		 * @pre list != NULL
		 * @pre list has same type as this LList
		 * @post all nodes in list are copied and appended to this LList
		 * @param list LList which is to be copied and appended to this LList
		 */
		void addAll(LList<T>*);
		
		/**
		 * removes all elements of LList without deleting the data
		 * @post list will have no data contained
		 * @post size == 0
		 * @post data will not be destructed
		 */
		void clear();
};

template <class T>
LList<T>::LList(){
	size = 0;
	// tracks floating pointer for optimised access
	currentNode = 0;
	// floating pointer for optimised access
	current = NULL;
	first = NULL;
}
template <class T>
LList<T>::~LList(){
	// will destruct list and all data within
	delete first;
}
template <class T>
int LList<T>::getSize(){
	return size;
}
template <class T>
void LList<T>::append(T *newData){
	// if first node is null start the list
	if (first == NULL){
		first = new Node<T>(newData);
		current = first;
		currentNode = 0;
	}
	// otherwise append to end of list
	else{
		while(current->getNext() != NULL){
			current = current->getNext();
			currentNode++;
		}
		current->setNext(new Node<T>(newData));
	}
	// in all cases increment size
	size++;
}
template <class T>
void LList<T>::insert(T *newData,int index){
	// if inserting at start of list replace first
	if (!index){
		Node<T> *newNode = new Node<T>(newData,first);
		first = newNode;
		current = first;
		currentNode = 0;
	}
	// if adding to end of list append
	// size must be decremented since it will be incremented in append also
	else if(index == size){
		this->append(newData);
		size--;
	}
	// otherwise insert at given position
	else{
		if (currentNode > index-1){
			currentNode = 0;
			current = first;
		}
		while (currentNode < index-1){
			current = current->getNext();
			currentNode++;
		}
		Node<T> *newNode = new Node<T>(newData,current->getNext());
		current->setNext(newNode);
	}
	// in all cases increment size
	size++;
}
template <class T>
void LList<T>::remove(int index){
	// if removing first element, first must be reassigned
	if (!index){
		current = first;
		first = first->getNext();
		current->setNext(NULL);
		delete current;
		current = first;
		currentNode = 0;
	}
	// otherwise remove element at given index
	else{
		if (currentNode > index-1){
			currentNode = 0;
			current = first;
		}
		while (currentNode < index-1){
			current = current->getNext();
			currentNode++;
		}
		// if removing last element no need to break links in list before deleting
		if (current->getNext()->getNext() == NULL){
			delete current->getNext();
			current->setNext(NULL);
		}
		// otherwise links must be broken to prevent items being destructed
		else{
			Node<T> *temp = current->getNext();
			current->setNext(temp->getNext());
			temp->setNext(NULL);
			delete temp;
		}
	}
	// in all cases decrement size
	size--;
}
template <class T>
T* LList<T>::getData(int index){
	// sets floating pointer to element to return and returns it
	if (index < 0) {
		return NULL;
	}
	if (currentNode > index){
		currentNode = 0;
		current = first;
	}
	while(currentNode < index){
		current = current->getNext();
		currentNode++;
	}
	return current->getData();
}
template <class T>
void LList<T>::addAll(LList<T> *list){
	// ensures all nodes of passed list are copied in case it gets destructed
	for (int i=0;i<list->getSize();i++){
		append(list->getData(i));
	}
}
template <class T>
void LList<T>::clear(){
	// if list != NULL sets all data to NULL then deletes first, sets size to 0 and first and current to NULL
	if (first!=NULL){
		current = first;
		for (int i=0;i<size;i++){
			current->setData(NULL);
			current = current->getNext();
		}
		delete first;
		first = NULL;
		current = NULL;
		size = 0;
		currentNode = 0;
	}
}

#endif