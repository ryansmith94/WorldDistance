#include "core.cpp"
using namespace std;

int main() {
	Place *p = new Place("test",0.0,0.0);
	cout<<p->getName()<<endl;
	Place *t = new Place("test2",0.0,0.0);
	Place *u = new Place("test3",0.0,0.0);
	Place *v = new Place("test4",0.0,0.0);
	Place *w = new Place("test5",0.0,0.0);
	Place *x = new Place("test6",0.0,0.0);
	p->addChild(t);
	p->addChild(u);
	p->addChild(v);
	cout<<p->getNbrChildren()<<endl;
	cout << p->getChild(2)->addChild(w)->getNbrChildren()<<endl;
	p->getChild(2)->getChild(0)->addChild(x);
	cout << p->getChild(2)->getChild(0)->getChild(0)->getName()<<endl;
	cout << p->getChild(2)->getName()<<endl;
	p->removeChild(1);
	cout<<p->getNbrChildren()<<endl;
	cout<<p->getChild(1)->getChild(0)->getChild(0)->getAddress()<<endl;
	LList<Place> *result = p->getMatchedChildren("test");
	cout<< result->getSize()<<endl;
	for (int i=0;i<result->getSize();i++){
		cout << result->getData(i)->getName()<<endl;
	}
	result = p->getMatchedChildren("test");
	cout<< result->getSize()<<endl;
	for (int i=0;i<result->getSize();i++){
		cout << result->getData(i)->getName()<<endl;
	}
	result = p->getMatchedChildren("test");
	cout<< result->getSize()<<endl;
	for (int i=0;i<result->getSize();i++){
		cout << result->getData(i)->getName()<<endl;
	}
	result = p->getMatchedChildren("test");
	cout<< result->getSize()<<endl;
	for (int i=0;i<result->getSize();i++){
		cout << result->getData(i)->getName()<<endl;
	}
	result = p->getMatchedChildren("test");
	cout<< result->getSize()<<endl;
	for (int i=0;i<result->getSize();i++){
		cout << result->getData(i)->getName()<<endl;
	}
	Place *root = new Place("Earth",0.0,0.0);
	root->loadPlace("data.txt");
	cout << root->getNbrChildren()<< endl;
	cout << root->getChild(0)->getName()<<endl;
	cout << root->getChild(1)->getName()<<endl;
	cout << root->getChild(0)->getNbrChildren() << endl;
	cout << root->getChild(1)->getChild(0)->getChild(0)->getName() << endl;
	cout << root->getChild(1)->getChild(0)->getChild(0)->getNbrChildren() << endl;
	cout << root->getChild(1)->getChild(0)->getNbrChildren() << endl;
	cout << root->getChild(1)->getChild(0)->getName() << endl;
	LList<Place> *searchResults = root->getMatchedChildren("");
	for (int i = 0; i<searchResults->getSize();i++){
		cout<<searchResults->getData(i)->getAddress()<<endl;
	}
	root->savePlace("test2.txt");
	delete p;
	delete root;
	return 0;
}