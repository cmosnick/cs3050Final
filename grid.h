#ifndef GRID
#define GRID
#include "import.cpp"
class Grid
{
	public:
		Grid *left, *right, *front, *back;
		bool visited;
 		int number, type, opt, optStatus;
 		//opt status is to prevent loops in the optimization.  0 not found, 1 is working on it, 2 is finished.
 	
		Grid(int val, int passed_type);
		Grid();

		void setLeft(Grid *grid);

		void setRight(Grid *grid);

		void setFront(Grid *grid);

		void setBack(Grid *grid);

		static int optSoln(Grid *node, int senderNode);
		static void printPath(Grid *head);

	private:
		static int findMin(int num1, int num2, int num3, int num4, int curr);
		static Grid* findMin(Grid *n1, Grid *n2, Grid *n3, Grid *n4, Grid *head);
};
#endif