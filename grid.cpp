#include "Grid.h"
	
	Grid::Grid(){};
	Grid::Grid(int val, char passed_type){	number = val;	type = passed_type;	opt = INFINITY;	optStatus = 0;}
	void Grid::setLeft(Grid *grid){		left = grid;	}
	void Grid::setRight(Grid *grid){	right = grid;	}
	void Grid::setFront(Grid *grid){	front = grid;	}
	void Grid::setBack(Grid *grid){		back = grid;	}
	Grid* Grid::getLeft(){return left;}
	Grid* Grid::getRight(){return right;}
	Grid* Grid::getFront(){return front;}
	Grid* Grid::getBack(){return back;}

	int Grid::getNumber(){return number;}
	int Grid::getOpt(){return opt;}
	int Grid::getOptStatus(){return optStatus;}
	char Grid::getType(){return type;}

	int Grid::optSoln(Grid *node, int senderNode){
		int fres, bres, lres, rres, temp = (int)INFINITY, temp2 = (int)INFINITY; temp2++;
		//Check base case: null, at end, or still working on optimization (to prevent loops)
		if(node == NULL) return -1;
		if(node->type == 'E') return 1;
		//if node->optStatus is odd, then loop has occurred.  Limit visits to 7 visits or inifinte loop occurs w/o limit.
		if(node->optStatus%2 == 1 || node->optStatus>=14){
			if(node->opt == temp)	return node->opt;
			else					return node->opt+1;
		}

		node->optStatus ++; //change node status to odd
		//Look to Front
		if(node->front == NULL) fres = INFINITY;
		else if(node->front != NULL && node->front->number != senderNode){
			fres = optSoln(node->front, node->number);
		} else fres = INFINITY;
		//Look to Back
		if(node->back == NULL) bres = INFINITY;
		else if(node->back != NULL && node->back->number != senderNode){
			bres = optSoln(node->back, node->number);
		}else bres = INFINITY;
		//Look to Left
		if(node->left == NULL) lres = INFINITY;
		else if(node->left != NULL && node->left->number != senderNode){
			lres = optSoln(node->left, node->number);
		}else lres = INFINITY;
		//Look to Right
		if(node->right == NULL) rres = INFINITY;
		else if(node->right != NULL && node->right->number != senderNode){
			rres = optSoln(node->right, node->number);
		}else rres = INFINITY;

		//Find min
		int min = findMin(fres, bres, lres, rres, node->opt);
		node->opt = min;
		node->optStatus ++;	//change node status back to even

		//make sure do not overflow int w/ infinity (would make it neg-infinity)
		if(min != temp)	return min+1;
		return node->opt;
	}

	int Grid::findMin(int num1, int num2, int num3, int num4, int curr){
		int min = num1;
		if(min > num2) min = num2;
		if(min > num3) min = num3;
		if(min > num4) min = num4;
		if(min > curr) min = curr;
		return min;
	}

	void Grid::printPath(Grid *head){
		if(head == NULL) return;
		int temp = (int)INFINITY;
		if(head->opt == temp) return;
		//Mark it as part of path
		if(head->type != 'S')	head->type = '@';
		if(head->front != NULL && head->front->opt == head->opt-1) printPath(head->front);
		if(head->back != NULL && head->back->opt == head->opt-1) printPath(head->back);
		if(head->left != NULL && head->left->opt == head->opt-1) printPath(head->left);
		if(head->right != NULL && head->right->opt == head->opt-1) printPath(head->right);
		return;
	}





