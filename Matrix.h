#ifndef MATRIX
#define MATRIX
#include "import.cpp"
class Matrix
{
	public:
		Grid *grid;
 		int opt;
 		
		Matrix();

		void setOpt(int val);
};
#endif