#include "fileInput.h"


void printArray(vector<vector<char> > &arr){
	unsigned int r, c;
	for(r=0; r<arr.size() ; r++){
		cout << endl;
		for(c=0; c<arr[r].size() ; c++){
			cout<<arr[r][c];
		}
	}
	return;
}

int readFile(char * arg, vector<vector<char> > &arr ){
	//Vars
	int row=0, col=0, len, i;
	string str, line;
	ifstream file;

	//Open file
	file.open(arg, ios::in);
	if(!file){
		cout << "\nCould not open file" << endl;
		return 0;
	}
	
	//Set up 2D array (vector) by resizing it to max size.  Will trim off excess later to save space.
	arr.resize(MAX);  for(i=0 ; i<MAX; i++) arr[i].resize(MAX);
	//Iterate through file, line by line.
	while(!file.eof()){
		getline(file, str);
		len = str.size();
		//Iterate through line char by char, assign to vector
		for(i=0 ; i<len ; i++){
			if(str[i]=='#' || str[i]=='S' || str[i]=='E')	arr[row][i] = str[i];
			else arr[row][i] = ' ';
		}
		//resize whole row to i, number of elements in row
		arr[row].resize(i);
		if(i > col) col = i;
		row++;
	}
	//resize vector to row, number of rows (vectors) in main vector
	arr.resize(row);
	return 1;
}

//Use vector array to initilize the grid array's size and values
int initGridArr(vector<vector<Grid *> > &gridArr, vector<vector<char> > &intArr){
	int i, j, size2, size=intArr.size(), count=0;
	gridArr.resize(size);
	for(i=0 ; i<size ; i++){
		size2 = intArr[i].size();
		gridArr[i].resize(size2);
		for(j=0 ; j<size2 ; j++){
			//Create new Grid object, init its sequence number and type
			Grid *newGrid = new Grid(count, intArr[i][j]);
			gridArr[i][j] = newGrid;
			count++;
		}
	}
	return count;
}


Grid* fillGridArr(vector<vector<Grid *> > &gridArr, vector<vector<char> > &arr){
	unsigned int size, size2, r, c;
	size = arr.size();
	Grid *head = NULL;
	for(r=0 ; r<size ; r++){
		size2 = arr[r].size();
		for(c=0 ; c<size2 ; c++){
			//Check if node is a wall
			if(gridArr[r][c]->getType() == '#'){	
				gridArr[r][c]->setFront(NULL);
				gridArr[r][c]->setBack(NULL);
				gridArr[r][c]->setLeft(NULL);
				gridArr[r][c]->setRight(NULL);	
			}else{
				//check upper bound
				if(r>0 && c<arr[r-1].size() && arr[r-1][c]!='#'){		gridArr[r][c]->setFront(gridArr[r-1][c]);	}
				else 											gridArr[r][c]->setFront(NULL);
				//check lower bound
				if(r<size && c<arr[r+1].size() && arr[r+1][c]!='#'){	gridArr[r][c]->setBack(gridArr[r+1][c]);	}
				else 											gridArr[r][c]->setBack(NULL);
				//check left bound
				if(c>0 && arr[r][c-1]!='#'){							gridArr[r][c]->setLeft(gridArr[r][c-1]);	}
				else 											gridArr[r][c]->setLeft(NULL);
				//check right bound
				if((c+1)< size2 && arr[r][c+1]!='#'){					gridArr[r][c]->setRight(gridArr[r][c+1]);	}
				else 											gridArr[r][c]->setRight(NULL);
			}

			//Check if head, or start
			if(arr[r][c] == 'S') head = gridArr[r][c];
		}
	}
	return head;
}


void printGridArr(vector<vector<Grid *> > &arr){
	unsigned int r, c;
	for(r=0; r<arr.size() ; r++){
		cout << endl;
		for(c=0; c<arr[r].size() ; c++){
			if(arr[r][c]->getType() == 'S') printf(ANSI_GREEN "%c" ANSI_RESET ,arr[r][c]->getType());
			else if(arr[r][c]->getType() == 'E') printf(ANSI_RED "%c" ANSI_RESET ,arr[r][c]->getType());
			else if(arr[r][c]->getType() == '@') printf(ANSI_BLUE "%c" ANSI_RESET ,arr[r][c]->getType());
			else printf("%c",arr[r][c]->getType());
		}
	}
	return;
}


/*Adjlist vector will be a 2D vector of pointers to grid nodes.  
The first grid object in each secondary vector will be the grid node.  
Each one folowing will be its adjacent nodes.
*/
void createAdjList(vector<vector<Grid *> > &adjList, vector<vector<Grid *> > &gridArr, int totSize){
	int i, j, count =0, count2=1, size = gridArr.size(), size2;
	adjList.resize(totSize);

	for(i=0 ; i<size ; i++){
		size2 = gridArr[i].size();
		for(j=0 ; j<size2 ; j++){
			//assign grid object to adj list, assign all adjacent nodes
			adjList[count].resize(5);
			adjList[count][0] = gridArr[i][j];
			if(gridArr[i][j]->getLeft() != NULL){	adjList[count][count2]=gridArr[i][j]->getLeft(); count2++;}
			if(gridArr[i][j]->getRight() != NULL){	adjList[count][count2]=gridArr[i][j]->getRight(); count2++;}
			if(gridArr[i][j]->getFront() != NULL){	adjList[count][count2]=gridArr[i][j]->getFront(); count2++;}
			if(gridArr[i][j]->getBack() != NULL){	adjList[count][count2]=gridArr[i][j]->getBack(); count2++;}
			adjList[count].resize(count2);	count2=1;	count++;
		}
	}	
}

void printAdjList(vector<vector<Grid*> > &adjList){
	int i, j, size=adjList.size(), size2;
	cout<<endl<<"Adjacecny List:"<<endl;
	for(i=0 ; i<size ; i++){
		size2 = adjList[i].size();
		cout<<setw(5)<<left<<adjList[i][0]->getNumber()<<"| ";
		for(j=1 ; j<size2 ;j++){
			cout<<setw(5)<<left<<adjList[i][j]->getNumber();
		}
		cout<<endl;
	}
}
