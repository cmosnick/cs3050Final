all: main

main: main.o grid.o grid.h fileInput.o fileInput.h
	g++ -o main main.o grid.o fileInput.o

main.o: main.cpp
	g++ -c main.cpp

grid.o: grid.cpp
	g++ -c grid.cpp

fileInput.o: fileInput.cpp
	g++ -c fileInput.cpp

clean: 
	rm *.o
	rm main