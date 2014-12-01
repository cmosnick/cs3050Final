#include "import.cpp"
class Grid
{
	public:
		Grid *left, *right, *front, *back;
		bool visited;
 
		Grid();

		void setLeft(Grid *grid);

		void setRight(Grid *grid);

		void setFront(Grid *grid);

		void setBack(Grid *grid);
};