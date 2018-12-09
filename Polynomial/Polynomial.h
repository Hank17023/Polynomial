
typedef struct _linkedlist_{
	int coef;
	int variable;
	struct _linkedlist_ *next;
}LinkedList;

LinkedList *createList(LinkedList *list);
void addList(LinkedList *head, int coef, int variable);
void add(LinkedList *exp_head1,LinkedList *exp_head2,LinkedList *result_head);
void minus(LinkedList *exp_head1,LinkedList *exp_head2,LinkedList *result_head);
void multiply(LinkedList *exp_head1,LinkedList *exp_head2,LinkedList *result_head);
void displayList(LinkedList *head);
