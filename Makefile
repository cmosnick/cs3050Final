all: main

main: main.o Grid.o Grid.h fileInput.o fileInput.h
	g++ -o main main.o Grid.o fileInput.o -Wall

main.o: main.cpp
	g++ -c main.cpp -Wall

Grid.o: Grid.cpp
	g++ -c Grid.cpp -Wall

fileInput.o: fileInput.cpp
	g++ -c fileInput.cpp -Wall

clean: 
	rm *.o
	rm main
