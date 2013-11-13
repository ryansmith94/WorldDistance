CC=g++
CFLAGS=-c -Wall
LDFLAGS= -Wall
SRCDIR=./src/
BUILDDIR=./build/
TESTDIR=./test/
OBJECTS=$(BUILDDIR)HashTable.o $(BUILDDIR)Place.o $(BUILDDIR)OptionsViewPlaces.o $(BUILDDIR)View.o $(BUILDDIR)AddPlacesView.o $(BUILDDIR)DeletePlacesView.o $(BUILDDIR)DistanceView.o $(BUILDDIR)ModifyPlaceView.o  $(BUILDDIR)PlacesView.o $(BUILDDIR)DistanceApp.o

all: ./tmp/testMain

build: $(BUILDDIR)release

test: ./tmp/testMain
	cd $(TESTDIR) && ../tmp/testMain --output=color
	rm tmp/*.txt

run: 
	cd $(BUILDDIR) && ./release

clean:
	rm $(BUILDDIR)*.o build/release

OptionsViewPlaces.o: $(SRCDIR)OptionsViewPlaces.cpp $(SRCDIR)OptionsViewPlaces.h $(SRCDIR)Place.h $(SRCDIR)OptionsView.h $(SRCDIR)Node.h
	$(CC) $(CFLAGS) $(SRCDIR)OptionsViewPlaces.cpp -o $(BUILDDIR)OptionsViewPlaces.o

DistanceApp.o: $(SRCDIR)DistanceApp.cpp $(SRCDIR)DistanceApp.h $(SRCDIR)OptionsView.h $(SRCDIR)Place.h $(SRCDIR)DistanceView.h $(SRCDIR)PlacesView.h $(SRCDIR)AddPlacesView.h $(SRCDIR)ModifyPlaceView.h $(SRCDIR)DeletePlacesView.h $(SRCDIR)HashTable.h
	$(CC) $(CFLAGS) $(SRCDIR)DistanceApp.cpp -o $(BUILDDIR)DistanceApp.o

HashTable.o: $(SRCDIR)HashTable.cpp $(SRCDIR)HashTable.h $(SRCDIR)Place.h $(SRCDIR)Node.h 
	$(CC) $(CFLAGS) $(SRCDIR)HashTable.cpp -o $(BUILDDIR)HashTable.o

main.o: $(SRCDIR)main.cpp $(SRCDIR)main.h $(SRCDIR)DistanceApp.h
	$(CC) $(CFLAGS) $(SRCDIR)main.cpp -o $(BUILDDIR)main.o

Place.o: $(SRCDIR)Place.cpp $(SRCDIR)Place.h $(SRCDIR)LList.h $(SRCDIR)HashTable.h
	$(CC) $(CFLAGS) $(SRCDIR)Place.cpp -o $(BUILDDIR)Place.o

$(BUILDDIR)testmain.o: $(TESTDIR)main.cpp $(TESTDIR)DistanceApp.cpp $(TESTDIR)DistanceView.cpp $(TESTDIR)LList.cpp $(TESTDIR)Node.cpp $(TESTDIR)OptionsView.cpp $(TESTDIR)OptionsViewPlaces.cpp $(TESTDIR)Place.cpp $(TESTDIR)HashTable.cpp
	$(CC) $(CFLAGS) $(TESTDIR)main.cpp -o $@
		
$(BUILDDIR)%View.o: $(SRCDIR)%View.cpp $(SRCDIR)%View.h $(SRCDIR)Place.h $(SRCDIR)HashTable.h $(SRCDIR)View.h
	$(CC) $(CFLAGS) $(SRCDIR)$*View.cpp -o $(BUILDDIR)$*View.o
		
$(BUILDDIR)%.o: $(SRCDIR)%.cpp
	$(CC) $(CFLAGS) $(SRCDIR)$*.cpp -o $(BUILDDIR)$*.o

./tmp/testMain: $(OBJECTS) $(BUILDDIR)testmain.o
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(BUILDDIR)testmain.o

$(BUILDDIR)release: $(OBJECTS) $(BUILDDIR)main.o
	$(CC) $(LDFLAGS) -o $(BUILDDIR)release $(OBJECTS) $(BUILDDIR)main.o

.PHONY: all build test run clean