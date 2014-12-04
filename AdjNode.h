#ifndef ADJNODE
#define ADJNODE
#include "import.cpp"
#include "Grid.h"

class AdjNode
{
	public:
		int number;
		AdjNode *next;
		Grid *original;
 		
 		AdjNode();
		AdjNode(int num);
};

#endif