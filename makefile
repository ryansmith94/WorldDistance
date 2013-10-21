COMPILER=g++
FLAGS=-Wall

release:
	$(COMPILER) -o ./build/main ./src/main.cpp $(FLAGS) && \
    $(COMPILER) -o ./tmp/testMain ./test/main.cpp $(FLAGS) && \
    cd test && ../tmp/testMain --output=color && cd ..
