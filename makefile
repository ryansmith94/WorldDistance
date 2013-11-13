CC=g++
CFLAGS=-c -Wall
LDFLAGS= -Wall
SRCDIR=./src/
BUILDDIR=./build/
TESTDIR=./test/
SOURCES=main.cpp hello.cpp factorial.cpp
OBJECTS=$(SOURCES:.cpp=.o)

AddPlacesView.o: $(SRCDIR)AddPlacesView.cpp $(SRCDIR)AddPlacesView.h $(SRCDIR)Place.h $(SRCDIR)HashTable.h $(SRCDIR)View.h
	$(CC) $(CFLAGS) $(SRCDIR)AddPlacesView.cpp -o $(BUILDDIR)AddPlacesView.o

DeletePlacesView.o: $(SRCDIR)DeletePlacesView.cpp $(SRCDIR)DeletePlacesView.h $(SRCDIR)Place.h $(SRCDIR)HashTable.h $(SRCDIR)View.h
	$(CC) $(CFLAGS) $(SRCDIR)DeletePlacesView.cpp -o $(BUILDDIR)DeletePlacesView.o

DistanceView.o: $(SRCDIR)DistanceView.cpp $(SRCDIR)DistanceView.h $(SRCDIR)Place.h $(SRCDIR)HashTable.h $(SRCDIR)View.h
	$(CC) $(CFLAGS) $(SRCDIR)DistanceView.cpp -o $(BUILDDIR)DistanceView.o

ModifyPlaceView.o: $(SRCDIR)ModifyPlaceView.cpp $(SRCDIR)ModifyPlaceView.h $(SRCDIR)Place.h $(SRCDIR)HashTable.h $(SRCDIR)View.h
	$(CC) $(CFLAGS) $(SRCDIR)ModifyPlaceView.cpp -o $(BUILDDIR)ModifyPlaceView.o

PlacesView.o: $(SRCDIR)PlacesView.cpp $(SRCDIR)PlacesView.h $(SRCDIR)Place.h $(SRCDIR)HashTable.h $(SRCDIR)View.h
	$(CC) $(CFLAGS) $(SRCDIR)PlacesView.cpp -o $(BUILDDIR)PlacesView.o

View.o: $(SRCDIR)View.cpp $(SRCDIR)View.h $(SRCDIR)Place.h $(SRCDIR)HashTable.h $(SRCDIR)OptionsViewPlaces.h
	$(CC) $(CFLAGS) $(SRCDIR)View.cpp -o $(BUILDDIR)View.o

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

testMain.o: $(TESTDIR)main.cpp $(TESTDIR)DistanceApp.cpp $(TESTDIR)DistanceView.cpp $(TESTDIR)LList.cpp $(TESTDIR)Node.cpp $(TESTDIR)OptionsView.cpp $(TESTDIR)OptionsViewPlaces.cpp $(TESTDIR)Place.cpp $(TESTDIR)HashTable.cpp
	$(CC) $(CFLAGS) $(TESTDIR)main.cpp -o $(BUILDDIR)testmain.o

test:
	build
	testMain.o
	$(CC) $(LDFLAGS) -o \
	./tmp/testMain \
	./build/HashTable.o \
	./build/Place.o \
	./build/OptionsViewPlaces.o \
	./build/View.o \
	./build/AddPlacesView.o \
	./build/DeletePlacesView.o \
	./build/DistanceView.o \
	./build/ModifyPlaceView.o \
	./build/PlacesView.o \
	./build/DistanceApp.o \
	./build/testmain.o
	cd test
	../tmp/testMain --output=color
	cd ..

build:
	AddPlacesView.o
	DeletePlacesView.o
	DistanceView.o
	ModifyPlaceView.o
	PlacesView.o
	View.o
	OptionsViewPlaces.o
	DistanceApp.o
	HashTable.o
	Place.o
	main.o
	$(COMPILER) $(LDFLAGS) -o \
	./build/release \
	./build/HashTable.o \
	./build/Place.o \
	./build/OptionsViewPlaces.o \
	./build/View.o \
	./build/AddPlacesView.o \
	./build/DeletePlacesView.o \
	./build/DistanceView.o \
	./build/ModifyPlaceView.o \
	./build/PlacesView.o \
	./build/DistanceApp.o \
	./build/main.o

clean:
	cd build
	rm release
	find . -name '*.o' -print0 | xargs -0 rm
	cd ..

.PHONY: test build clean