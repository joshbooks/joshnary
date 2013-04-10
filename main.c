#include "node.h"

int
main(void)
{
	node *n1 = newNode(5);
//	printf ("%i", insert(n1, 5)->data);
//inserting a bunch sequentially is a great way to unbalance
	int i;
	for (i=0; i<10000; i++)
		insert (n1, i);
//	printf ("%i", min(n1)->data);
//	printf ("%i", min(n1)->right->data);
//	printf ("%i", min(n1)->parent->data);

	clean(n1);
//if I can print all this crap it's a useful print function
//	treeprint(n1);
//make sure I haven't screwed up tree structure
//	for (i=0; i<10000; i++)
//		printf("%i\n", find(n1, i)->data);
	return 0;
}
