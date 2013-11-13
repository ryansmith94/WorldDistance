# Compiler Variables
CC=g++
CFLAGS=-c -Wall
LDFLAGS= -Wall

# Directories
SRCDIR=./src/
BUILDDIR=./build/
TESTDIR=./test/
TMPDIR=./tmp/

# Files
FILES=HashTable Place OptionsViewPlaces View AddPlacesView DeletePlacesView DistanceView ModifyPlaceView PlacesView DistanceApp
SRCFILES=$(addprefix $(SRCDIR),$(FILES))
OBJECTS=$(addprefix $(BUILDDIR),$(addsuffix .o,$(FILES)))
SOURCES=$(addsuffix .cpp,$(SRCFILES))
HEADERS=$(addsuffix .h,$(SRCFILES))
TESTS=$(addsuffix .cpp,$(addprefix $(TESTDIR),main DistanceApp DistanceView LList Node OptionsView OptionsViewPlaces Place HashTable))

all: clean test build run

build: $(BUILDDIR)release

test: $(TMPDIR)testMain
	cd $(TESTDIR) && ../tmp/testMain --output=color
	rm $(TMPDIR)*.txt

run: 
	cd $(BUILDDIR) && ./release

clean:
	rm $(BUILDDIR)*.o $(BUILDDIR)release

watch:
	if ! type "wr" > /dev/null; then sudo npm install wr -g; fi
	wr "make test" src test

OptionsViewPlaces.o: $(SRCDIR)OptionsViewPlaces.cpp $(SRCDIR)OptionsViewPlaces.h $(SRCDIR)Place.h $(SRCDIR)OptionsView.h $(SRCDIR)Node.h
	$(CC) $(CFLAGS) $(SRCDIR)OptionsViewPlaces.cpp -o $(BUILDDIR)OptionsViewPlaces.o

DistanceApp.o: $(SRCDIR)DistanceApp.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(SRCDIR)DistanceApp.cpp -o $(BUILDDIR)DistanceApp.o

HashTable.o: $(SRCDIR)HashTable.cpp $(SRCDIR)HashTable.h $(SRCDIR)Place.h $(SRCDIR)Node.h 
	$(CC) $(CFLAGS) $(SRCDIR)HashTable.cpp -o $(BUILDDIR)HashTable.o

main.o: $(SRCDIR)main.cpp $(SRCDIR)main.h $(SRCDIR)DistanceApp.h
	$(CC) $(CFLAGS) $(SRCDIR)main.cpp -o $(BUILDDIR)main.o

Place.o: $(SRCDIR)Place.cpp $(SRCDIR)Place.h $(SRCDIR)LList.h $(SRCDIR)HashTable.h
	$(CC) $(CFLAGS) $(SRCDIR)Place.cpp -o $(BUILDDIR)Place.o

$(BUILDDIR)testmain.o: $(TESTS)
	$(CC) $(CFLAGS) $(TESTDIR)main.cpp -o $@
		
$(BUILDDIR)%View.o: $(SRCDIR)%View.cpp $(SRCDIR)%View.h $(SRCDIR)Place.h $(SRCDIR)HashTable.h $(SRCDIR)View.h
	$(CC) $(CFLAGS) $(SRCDIR)$*View.cpp -o $(BUILDDIR)$*View.o
		
$(BUILDDIR)%.o: $(SRCDIR)%.cpp
	$(CC) $(CFLAGS) $< -o $@

$(TMPDIR)testMain: $(OBJECTS) $(BUILDDIR)testmain.o
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(BUILDDIR)testmain.o

$(BUILDDIR)release: $(OBJECTS) $(BUILDDIR)main.o
	$(CC) $(LDFLAGS) -o $(BUILDDIR)release $(OBJECTS) $(BUILDDIR)main.o

.PHONY: all build test run clean watch