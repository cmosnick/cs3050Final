#include "Grid.h"
	
	Grid::Grid(){};
	Grid::Grid(int val, int passed_type){	number = val;	type = passed_type;	opt = INFINITY;	optStatus = 0;}
	void Grid::setLeft(Grid *grid){		left = grid;	}
	void Grid::setRight(Grid *grid){	right = grid;	}
	void Grid::setFront(Grid *grid){	front = grid;	}
	void Grid::setBack(Grid *grid){		back = grid;	}

	int Grid::optSoln(Grid *node, int senderNode){
		int fres, bres, lres, rres, temp = INFINITY, temp2 = INFINITY; temp2++;
		//Check base case: null, at end, or still working on optimization (to prevent loops)
		if(node == NULL) return -1;
		if(node->type == 3) return 1;
		//if node->optStatus is odd, then loop has occurred.  Limit visits to 7 visits or inifinte loop occurs w/o limit.
		if(node->optStatus%2 == 1 || node->optStatus>=14){
			if(node->opt == temp)	return node->opt;
			else					return node->opt+1;
		}

		node->optStatus ++;
		//Look to Front
		if(node->front == NULL) fres = INFINITY;
		else if(node->front != NULL && node->front->number != senderNode){
			//printf("\n(%d->%d)", node->number, node->front->number);
			fres = optSoln(node->front, node->number);
		} else fres = INFINITY;
		//Look to Back
		if(node->back == NULL) bres = INFINITY;
		else if(node->back != NULL && node->back->number != senderNode){
			//printf("\n(%d->%d)", node->number, node->back->number);
			bres = optSoln(node->back, node->number);
		}else bres = INFINITY;
		//Look to Left
		if(node->left == NULL) lres = INFINITY;
		else if(node->left != NULL && node->left->number != senderNode){
			//printf("\n(%d->%d)", node->number, node->left->number);
			lres = optSoln(node->left, node->number);
		}else lres = INFINITY;
		//Look to Right
		if(node->right == NULL) rres = INFINITY;
		else if(node->right != NULL && node->right->number != senderNode){
			//printf("\n(%d->%d)", node->number, node->right->number);
			rres = optSoln(node->right, node->number);
		}else rres = INFINITY;

		//Find min
		int min = findMin(fres, bres, lres, rres, node->opt);
		node->opt = min;
		node->optStatus ++;

		//make sure do not overflow int w/ infinity
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

	Grid* Grid::findMin(Grid *n1, Grid *n2, Grid *n3, Grid *n4, Grid *head){
		Grid *min = NULL;
		if(n1 != NULL) min = n1;
		else if(n2 != NULL) min = n2;
		else if(n3 != NULL) min = n3;
		else if(n4 != NULL) min = n4;
		else return NULL;
		if(n1 != NULL && min->opt > n1->opt && n1->opt < head->opt) min = n1;
		if(n2 != NULL && min->opt > n2->opt && n2->opt < head->opt) min = n2;
		if(n3 != NULL && min->opt > n3->opt && n3->opt < head->opt) min = n3;
		if(n4 != NULL && min->opt > n4->opt && n4->opt < head->opt) min = n4;
		return min;
	}

	void Grid::printPath(Grid *head){
		if(head == NULL) return;
		int temp = INFINITY;
		if(head->opt == temp) return;
		//Mark it as part of path
			//printf("\nChanging value of node %d to 4.", head->number);
			//if(head->type != 1)	head->type = 4;
			//Grid *next = findMin(head->front, head->back, head->right, head->left, head);
			//if (next != NULL) printf("\n(%d->%d)", head->number, next->number);
		if(head->front != NULL && head->front->opt == head->opt-1) printPath(head->front);
		else if(head->back != NULL && head->back->opt == head->opt-1) printPath(head->back);
		else if(head->left != NULL && head->left->opt == head->opt-1) printPath(head->left);
		else if(head->right != NULL && head->right->opt == head->opt-1) printPath(head->right);
		else return;
}





