#include "node.h"

int
main(void)
{
	struct node *n1 = newNode(5);
//	printf ("%i", insert(n1, 5)->data);
//	n1->right = newNode(10);
//	n1->right->parent = n1;
//	n1->left = newNode(4);
//	n1->left->parent = n1;
//	insert(n1, 9);
//	insert(n1, 7);
//	insert(n1, 3);
//	insert(n1, 6);
//inserting a bunch sequentially is a great way to unbalance
	int i;
	for (i=0; i<10000; i++)
		insert (n1, i);
//if I can print all this crap it's a useful print function
//	treeprint(n1);

//make sure I haven't screwed up tree structure
//	for (i=0; i<10000; i++)
//		printf("%i\n", find(n1, i)->data);
//	printf ("%i\n", top(n1)->left->right->data);
//	printf ("%i\n", top(n1)->left->data);
	printf (" %i\n", top(n1)->right->data);
	printf ("%i\n", top(n1)->right->right->left->data);

//	printf ("%i\n", n1->left->right->data);
//	printf ("%i\n", n1->left->data);
//	printf ("%i\n", n1->data);
//	printf ("%i\n", n1->right->data);
	return 0;
}
