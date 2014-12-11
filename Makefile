all: main

main: main.o grid.o grid.h fileInput.o fileInput.h
	g++ -o main main.o grid.o fileInput.o -Wall

main.o: main.cpp
	g++ -c main.cpp -Wall

grid.o: grid.cpp
	g++ -c grid.cpp -Wall

fileInput.o: fileInput.cpp
	g++ -c fileInput.cpp -Wall

clean: 
	rm *.o
	rm main