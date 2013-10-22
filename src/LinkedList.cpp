#include <iostream>
#include <string>
using namespace std;

template <class T>
class LinkedList {
	private:
		T *data;
		LinkedList *next;
		
		T getData(){
			return *data;
		}
		T* getDataRef(){
			return data;
		}
		LinkedList* getNext(){
			return next;
		}
	public:
		LinkedList(){
			data = NULL;
			next = NULL;
		}
		LinkedList (T nextData){
			data = new T(nextData);
			next = NULL;
		}
		LinkedList (T *nextData){
			data = nextData;
			next = NULL;
		}
		~LinkedList(){
			delete data;
			delete next;
		}
		void append(T nextData){
			if (data == NULL) data = new T(nextData);
			else {
				if (next == NULL) next = new LinkedList(nextData);
				else next->append(nextData);
			}		
		}
		void append(T *nextData){
			if (data == NULL) data = nextData;
			else{
				if (next == NULL) next = new LinkedList(*nextData);
				else next->append(*nextData);
			}
		}
		int getLength(){
			int result;
			if (data == NULL) result = 0;
			else result = 1;
			if (next != NULL) result += next->getLength();
			return result;
		}
		T getData(int index){
			T result;
			if (index) result = getNext()->getData(--index);
			else result = *data;
			return result;
		}
		T* getDataRef(int index){
			T *result;
			if (index) result = getNext()->getDataRef(--index);
			else result = data;
			return result;
		}
		void insert(T newData, int index){
			if(index == 1 && next == NULL){
				next = new LinkedList(newData);
				next->next = NULL;
			}
			else if(index) getNext()->insert(newData,--index);
			else{
				LinkedList *newNext = new LinkedList(data);
				newNext->next = next;
				data = new T(newData);
				next = newNext;
			}
		}
		void insert(T *newData, int index){
			if(index == 1 && next ==NULL){
				next = new LinkedList(newData);
				next->next = NULL;
			}
			else if(index) getNext()->insert(newData,--index);
			else{
				LinkedList *newNext = new LinkedList(data);
				newNext->next = next;
				data = newData;
				next = newNext;
			}
				
		}
		void remove(int index){
			//special case for end of list(remove last element)
			if (index == 1 && next->next == NULL){
				delete next;
				next = NULL;
			}
			//recurse if not at element to remove
			else if (index) getNext()->remove(--index);
			//special case for first element is last element(cant remove first link)
			else if (!index && next == NULL){
				delete data;
				data = NULL;
			}
			//normal case
			else{
				LinkedList *temp = next;
				delete data;
				data = temp->data;
				temp->data = NULL;
				next = temp->next;
				temp->next = NULL;
				delete temp;
			}
		}
};

int main(){
	LinkedList<string> *myList = new LinkedList<string>();
	myList->append("Hello");
	myList->append("World");
	myList->append("Cheese");
	myList->remove(0);
	myList->remove(0);
	myList->remove(0);
	for(int i = 0; i<myList->getLength();i++){
		cout<<myList->getData(i)<<endl;
	}
	myList->append("dog");
	myList->append("cat");
	myList->insert("ape",2);
	string *myString = new string("chicken");
	myList->insert(myString,3);
	*myString = "donkey";
	for(int i = 0; i<myList->getLength();i++){
		cout<<myList->getData(i)<<endl;
	}
	return 1;
}