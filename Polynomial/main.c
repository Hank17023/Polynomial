#include <stdio.h>
#include <stdlib.h>
#include "Polynomial.h"

int main(int argc, char *argv[]) {
	LinkedList *exp1, *exp2, *result;
	exp1 = createList(exp1);
	exp2 = createList(exp2);
	result = createList(result);
	
	addList(exp1,2,0);
	addList(exp1,1,1);
	addList(exp1,3,3);
	addList(exp1,4,2);
	displayList(exp1);

	addList(exp2,4,4);
	addList(exp2,1,0);
	addList(exp2,2,1);
	addList(exp2,2,2);
	displayList(exp2);
	
	// add(exp1,exp2,result);
	// minus(exp1,exp2,result);
	multiply(exp1,exp2,result);
	displayList(result);
	return 0;
}
