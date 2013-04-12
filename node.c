#include "node.h"


void *
max (void *arg)
{
	node *middle = (node *)arg;

	while (middle->right != NULL)
		middle = middle->right;

	return (void *)middle;
}

void *
top (void *arg)
{
	node *bottom = (node *)arg;

	while (bottom->parent != NULL)
		bottom = bottom->parent;

	return (void *)bottom;
}


void
*min (void *arg)
{
	node *middle = (node *)arg;

	while (middle->left != NULL)
		middle = middle->left;

	return (void *)middle;
}

void *
newNode(void *arg)
{
	node *edon = (node *) malloc(sizeof(node));
	edon->data = (int)arg;
	pthread_cond_init(&edon->nodify, NULL);
	pthread_mutex_init(&edon->nodex, NULL);
	return (void *)edon;
}

//performs one extra check at the bottom, seems to alleviate the long-branch
//unbalanced tree a bit be nice to eliminate it, the zigzag is a little less
//significant, but it
//would be nice to deal with that too

void *
insert(void *arg)
{

	int s;
	struct nodint *stuff = (struct nodint *)arg;
	node *node = stuff->tree;
	int datum = stuff->data;
	printf("%i\n", datum);
	node = top(node);
	while (node != NULL)
	{
		if (datum < node->data)
			if (node->left == NULL)
			{
				if ( node->parent!=NULL && node->right==NULL && node->parent->right==NULL)
				{
					s = pthread_mutex_lock(&node->parent->nodex);
					if (s != 0)
						exit(s);

					node->parent->right=newNode((void *)node->parent->data);
					node->parent->data = node->data;
					node->data = datum;

					s = pthread_mutex_unlock(&node->parent->nodex);
					if (s != 0)
						exit(s);

					return node;
				}
				else
				{

					s = pthread_mutex_lock(&node->nodex);
					if (s != 0)
						exit(s);

					node->left = newNode((void *)datum);
					node->left->parent=node;

					s = pthread_mutex_unlock(&node->nodex);
					if (s != 0)
						exit(s);

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

					s = pthread_mutex_lock(&node->parent->nodex);
					if (s != 0)
						exit(s);

					node->parent->left=newNode((void *)node->parent->data);
					node->parent->data = node->data;
					node->data = datum;

					s = pthread_mutex_unlock(&node->parent->nodex);
					if (s != 0)
						exit(s);

					return node;
				}
				else
				{

					s = pthread_mutex_lock(&node->nodex);
					if (s != 0)
						exit(s);

					node->right = newNode((void *)datum);
					node->right->parent = node;

					s = pthread_mutex_unlock(&node->nodex);
					if (s != 0)
						exit(s);

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




