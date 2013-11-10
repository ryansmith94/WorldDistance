#ifndef LList_CPP
#define LList_CPP
#include "LList.h"
#include "Node.h"
#include <cstddef>
using namespace std;

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

#endif
