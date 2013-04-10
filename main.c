#include "node.h"

int
main(void)
{
//	int init = 5;
	struct node *n1 = newNode((void *)5);


//inserting a bunch sequentially is a great way to unbalance
	int i;
	for (i=0; i<10000; i++)
		insert (n1, i);
//	printf ("%i", min(n1)->data);
//	printf ("%i", min(n1)->right->data);
//	printf ("%i", min(n1)->parent->data);

//if I can print all this crap it's a useful print function
//	treeprint(n1);
//make sure I haven't screwed up tree structure
	for (i=0; i<10000; i++)
		printf("%i\n", find(n1, i)->data);

//	node *maximus = (node *)max((void *) n1);

	printf ("%i", max(n1)->data);

	clean(n1);
	return 0;
}
