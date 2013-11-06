#ifndef TestNode_H
#define TestNode_H
#include "../src/Node.cpp"
#include "igloo/igloo_alt.h"
using namespace igloo;

Describe(Node_class){
	It(should_consruct_a_Node_with_data_passed){
		Assert::That((new Node<int>(new int(1))) != NULL, Equals(1));
	}
	It(should_consruct_a_Node_with_data_and_Node_passed){
		Assert::That((new Node<int>(new int(1),NULL)) != NULL, Equals(1));
	}
	It(should_expose_a_getNext_method){
		Assert::That(!!(&Node<int>::getNext), Equals(1));
	}
	It(should_expose_a_setNext_method){
		Assert::That(!!(&Node<int>::setNext), Equals(1));
	}
	It(should_expose_a_getData_method){
		Assert::That(!!(&Node<int>::getData), Equals(1));
	}
	It(should_expose_a_setData_method){
		Assert::That(!!(&Node<int>::setData), Equals(1));
	}
	Describe(getNext_method){
		It(should_return_the_next_Node){
			Node<int> *first = new Node<int>(new int(1));
			Node<int> *second = new Node<int>(new int(2));
			first->setNext(second);
			Assert::That(first->getNext(), Equals(second));
			delete first;
		}
	};
	Describe(setNext_method){
		It(should_set_the_next_Node){
			Node<int> *first = new Node<int>(new int(1));
			Node<int> *second = new Node<int>(new int(2));
			first->setNext(second);
			Assert::That(first->getNext(), Equals(second));
			delete first;
		}
	};
	Describe(getData_method){
		It(should_get_data_from_the_Node){
			int *data = new int(1);
			Node<int> *first = new Node<int>(data);
			Assert::That(first->getData(), Equals(data));
			delete first;
		}
	};
	Describe(setData_method){
		It(should_set_data_in_Node){
			int *data = new int(1);
			int *otherData = new int(2);
			Node<int> *first = new Node<int>(data);
			first->setData(otherData);
			Assert::That(first->getData(), Equals(otherData));
			delete data;
			delete first;
		}
	};

};

#endif
