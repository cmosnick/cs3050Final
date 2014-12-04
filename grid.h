#ifndef GRID
#define GRID
#include "import.cpp"
class Grid
{
	public:
		Grid *left, *right, *front, *back;
		bool visited;
 		int number, type;
 		
		Grid(int val, int passed_type);
		Grid();

		void setLeft(Grid *grid);

		void setRight(Grid *grid);

		void setFront(Grid *grid);

		void setBack(Grid *grid);
};
#endif