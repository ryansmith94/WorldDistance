# COMPILER=g++
# FLAGS=-Wall

# objects:

# 	$(COMPILER) $(FLAGS) -c -g -o ./build/HashTable.o ./src/HashTable.cpp
# 	$(COMPILER) $(FLAGS) -c -g -o ./build/Place.o ./src/Place.cpp
# 	$(COMPILER) $(FLAGS) -c -g -o ./build/OptionsViewPlaces.o ./src/OptionsViewPlaces.cpp
# 	$(COMPILER) $(FLAGS) -c -g -o ./build/AddPlacesView.o ./src/AddPlacesView.cpp
# 	$(COMPILER) $(FLAGS) -c -g -o ./build/DeletePlacesView.o ./src/DeletePlacesView.cpp
# 	$(COMPILER) $(FLAGS) -c -g -o ./build/DistanceView.o ./src/DistanceView.cpp
# 	$(COMPILER) $(FLAGS) -c -g -o ./build/ModifyPlaceView.o ./src/ModifyPlaceView.cpp
# 	$(COMPILER) $(FLAGS) -c -g -o ./build/PlacesView.o ./src/PlacesView.cpp
# 	$(COMPILER) $(FLAGS) -c -g -o ./build/DistanceApp.o ./src/DistanceApp.cpp
# 	$(COMPILER) $(FLAGS) -c -g -o ./build/View.o ./src/View.cpp
# 	$(COMPILER) $(FLAGS) -c -g -o ./build/main.o ./src/main.cpp
# 	$(COMPILER) $(FLAGS) -c -g -o ./build/testmain.o ./test/main.cpp

# release: 

# 	$(COMPILER) $(FLAGS) -o \
# 	./build/release \
# 	./build/HashTable.o \
# 	./build/Place.o \
# 	./build/OptionsViewPlaces.o \
# 	./build/View.o \
# 	./build/AddPlacesView.o \
# 	./build/DeletePlacesView.o \
# 	./build/DistanceView.o \
# 	./build/ModifyPlaceView.o \
# 	./build/PlacesView.o \
# 	./build/DistanceApp.o \
# 	./build/main.o

# test:

# 	$(COMPILER) $(FLAGS) -o \
# 	./tmp/testMain \
# 	./build/HashTable.o \
# 	./build/Place.o \
# 	./build/OptionsViewPlaces.o \
# 	./build/View.o \
# 	./build/AddPlacesView.o \
# 	./build/DeletePlacesView.o \
# 	./build/DistanceView.o \
# 	./build/ModifyPlaceView.o \
# 	./build/PlacesView.o \
# 	./build/DistanceApp.o \
# 	./build/testmain.o && \
# 	cd test && ../tmp/testMain --output=color && cd ..

CC=g++
CFLAGS=-c -Wall
LDFLAGS= -Wall
SRCDIR=./src/
BUILDDIR=./build/
TESTDIR=./test/

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

$(BUILDDIR)testMain.o: $(TESTDIR)main.cpp $(TESTDIR)DistanceApp.cpp $(TESTDIR)DistanceView.cpp $(TESTDIR)LList.cpp $(TESTDIR)Node.cpp $(TESTDIR)OptionsView.cpp $(TESTDIR)OptionsViewPlaces.cpp $(TESTDIR)Place.cpp $(TESTDIR)HashTable.cpp
	$(CC) $(CFLAGS) $(TESTDIR)main.cpp -o $(BUILDDIR)testmain.o
	
$(BUILDDIR)%View.o: $(SRCDIR)%View.cpp $(SRCDIR)%View.h $(SRCDIR)Place.h $(SRCDIR)HashTable.h $(SRCDIR)View.h
	$(CC) $(CFLAGS) $(SRCDIR)$*View.cpp -o $(BUILDDIR)$*View.o
	
$(BUILDDIR)%.o: $(SRCDIR)%.cpp
	$(CC) $(CFLAGS) $(SRCDIR)$*.cpp -o $(BUILDDIR)$*.o

test: $(BUILDDIR)HashTable.o $(BUILDDIR)Place.o $(BUILDDIR)OptionsViewPlaces.o $(BUILDDIR)View.o $(BUILDDIR)AddPlacesView.o $(BUILDDIR)DeletePlacesView.o $(BUILDDIR)DistanceView.o $(BUILDDIR)ModifyPlaceView.o $(BUILDDIR)PlacesView.o $(BUILDDIR)DistanceApp.o $(BUILDDIR)testmain.o
	$(CC) $(LDFLAGS) -o \
	./tmp/testMain \
	$(BUILDDIR)HashTable.o \
	$(BUILDDIR)Place.o \
	$(BUILDDIR)OptionsViewPlaces.o \
	$(BUILDDIR)View.o \
	$(BUILDDIR)AddPlacesView.o \
	$(BUILDDIR)DeletePlacesView.o \
	$(BUILDDIR)DistanceView.o \
	$(BUILDDIR)ModifyPlaceView.o \
	$(BUILDDIR)PlacesView.o \
	$(BUILDDIR)DistanceApp.o \
	$(BUILDDIR)testmain.o
	cd $(TESTDIR)
	../tmp/testMain --output=color
	cd ..

build: $(BUILDDIR)HashTable.o $(BUILDDIR)Place.o $(BUILDDIR)OptionsViewPlaces.o $(BUILDDIR)View.o $(BUILDDIR)AddPlacesView.o $(BUILDDIR)DeletePlacesView.o $(BUILDDIR)DistanceView.o $(BUILDDIR)ModifyPlaceView.o $(BUILDDIR)PlacesView.o $(BUILDDIR)DistanceApp.o $(BUILDDIR)main.o
	
	$(CC) $(LDFLAGS) -o \
	$(BUILDDIR)release \
	$(BUILDDIR)HashTable.o \
	$(BUILDDIR)Place.o \
	$(BUILDDIR)OptionsViewPlaces.o \
	$(BUILDDIR)View.o \
	$(BUILDDIR)AddPlacesView.o \
	$(BUILDDIR)DeletePlacesView.o \
	$(BUILDDIR)DistanceView.o \
	$(BUILDDIR)ModifyPlaceView.o \
	$(BUILDDIR)PlacesView.o \
	$(BUILDDIR)DistanceApp.o \
	$(BUILDDIR)main.o

clean:
	rm build/*.o build/release

.PHONY: test build clean