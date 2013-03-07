#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
	int data;
	node *left;
	node *right;
	node *parent;
};
struct node* max (struct node* middle)
{
	while (middle->right != NULL)
		middle = middle->right;
	return middle;
}

struct node* top (struct node* bottom)
{
	while (bottom->parent != NULL)
		bottom = bottom->parent;
	return bottom;
}


struct node* min (struct node* middle)
{
	while (middle->left != NULL)
		middle = middle->left;
	return middle;
}

struct node* newNode(int datum)
{
	struct node *edon = (struct node *) malloc(sizeof(struct node));
	edon->data = datum;
	return edon;
}

//looping instead of resursing so stack doesn't topple
//balancing from the top won't work because it makes the bottom all wobbly
//is there any way to balnce from the bottom without insane overhead?

struct node* insert(struct node* node, int datum)
{
	node = top(node);
	while (node != NULL)
	{
		if (datum < node->data)
			if (node->left == NULL)
			{
				node->left = newNode(datum);
				node->left->parent=node;
				return node->left;
			}
			else
				node = node->left;

		else if (datum > node->data)
			if (node->right == NULL)
			{
				node->right = newNode(datum);
				node->right->parent = node;
				return node->right;
			}
			else
				node = node->right;

		else
			return node;
	}
	return node=newNode(datum);
}

struct node* find(struct node* start, int value)
{
	start = top(start);
	while (start != NULL)
	{
		if (value > start->data)
			start = start->right;
		else if (value < start->data)
			start = start->left;
		else
			return start;
	}
	puts("I dislike you");
}

int
main(void)
{
	struct node *n1 = newNode(500);
//	n1->right = newNode(10);
//	n1->right->parent = n1;
//	n1->left = newNode(4);
//	n1->left->parent = n1;
//	insert(n1, 7);
//	insert(n1, 9);
//	insert(n1, 3);
//	insert(n1, 6);
//	int i;
//	for (i=0; i<10000; i++)
//		insert (n1, i);

//	for (i=0; i<10000; i++)
//		printf("%i\n", find(n1,i)->data);
//	printf ("%i\n", top(n1)->left->right->data);
//	printf ("%i\n", top(n1)->left->data);
//	printf ("%i\n", top(n1)->right->right->data);
//	printf ("%i\n", top(n1)->data);

	//printf ("%i\n", n1->data);
	return 0;
}
