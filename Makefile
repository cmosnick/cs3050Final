all: main

main: main.o Grid.o Grid.h fileInput.o fileInput.h
	g++ -o main main.o Grid.o fileInput.o -Wall -g

main.o: main.cpp
	g++ -c main.cpp -Wall -g

Grid.o: Grid.cpp
	g++ -c Grid.cpp -Wall -g

fileInput.o: fileInput.cpp
	g++ -c fileInput.cpp -Wall -g

clean: 
	rm *.o
	rm main
