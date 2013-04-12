#include "node.h"


int
main(void)
{

	int s;
	pthread_t t1, t2, t3;
	void *mess, *mess1, *mess2;
	node *messy;

	s = pthread_create(&t3, NULL, newNode, (void *)5);
	if (s != 0)
		exit(-1);

	s = pthread_join(t3, &mess2);
	if (s != 0)
		exit(-1);

	node *n1 = (node *)mess2;

//inserting a bunch sequentially is a great way to unbalance
//or create race conditions now that we're being all thready
	int i;
	struct nodint *inserter = calloc(10000, sizeof(struct nodint));


	pthread_t *tarry = calloc(10000, sizeof(pthread_t));

	for (i=0; i<10000; i++)
	{
	inserter[i].tree = n1;
	inserter[i].data = i;
	s = pthread_create(&tarry[i], NULL, insert, (void *)&inserter[i]);
	if (s != 0)
		exit(-1);
	}


//	treeprint(n1);
//if I can print all this crap it's a useful print function

//make sure I haven't screwed up tree structure
	for (i=0; i<10000; i++)
		printf("%i\n", find(n1, i)->data);


//create threads to do stuff
	s = pthread_create(&t1, NULL, max, n1);
	if (s != 0)
		exit(-1);

	s = pthread_create(&t2, NULL, min, n1);
	if (s != 0)
		exit(-1);

//join, cast, and print
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
