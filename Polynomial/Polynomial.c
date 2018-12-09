#include <stdio.h>
#include <stdlib.h>
#include "Polynomial.h"

LinkedList *createList(LinkedList *list){
	list = (LinkedList*)malloc(sizeof(LinkedList));
	list->next=NULL;
	return list;
}

void addList(LinkedList *head, int coef, int variable){
	LinkedList *prev = head;
	LinkedList *node = head->next;
	while(node!=NULL){
		if(variable > node->variable){
			LinkedList *temp = createList(temp);
			temp->coef = coef;
			temp->variable = variable;
			temp->next = prev->next;
			prev->next = temp;
			return;
		}
		else if(variable < node->variable ){
			prev = node;
			node = node->next;
		}
		else{
			node->coef+=coef;
			return;
		}
	}
	node = createList(node);
	node->coef = coef;
	node->variable = variable;
	prev->next = node;
}

void add(LinkedList *exp_head1,LinkedList *exp_head2,LinkedList *result_head){
	LinkedList *exp1 = exp_head1->next;
	LinkedList *exp2 = exp_head2->next;
	while(exp1){
		addList(result_head,exp1->coef,exp1->variable);
		exp1 = exp1->next;
	}
	while(exp2){
		addList(result_head,exp2->coef,exp2->variable);
		exp2 = exp2->next;
	}
}

void minus(LinkedList *exp_head1,LinkedList *exp_head2,LinkedList *result_head){
	LinkedList *exp2 = exp_head2->next;
	while(exp2){
		exp2->coef = -exp2->coef;
		exp2 = exp2->next;
	}
	add(exp_head1,exp_head2,result_head);
}

void multiply(LinkedList *exp_head1,LinkedList *exp_head2,LinkedList *result_head){
	LinkedList *exp1 = exp_head1->next;
	LinkedList *exp2 = exp_head2->next;
	while(exp1){
		while(exp2){
			addList(result_head,exp1->coef*exp2->coef,exp1->variable+exp2->variable);
			exp2 = exp2->next;
		}
		exp1 = exp1->next;
		exp2 = exp_head2->next;
	}
}

void displayList(LinkedList *head){
	LinkedList *node = head->next;
	while(node!=NULL){
		node->coef<0 ? printf("%dx^%d",node->coef,node->variable) 
					 : printf("+%dx^%d",node->coef,node->variable);
		node = node->next;
	}
	printf("\n");

}
