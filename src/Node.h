#ifndef Node_H
#define Node_H
#include <iostream>
#include <cstddef>
using namespace std;

template <class T>
class Node{
    private:
        T *data;
        Node *next;
    public:
		
		/**
		 * constructor for node taking newData and nextNode as parameters
		 * @pre newData != NULL
		 * @pre data is of same type as generic
		 * @post Node is constructed containing newData and next
		 */
        Node(T*,Node*);
		
		/**
		 * constructor for node taking newData as parameter
		 * @pre newData != NULL
		 * @pre data is of same type as generic
		 * @post Node is constructed containing newData and next is set to NULL
		 */
        Node(T*);
		
		/**
		 * constructor for node taking no parameters
		 * @post Node is constructed with data and next set to NULL
		 */
        Node();
		
		/**
		 * destructs Node and node connected to this node
		 * @post data is destructed
		 * @post next is destructed
		 */
        ~Node();
		
		/**
		 * returns next Node
		 * @post next Node is returned
		 * @return next Node
		 */
        Node* getNext();
		
		/**
		 * sets next Node to passed value
		 * @post next is set to nextNode
		 */
        void setNext(Node*);
		
		/**
		 * returns data stored in node
		 * @post data stored in node is returned
		 * @return data stored in node
		 */
        T* getData();
		
		/**
		 * sets data stored in node
		 * @pre data is of same type as generic
		 * @post newData is stored in node
		 * @post original data is not destructed!!
		 */
        void setData(T*);
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
    data = NULL;
    next = NULL;
}
template <class T>
Node<T>::~Node(){
	// all nodes in the forward chain will be destructed
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

#endif