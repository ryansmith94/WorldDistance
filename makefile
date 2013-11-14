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
TESTFILES=main DistanceApp DistanceView LList Node OptionsView OptionsViewPlaces Place HashTable TestWithStdIO compareFiles
SRCFILES=$(addprefix $(SRCDIR),$(FILES))
OBJECTS=$(addprefix $(BUILDDIR),$(addsuffix .o,$(FILES)))
SOURCES=$(addsuffix .cpp,$(SRCFILES))
HEADERS=$(addsuffix .h,$(SRCFILES))
TESTS=$(addsuffix .cpp,$(addprefix $(TESTDIR),$(TESTFILES)))
TESTSOBJS=$(addsuffix .o,$(addprefix $(TMPDIR),$(TESTFILES)))

all: test build

build: $(BUILDDIR)release

test: $(TESTSOBJS) $(OBJECTS) $(TMPDIR)testMain
	cd $(TESTDIR) && ../tmp/testMain --output=color
	rm $(TMPDIR)*.txt

run: 
	cd $(BUILDDIR) && ./release

clean:
	\rm -f $(BUILDDIR)*.o $(BUILDDIR)release $(TMPDIR)*.o

watch:
	if ! type "wr" > /dev/null; then sudo npm install wr -g; fi
	wr "make all" src test

OptionsViewPlaces.o: $(addprefix $(SRCDIR),OptionsViewPlaces.cpp OptionsViewPlaces.h Place.h OptionsView.h Node.h)
	$(CC) $(CFLAGS) $(SRCDIR)OptionsViewPlaces.cpp -o $(BUILDDIR)OptionsViewPlaces.o

DistanceApp.o: $(SRCDIR)DistanceApp.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(SRCDIR)DistanceApp.cpp -o $(BUILDDIR)DistanceApp.o

HashTable.o: $(addprefix $(SRCDIR),HashTable.cpp HashTable.h Place.h Node.h)
	$(CC) $(CFLAGS) $(SRCDIR)HashTable.cpp -o $(BUILDDIR)HashTable.o

main.o: $(addprefix $(SRCDIR),main.cpp main.h DistanceApp.h)
	$(CC) $(CFLAGS) $(SRCDIR)main.cpp -o $(BUILDDIR)main.o

Place.o: $(addprefix $(SRCDIR),Place.cpp Place.h LList.h HashTable.h)
	$(CC) $(CFLAGS) $(SRCDIR)Place.cpp -o $(BUILDDIR)Place.o

$(TMPDIR)main.o: $(TESTS)
	$(CC) $(CFLAGS) $(TESTDIR)main.cpp -o $@
		
$(BUILDDIR)%View.o: $(addprefix $(SRCDIR),%View.cpp %View.h Place.h HashTable.h View.h OptionsView.h)
	$(CC) $(CFLAGS) $(SRCDIR)$*View.cpp -o $(BUILDDIR)$*View.o
		
$(BUILDDIR)%.o: $(SRCDIR)%.cpp
	$(CC) $(CFLAGS) $< -o $@

$(TMPDIR)%.o: $(TESTDIR)%.cpp
	$(CC) $(CFLAGS) $< -o $@

$(TMPDIR)testMain: $(OBJECTS) $(TMPDIR)main.o
	$(CC) $(LDFLAGS) -o $@ $(TESTSOBJS) $(OBJECTS)

$(BUILDDIR)release: $(OBJECTS) $(BUILDDIR)main.o
	$(CC) $(LDFLAGS) -o $(BUILDDIR)release $(OBJECTS) $(BUILDDIR)main.o

.PHONY: all build test run clean watch