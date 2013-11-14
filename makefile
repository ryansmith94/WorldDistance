# Compiler Variables
CC=g++
CFLAGS=-c -Wall
LDFLAGS= -Wall

# Directories
SRCDIR=./src/
BUILDDIR=./build/
SRCOBJDIR=./tmp/src/
TESTOBJDIR=./tmp/test/
TESTDIR=./test/
TMPDIR=./tmp/

# Files
FILES=HashTable Place OptionsViewPlaces View AddPlacesView DeletePlacesView DistanceView ModifyPlaceView PlacesView DistanceApp
TESTFILES=main DistanceApp DistanceView LList Node OptionsView OptionsViewPlaces Place HashTable TestWithStdIO compareFiles
SRCFILES=$(addprefix $(SRCDIR),$(FILES))
OBJECTS=$(addprefix $(SRCOBJDIR),$(addsuffix .o,$(FILES)))
SOURCES=$(addsuffix .cpp,$(SRCFILES))
HEADERS=$(addsuffix .h,$(SRCFILES))
TESTS=$(addsuffix .cpp,$(addprefix $(TESTDIR),$(TESTFILES)))
TESTSOBJS=$(addsuffix .o,$(addprefix $(TESTOBJDIR),$(TESTFILES)))

all: test build

build: $(BUILDDIR)release

test: $(TESTSOBJS) $(OBJECTS) $(TMPDIR)testMain
	cd $(TESTDIR) && ../tmp/testMain --output=color
	rm $(TMPDIR)*.txt

run: 
	cd $(BUILDDIR) && ./release

clean:
	\rm -f $(SRCOBJDIR)*.o $(BUILDDIR)release $(TESTOBJDIR)*.o

watch:
	if ! type "wr" > /dev/null; then sudo npm install wr -g; fi
	wr "make all" src test

$(SRCOBJDIR)OptionsViewPlaces.o: $(addprefix $(SRCDIR),OptionsViewPlaces.cpp OptionsViewPlaces.h Place.h OptionsView.h Node.h)
	$(CC) $(CFLAGS) $(SRCDIR)OptionsViewPlaces.cpp -o $(SRCOBJDIR)OptionsViewPlaces.o

$(SRCOBJDIR)DistanceApp.o: $(SRCDIR)DistanceApp.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(SRCDIR)DistanceApp.cpp -o $(SRCOBJDIR)DistanceApp.o

$(SRCOBJDIR)HashTable.o: $(addprefix $(SRCDIR),HashTable.cpp HashTable.h Place.h Node.h)
	$(CC) $(CFLAGS) $(SRCDIR)HashTable.cpp -o $(SRCOBJDIR)HashTable.o

$(SRCOBJDIR)main.o: $(addprefix $(SRCDIR),main.cpp DistanceApp.h)
	$(CC) $(CFLAGS) $(SRCDIR)main.cpp -o $(SRCOBJDIR)main.o

$(SRCOBJDIR)Place.o: $(addprefix $(SRCDIR),Place.cpp Place.h LList.h HashTable.h)
	$(CC) $(CFLAGS) $(SRCDIR)Place.cpp -o $(SRCOBJDIR)Place.o

$(TESTOBJDIR)main.o: $(TESTS)
	$(CC) $(CFLAGS) $(TESTDIR)main.cpp -o $@
		
$(SRCOBJDIR)%View.o: $(addprefix $(SRCDIR),%View.cpp %View.h Place.h HashTable.h View.h OptionsView.h)
	$(CC) $(CFLAGS) $(SRCDIR)$*View.cpp -o $(SRCOBJDIR)$*View.o
		
$(SRCOBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) $(CFLAGS) $< -o $@

$(TESTOBJDIR)%.o: $(TESTDIR)%.cpp
	$(CC) $(CFLAGS) $< -o $@

$(TMPDIR)testMain: $(OBJECTS) $(TESTOBJDIR)main.o
	$(CC) $(LDFLAGS) -o $@ $(TESTSOBJS) $(OBJECTS)

$(BUILDDIR)release: $(OBJECTS) $(SRCOBJDIR)main.o
	$(CC) $(LDFLAGS) -o $(BUILDDIR)release $(OBJECTS) $(SRCOBJDIR)main.o

.PHONY: all build test run clean watch