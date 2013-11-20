#ifndef LList_H
#define LList_H
#include "Node.h"
#include <cstddef>
using namespace std;

template <class T>
class LList{
	private:
		int size;
		Node<T> *first;
		Node<T> *current;
		int currentNode;
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
LList<T>::LList(){
	size = 0;
	currentNode = 0;
	current = NULL;
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
		current = first;
		currentNode = 0;
	}
	else{
		while(current->getNext() != NULL){
			current = current->getNext();
			currentNode++;
		}
		current->setNext(new Node<T>(newData));
	}
	size++;
}
template <class T>
void LList<T>::insert(T *newData,int index){
	if (!index){
		Node<T> *newNode = new Node<T>(newData,first);
		first = newNode;
		current = first;
		currentNode = 0;
	}
	else if(index == size){
		this->append(newData);
		size--;
	}
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
	size++;
}
template <class T>
void LList<T>::remove(int index){
	if (!index){
		current = first;
		first = first->getNext();
		current->setNext(NULL);
		delete current;
		current = first;
		currentNode = 0;
	}
	else{
		if (currentNode > index-1){
			currentNode = 0;
			current = first;
		}
		while (currentNode < index-1){
			current = current->getNext();
			currentNode++;
		}
		if (current->getNext()->getNext() == NULL){
			delete current->getNext();
			current->setNext(NULL);
		}
		else{
			Node<T> *temp = current->getNext();
			current->setNext(temp->getNext());
			temp->setNext(NULL);
			delete temp;
		}
	}
	size--;
}
template <class T>
T* LList<T>::getData(int index){
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
	for (int i=0;i<list->getSize();i++){
		append(list->getData(i));
	}
}
template <class T>
void LList<T>::clear(){
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