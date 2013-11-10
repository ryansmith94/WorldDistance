COMPILER=g++
FLAGS=-Wall

release: 
	
	$(COMPILER) -o ./build/main ./src/Place.cpp ./src/AddPlacesView.cpp ./src/DeletePlacesView.cpp ./src/DistanceApp.cpp ./src/DistanceView.cpp ./src/HashTable.cpp ./src/LList.cpp ./src/ModifyPlacesView.cpp ./src/Node.cpp  ./src/OptionsView.cpp ./src/OptionsViewPlace.cpp ./src/View.cpp ./src/main.cpp $(FLAGS) && \
	$(COMPILER) -o ./tmp/testMain ./src/Place.cpp ./src/AddPlacesView.cpp ./src/DeletePlacesView.cpp ./src/DistanceApp.cpp ./src/DistanceView.cpp ./src/HashTable.cpp ./src/LList.cpp ./src/ModifyPlacesView.cpp ./src/Node.cpp  ./src/OptionsView.cpp ./src/OptionsViewPlace.cpp ./src/View.cpp./test/main.cpp $(FLAGS) && \
	cd test && ../tmp/testMain --output=color && cd ..