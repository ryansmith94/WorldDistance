COMPILER=g++
FLAGS=-Wall

objects:

	$(COMPILER) $(FLAGS) -c -g -o ./build/HashTable.o ./src/HashTable.cpp
	$(COMPILER) $(FLAGS) -c -g -o ./build/Place.o ./src/Place.cpp
	$(COMPILER) $(FLAGS) -c -g -o ./build/OptionsViewPlaces.o ./src/OptionsViewPlaces.cpp
	$(COMPILER) $(FLAGS) -c -g -o ./build/AddPlacesView.o ./src/AddPlacesView.cpp
	$(COMPILER) $(FLAGS) -c -g -o ./build/DeletePlacesView.o ./src/DeletePlacesView.cpp
	$(COMPILER) $(FLAGS) -c -g -o ./build/DistanceView.o ./src/DistanceView.cpp
	$(COMPILER) $(FLAGS) -c -g -o ./build/ModifyPlaceView.o ./src/ModifyPlaceView.cpp
	$(COMPILER) $(FLAGS) -c -g -o ./build/PlacesView.o ./src/PlacesView.cpp
	$(COMPILER) $(FLAGS) -c -g -o ./build/DistanceApp.o ./src/DistanceApp.cpp
	$(COMPILER) $(FLAGS) -c -g -o ./build/View.o ./src/View.cpp
	$(COMPILER) $(FLAGS) -c -g -o ./build/main.o ./src/main.cpp
	$(COMPILER) $(FLAGS) -c -g -o ./build/testmain.o ./test/main.cpp

release: 

	$(COMPILER) $(FLAGS) -o \
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

test:

	$(COMPILER) $(FLAGS) -o \
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
	./build/testmain.o && \
	cd test && ../tmp/testMain --output=color && cd ..

.PHONY: objects release test