all: main

main: main.o grid.o grid.h fileInput.o fileInput.h
	g++ -o main main.o grid.o fileInput.o -Wall -g

main.o: main.cpp
	g++ -c main.cpp -Wall -g

grid.o: grid.cpp
	g++ -c grid.cpp -Wall -g

fileInput.o: fileInput.cpp
	g++ -c fileInput.cpp -Wall -g

clean: 
	rm *.o
	rm main