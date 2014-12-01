#include "grid.h"
Grid::Grid(){};
void Grid::setLeft(Grid *grid){	left = grid;	}
void Grid::setRight(Grid *grid){	right = grid;	}
void Grid::setFront(Grid *grid){	front = grid;	}
void Grid::setBack(Grid *grid){	back = grid;	}