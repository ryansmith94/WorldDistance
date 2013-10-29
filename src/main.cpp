#include "core.cpp"
using namespace std;

int main() {
	Place * Austria = new Place("Austria",14.618683,47.391144,NULL);

	Place * Linz = new Place("Linz",14.290466,48.269712,Austria);
	Place * Graz = new Place("Graz",15.444031,47.071291,Austria);
	Place * Vienna = new Place("Vienna",16.377182,48.203397,Austria);
	Place * Salzburg = new Place("Salzburg",13.059311,47.806468,Austria);

	Austria->addChild(Linz);
	Austria->addChild(Graz);
	Austria->addChild(Vienna);
	Austria->addChild(Salzburg);

	PlacesView *con = new PlacesView(Austria);
	con->start();

	/* Ollies Test Code

	Place *p = new Place("test",0.0,0.0,NULL);
	cout<<p->getName()<<endl;
	Place *t = new Place("test2",0.0,0.0,NULL);
	Place *u = new Place("test3",0.0,0.0,NULL);
	Place *v = new Place("test4",0.0,0.0,NULL);
	Place *w = new Place("test5",0.0,0.0,NULL);
	Place *x = new Place("test6",0.0,0.0,NULL);

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
	
	delete p;
	*/

	cin.get();
	return 0;
}