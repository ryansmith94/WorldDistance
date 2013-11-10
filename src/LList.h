#ifndef LList_H
#define LList_H
#include "Node.h"

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

#endif