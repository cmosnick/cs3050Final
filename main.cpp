#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#define MAX 	5000
using namespace std;


int readFile(char * arg, vector<vector<int> > arr);
void printArray(vector<vector<int> > arr, int rows, int cols);
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

	//cout<< endl<< START << endl <<END << endl << SPACE << endl << WALL <<endl;
	//send vector to be turned into a graph


	return 1;
}//end main


void printArray(vector<vector<int> > arr, int rows, int cols)
{
	int r, c;
	for(r=0; r<rows ; r++)
	{
		cout << endl;
		for(c=0; c<cols ; c++)
		{
			cout<<arr[r][c];
		}
	}
	return;
}

int readFile(char * arg, vector<vector<int> > arr )
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
		if(i > col) col = i;
		row++;
	}

	printArray(arr, row, col);
	return 1;
}