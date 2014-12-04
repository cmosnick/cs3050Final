all: main

main: main.o grid.o grid.h AdjNode.o AdjNode.h
	g++ -o main main.o grid.o AdjNode.o

main.o: main.cpp
	g++ -c main.cpp

grid.o: grid.cpp
	g++ -c grid.cpp

AdjNode.o: AdjNode.cpp
	g++ -c AdjNode.cpp

clean: 
	rm *.o