#include "import.cpp"
#include "Grid.h"
#include "fileInput.h"


int main(int argc, char *argv[]){
	//check if file
	if(argc<2){
		cerr << "No file passed" << endl;
		return 0;
	}	
	vector<vector<char> > arr;
	
	//readfile into a vector
	if(readFile(argv[1], arr) == 0){
		cerr<< "Could not open/parse file" <<endl;
		return 0;
	}
	//make a vector of pointers to grid objects, init and fill it.
	vector<vector<Grid *> > gridArr ;
	/*int count = */initGridArr(gridArr, arr);
	Grid* head = fillGridArr(gridArr, arr);
	cout<<endl<<"Grid Array:";
	printGridArr(gridArr);

	//Make a vector for adjacency list, solely for the purpose of showing file was read in correctly
		/*vector<vector<Grid*> > adjList;
		createAdjList(adjList, gridArr, count);
		printAdjList(adjList);
		*/

	//Find optimal solution
	int soln = Grid::optSoln(head, head->getNumber());
	int temp = numeric_limits<int>::max();
	if(soln == -1 || soln == temp){
		cout<<endl<<"End not found :("<<endl;
		return 0;
	}

	cout<<"\n\n\nShortest path(s) is/are: "<<soln<<endl;

	Grid::printPath(head);
	cout<<"\n\nThere may be many equally optimal paths.  \nAll are shown here:";
	printGridArr(gridArr);
	return 1;
}//end main