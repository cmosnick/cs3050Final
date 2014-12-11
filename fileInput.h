#include "import.cpp"
#include "Grid.h"

int readFile(char * arg, vector<vector<char> > &arr);
void printArray(vector<vector<char> > &arr);
void printGridArr(vector<vector<Grid *> > &arr);
int initGridArr(vector<vector<Grid *> > &gridArr, vector<vector<char> > &intArr);
Grid* fillGridArr(vector<vector<Grid *> > &gridArr, vector<vector<char> > &arr);
void createAdjList(vector<vector<Grid *> > &adjList, vector<vector<Grid *> > &gridArrt, int totSizes);
void printAdjList(vector<vector<Grid*> > &adjList);