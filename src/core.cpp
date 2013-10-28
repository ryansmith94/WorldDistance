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

template <class OptionType>
class OptionsView {
        OptionType *options;
        int numberOfOptions;
    public:
        OptionsView (OptionType *opts, int len = 0) {
            options = opts;
            numberOfOptions = len;
        }
        ~OptionsView () {

        }
        OptionsView* display() {
            for (int i = 0; i < numberOfOptions; i += 1) {
                cout << i + 1 << ". " << options[i] << endl;
            }
            cout << endl;
            return this;
        }
        OptionType getOption() {
            int selected = -1;

            do {
                cout << "Please select an option (1-" << numberOfOptions <<  "): ";
                cin >> selected;
            } while (selected < 1 || selected > numberOfOptions);

            return options[selected - 1];
        }
        OptionType* getOptions() {
            return options;
        }
};

class Place {
        string name;
        float longitude;
        float latitude;
        Place* parent;
        Place* children[50];    /* Should we place a limit on this? */
        int nbrChildren;
    public:
        Place(string newName, float newLongitude, float newLatitude, Place* newParent) {
            name = newName;
            longitude = newLongitude;
            latitude = newLatitude;
            parent = newParent;
            for (int i=0;i<50; i++){
                children[i] = NULL;
            }
            nbrChildren = 0;
        }
        
        ~Place() {
        }
        
        string getName() {
            return name;
        }
        
        float getLongitude() {
            return longitude;
        }
        
        float getLatitude() {
            return latitude;
        }
        
        Place* setName(string newName) {
            this->name = newName;
            return this;
        }
        
        Place* getParent() {
            return parent;
        }
        
        Place* getChildren(string searchTerm){
            return this;
        }
        
        Place* getChild(int index) {
            return children[index];
        }
        
        int getNbrChildren() {
            return nbrChildren;
        }
        
        Place* addChild(Place* newPlace) {
            children[nbrChildren] = newPlace;
            nbrChildren++;
            return this;
        }
        
        Place* removeChild(int index){
            delete children[index];
            for (int i=index;i<nbrChildren;i++){
                children[index] = children[index+1];
            }
            children[--nbrChildren] = NULL;
            return this;
        }
        
        Place* loadPlace(string dataLocation){
            return this;
        }
        
        Place* savePlace(string datalocation){
            return this;
        }

};

class View {
    protected:
        Place* rootPlace;
        string getAddress(int rejectEmpty = 0) {
            string address;
            do {
                cout << "Please enter an address: ";
                cin >> address;
            } while (rejectEmpty == 1 && address == "");
            return address;
        }
    public:
        View(Place* place) {
            rootPlace = place;
        }
        virtual View* start() =0;
};

class DistanceView: public View {
    public:
        DistanceView(Place* place) : View(place) {}
        DistanceView* start() {
            string address1;
            string address2;
            address1 = getAddress(1);
            address2 = getAddress(1);
            // Calculate distance.
            return this;
        }
};

class PlacesView: public View {
    public:
        PlacesView(Place* place) : View(place) {}
        PlacesView* start() {
            return this;
        }
};

class AddPlacesView: public View {
    public:
        AddPlacesView(Place* place) : View(place) {}
        AddPlacesView* start() {
            return this;
        }
};

class ModifyPlacesView: public View {
    public:
        ModifyPlacesView(Place* place) : View(place) {}
        ModifyPlacesView* start() {
            return this;
        }
};

class DeletePlacesView: public View {
    public:
        DeletePlacesView(Place* place) : View(place) {}
        DeletePlacesView* start() {
            return this;
        }
};

class DistanceApp {
        Place* rootPlace;
        string dataLocation;
    public:
        DistanceApp() {
            dataLocation = "data.txt";
            rootPlace = new Place("Earth", 0.0, 0.0, NULL);
        }
        DistanceApp* start() {
            string opts[6] = {"Distance", "Places", "Add place", "Modify place", "Delete place", "Quit"};
            OptionsView<string> optionsView(opts, 6);
            DistanceView distanceView(rootPlace);
            PlacesView placesView(rootPlace);
            AddPlacesView addPlacesView(rootPlace);
            ModifyPlacesView modifyPlacesView(rootPlace);
            DeletePlacesView deletePlacesView(rootPlace);
            string selected;

            do {
                selected = optionsView.display()->getOption();

                if (selected == opts[0]) {
                    distanceView.start();
                } else if (selected == opts[1]) {
                    placesView.start();
                } else if (selected == opts[2]) {
                    addPlacesView.start();
                } else if (selected == opts[3]) {
                    modifyPlacesView.start();
                } else if (selected == opts[4]) {
                    deletePlacesView.start();
                }
            } while (selected != "Quit");

            return this;
        }
};