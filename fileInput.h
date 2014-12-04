#include "import.cpp"
#include "Grid.h"

int readFile(char * arg, vector<vector<int> > &arr);
void printArray(vector<vector<int> > &arr);
void printGridArr(vector<vector<Grid *> > &arr);
int initGridArr(vector<vector<Grid *> > &gridArr, vector<vector<int> > &intArr);
Grid* fillGridArr(vector<vector<Grid *> > &gridArr, vector<vector<int> > &arr);
void createAdjList(vector<vector<Grid *> > &adjList, vector<vector<Grid *> > &gridArrt, int totSizes);
void printAdjList(vector<vector<Grid*> > &adjList);