#include "node.h"

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

//performs one extra check at the bottom, seems to eliminate the long-branch
//unbalanced tree, the zigzag is a little less significant, but it
//would be nice to deal with that too

struct node* insert(struct node* node, int datum)
{
	node = top(node);
	while (node != NULL)
	{
		if (datum < node->data)
			if (node->left == NULL)
			{
				if (node->right==NULL && node->parent->right==NULL)
				{
					node->parent->right=newNode(node->parent->data);
					node->parent->data = node->data;
					node->data = datum;
					return node;
				}
				else
				{
					node->left = newNode(datum);
					node->left->parent=node;
					return node->left;
				}
			}
			else
				node = node->left;

		else if (datum > node->data)
			if (node->right == NULL)
			{
				if (node->left==NULL && node->parent->left==NULL)
				{
					node->parent->left=newNode(node->parent->data);
					node->parent->data = node->data;
					node->data = datum;
					return node;
				}
				else
				{
					node->right = newNode(datum);
					node->right->parent = node;
					return node->right;
				}
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
	struct node *n1 = newNode(5);

//	printf ("%i", insert(n1, 5)->data);
	n1->right = newNode(10);
	n1->right->parent = n1;
	n1->left = newNode(4);
	n1->left->parent = n1;
//	insert(n1, 9);
//	insert(n1, 7);
//	insert(n1, 3);
//	insert(n1, 6);
	int i;
	for (i=0; i<10000; i++)
		insert (n1, i);

//	for (i=0; i<10000; i++)
//		printf("%i\n", find(n1, i)->data);
//	printf ("%i\n", top(n1)->left->right->data);
//	printf ("%i\n", top(n1)->left->data);
	printf ("%i\n", top(n1)->data);
	printf ("%i\n", top(n1)->right->data);
	printf ("%i\n", top(n1)->right->right->right->data);
	printf ("%i\n", top(n1)->right->right->left->data);
	return 0;
}
