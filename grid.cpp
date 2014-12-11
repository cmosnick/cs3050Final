#include "Grid.h"
	
	Grid::Grid(){};
	Grid::Grid(int val, int passed_type){	number = val;	type = passed_type;	opt = INFINITY;	optStatus = 0;}
	void Grid::setLeft(Grid *grid){		left = grid;	}
	void Grid::setRight(Grid *grid){	right = grid;	}
	void Grid::setFront(Grid *grid){	front = grid;	}
	void Grid::setBack(Grid *grid){		back = grid;	}

	int Grid::optSoln(Grid *node, int senderNode){
		int fres, bres, lres, rres, temp = INFINITY, temp2 = INFINITY; temp2++;
		//Check base case: null, at end, or still working on optimization(to prvenet loops)
		if(node == NULL) return -1;
		if(node->type == 3) return 1;
		if(node->optStatus ==1 || node->optStatus ==3 || node->optStatus==5 || node->optStatus==7 || node->optStatus==9|| node->optStatus==11|| node->optStatus==13|| node->optStatus==14){
			if(node->opt == temp){
				//printf("\n%dInfinity, returning %d to %d", node->number, node->opt+1, senderNode);			
				return node->opt;
			}
			else{
				//printf("\n%dNot infinity, returning %d to %d", node->number, node->opt, senderNode);			
				return node->opt+1;
			}
		}

		node->optStatus ++;
		//Look to Front
		if(node->front == NULL) fres = INFINITY;
		//else if(node->front->optStatus ==1) fres = node->front->opt+1;
		else if(node->front != NULL && node->front->number != senderNode){
			printf("\n(%d->%d)", node->number, node->front->number);
			fres = optSoln(node->front, node->number);
		} else fres = INFINITY;
		//Look to Back
		if(node->back == NULL) bres = INFINITY;
		//else if(node->back->optStatus ==1) bres = node->back->opt+1;
		else if(node->back != NULL && node->back->number != senderNode){
			printf("\n(%d->%d)", node->number, node->back->number);
			bres = optSoln(node->back, node->number);
		}else bres = INFINITY;
		//Look to Left
		if(node->left == NULL) lres = INFINITY;
		//else if(node->left->optStatus ==1) lres = node->left->opt+1;
		else if(node->left != NULL && node->left->number != senderNode){
			printf("\n(%d->%d)", node->number, node->left->number);
			lres = optSoln(node->left, node->number);
		}else lres = INFINITY;
		//Look to Right
		if(node->right == NULL) rres = INFINITY;
		//else if(node->right->optStatus ==1) rres = node->right->opt+1;
		else if(node->right != NULL && node->right->number != senderNode){
			printf("\n(%d->%d)", node->number, node->right->number);
			rres = optSoln(node->right, node->number);
		}else rres = INFINITY;

		//Find min
		int min = findMin(fres, bres, lres, rres, node->opt);
		node->opt = min;
		node->optStatus ++;

		//cout<<endl<<min;
		//make sure do not overflow int w/ infinity
		if(min != temp){	
			//printf("\n%d returning %d to %d", node->number, min+1, senderNode);
			return min+1;	}
		//printf("\n%d returning %d to %d", node->number, node->opt, senderNode);
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







