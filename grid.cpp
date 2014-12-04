#include "Grid.h"
Grid::Grid(){};
Grid::Grid(int val, int passed_type){	number = val;	type = passed_type;	}
void Grid::setLeft(Grid *grid){	left = grid;	}
void Grid::setRight(Grid *grid){	right = grid;	}
void Grid::setFront(Grid *grid){	front = grid;	}
void Grid::setBack(Grid *grid){	back = grid;	}