#include "import.cpp"
#include "grid.h"

int readFile(char * arg, vector<vector<int> > &arr);
void printArray(vector<vector<int> > &arr);
void printGrid(vector<vector<Grid *> > &arr);
void initGridArr(vector<vector<Grid *> > &gridArr, vector<vector<int> > &intArr);
Grid* fillGridArr(vector<vector<Grid *> > &gridArr, vector<vector<int> > &arr);
int main(int argc, char *argv[])
{
	//check if file
	if(argc<2)
	{
		cerr << "No file passed" << endl;
		return 0;
	}	
	vector<vector<int> > arr;
	
	//readfile into a vector
	if(readFile(argv[1], arr) == 0){
		cerr<< "Could not open/parse file" <<endl;
		return 0;
	}
	cout<<endl<<arr.size()<<endl<<arr[1].size()<<endl;
	//make a vector of pointers to grid objects
	vector<vector<Grid *> > gridArr ;
	initGridArr(gridArr, arr);
	Grid* head = fillGridArr(gridArr, arr);

	cout<<head<<endl;
	return 1;
}//end main


void printArray(vector<vector<int> > &arr)
{
	int r, c;
	for(r=0; r<arr.size() ; r++)
	{
		cout << endl;
		for(c=0; c<arr[r].size() ; c++)
		{
			cout<<arr[r][c];
		}
	}
	
	return;
}

int readFile(char * arg, vector<vector<int> > &arr )
{
	//readfile
	ifstream file;
	file.open(arg, ios::in);
	if(!file)
	{
		cout << "\nCould not open file" << endl;
		return 0;
	}
	
	///set up 2d array (vector)
	int row=0, val, col=0, len, i;
	arr.resize(MAX);  for(i=0 ; i<MAX; i++) arr[i].resize(MAX);
	string str, line;
	while(!file.eof()){
		getline(file, str);
		len =str.size();
		//newline
		cout << endl;
		for(i=0 ; i<len ; i++){
			cout <<str[i];
			switch(str[i])
			{
				case '#': 	val = 0; 	break;
				case 'S':	val = 1; 	break;
				case 'E': 	val = 3; 		break;
				default: 	val = 2; 	break;
			}

			arr[row][i] = val;
		}
		arr[row].resize(i);
		if(i > col) col = i;
		row++;
	}
	arr.resize(row);
	printArray(arr);
	return 1;
}

void initGridArr(vector<vector<Grid *> > &gridArr, vector<vector<int> > &intArr)
{
	int i, j, size2, size=intArr.size();
	//cout<<size<<endl;
	gridArr.resize(size);
	for(i=0 ; i<size ; i++)
	{
		size2 = intArr[i].size();
		gridArr[i].resize(size2);
		for(j=0 ; j<size2 ; j++)
		{
			Grid *newGrid = new Grid;
			gridArr[i][j] = newGrid;
			//cout <<newGrid<<endl;
		}
	}
	//printGrid(gridArr);
	return;
}

void printGrid(vector<vector<Grid *> > &arr)
{
	int r, c;
	for(r=0; r<arr.size() ; r++)
	{
		cout << endl;
		for(c=0; c<arr[r].size() ; c++)
		{
			cout<<arr[r][c];
		}
	}
	return;
}


Grid* fillGridArr(vector<vector<Grid *> > &gridArr, vector<vector<int> > &arr)
{
	int size, size2, r, c;
	size = arr.size();
	Grid *head = NULL;
	for(r=0 ; r<size ; r++)
	{
		size2 = arr[r].size();
		for(c=0 ; c<size2 ; c++){
			//check upper bound
			if(r>0 && c<arr[r-1].size()){	gridArr[r][c]->setFront(gridArr[r-1][c]);	}
			else gridArr[r][c]->setFront(NULL);

			//check lower bound
			if(r<size && c<arr[r+1].size()){	gridArr[r][c]->setBack(gridArr[r+1][c]);	}
			else gridArr[r][c]->setBack(NULL);
			
			//check left bound
			if(c>0){	gridArr[r][c]->setLeft(gridArr[r][c-1]);	}
			else gridArr[r][c]->setLeft(NULL);

			//check right bound
			if((c+1)< size2){	gridArr[r][c]->setRight(gridArr[r][c+1]);	}
			else gridArr[r][c]->setRight(NULL);

			if(arr[r][c] == 1) head = gridArr[r][c];
		}
	}
	return head;
}






