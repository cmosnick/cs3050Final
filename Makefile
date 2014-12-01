all: main

main: main.o
	g++ -o main main.o

main.o: 
	g++ -c main.cpp

clean: 
	rm *.o all