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

		int optSoln(Grid *node, int senderNode);

	private:
		int findMin(int num1, int num2, int num3, int num4, int curr);
};
#endif