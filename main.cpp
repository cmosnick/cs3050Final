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

	//Call OptSoln from head
	int soln = head->optSoln(head, head->number);
	cout<<endl<<"Shortest path is: "<<soln<<endl;

	/*soln = head->optSoln(head, head->number);
	cout<<endl<<"Shortest path is: "<<soln<<endl; */
	return 1;
}//end main