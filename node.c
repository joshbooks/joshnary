#include "node.h"


struct node* max (void *arg)
{
	int s;
	node *middle = (node *)arg;

	while (middle->right != NULL)
	{
		s = pthread_mutex_lock(&middle->nodex);
		if (s != 0)
			exit(-1);

		s = pthread_cond_wait(&middle->nodify, &middle->nodex);
		if (s != 0)
			exit(-1);

		middle = middle->right;

		s = pthread_mutex_unlock(&middle->nodex);
		if (s != 0)
			exit(-1);

	}

	return middle;
}

struct node* top (void *arg)
{
	node *bottom = (node *)arg;
	while (bottom->parent != NULL)
		bottom = bottom->parent;
	return bottom;
}


struct node* min (void *arg)
{
	node *middle = (node *)arg;
	while (middle->left != NULL)
		middle = middle->left;
	return middle;
}

struct node* newNode(void *arg)
{
	int datum = (int)arg;
	node *edon = (node *) malloc(sizeof(node));
	edon->data = datum;
	pthread_cond_init(&edon->nodify, NULL);
	pthread_mutex_init(&edon->nodex, NULL);
	return edon;
}

//performs one extra check at the bottom, seems to alleviate the long-branch
//unbalanced tree a bit be nice to eliminate it, the zigzag is a little less
//significant, but it
//would be nice to deal with that too

struct node* insert(struct node* node, int datum)
{
	node = top(node);
	while (node != NULL)
	{
		if (datum < node->data)
			if (node->left == NULL)
			{
				if ( node->parent!=NULL && node->right==NULL && node->parent->right==NULL)
				{
					node->parent->right=newNode((void *)node->parent->data);
					node->parent->data = node->data;
					node->data = datum;
					return node;
				}
				else
				{
					node->left = newNode((void *)datum);
					node->left->parent=node;
					return node->left;
				}
			}
			else
				node = node->left;

		else if (datum > node->data)
			if (node->right == NULL)
			{
				if (node->parent!=NULL && node->left==NULL && node->parent->left==NULL)
				{
					node->parent->left=newNode((void *)node->parent->data);
					node->parent->data = node->data;
					node->data = datum;
					return node;
				}
				else
				{
					node->right = newNode((void *)datum);
					node->right->parent = node;
					return node->right;
				}
			}
			else
				node = node->right;

		else
			return node;
	}
}

node* find(node* start, int value)
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

//frees trees, because memory is not unlimited
//no matter what my cs teachers say;
//on that note, I waste a bunch of memory recursing :(

void clean(node* before)
{

	if (before->right != NULL)
		clean(before->right);

	if (before->left != NULL)
		clean(before->left);

		free(before);

}



//prints tree down from passed node
//probably going to wind up being very similar to
//linux tree, but a proper christmas tree appearance
//would be excellent
void treeprint(node* tree)
{
	tree = top(tree);
	
}




