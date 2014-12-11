#include "import.cpp"
#include "Grid.h"
#include "fileInput.h"


int main(int argc, char *argv[]){
	//check if file
	if(argc<2){
		cerr << "No file passed" << endl;
		return 0;
	}	
	vector<vector<int> > arr;
	
	//readfile into a vector
	if(readFile(argv[1], arr) == 0){
		cerr<< "Could not open/parse file" <<endl;
		return 0;
	}
	//make a vector of pointers to grid objects, init and fill it.
	vector<vector<Grid *> > gridArr ;
	int count = initGridArr(gridArr, arr);
	Grid* head = fillGridArr(gridArr, arr);
	printGridArr(gridArr);

	//Make a vector for adjacency list
	vector<vector<Grid*> > adjList;
	createAdjList(adjList, gridArr, count);
	//printAdjList(adjList);

	//Find optimal solution
	int soln = Grid::optSoln(head, head->number);
	if(soln == -1){
		cout<<endl<<"End not found :("<<endl;
		return 0;
	}

	cout<<endl<<"Shortest path is: "<<soln<<endl;

	Grid::printPath(head);
	printGridArr(gridArr);
	return 1;
}//end main