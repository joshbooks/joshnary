#include "node.h"

int
main(void)
{
	int s;
	pthread_t t1, t2;
	void *mess, *mess1;
	node *messy;
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
//	for (i=0; i<10000; i++)
//		printf("%i\n", find(n1, i)->data);




	s = pthread_create(&t1, NULL, max, n1);
	if (s != 0)
		exit(-1);

	s = pthread_create(&t2, NULL, top, n1);
	if (s != 0)
		exit(-1);


	s = pthread_join(t1, &mess);
	if (s != 0)
		exit(-1);

	messy = (node *) mess;
	printf ("%i\n", (node *)messy->data);


	s = pthread_join(t2, &mess1);
	if (s != 0)
		exit(-1);

	messy = (node *) mess1;
	printf ("%i\n", (node *)messy->data);

	clean(n1);
	return 0;
}
