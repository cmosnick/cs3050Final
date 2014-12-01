all: main

main: main.o grid.o grid.h
	g++ -o main main.o grid.o

main.o: main.cpp
	g++ -c main.cpp

grid.o: grid.cpp
	g++ -c grid.cpp

clean: 
	rm *.o