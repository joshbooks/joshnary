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
					node->parent->right=newNode(node->parent->data);
					node->next = node->parent->right;
					node->parent->data = node->data;
					node->data = datum;
					return node;
				}
				else
				{
					node->left = newNode(datum);
					node->next = node->left;
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
					node->parent->left=newNode(node->parent->data);
					node->next = node->parent->left;
					node->parent->data = node->data;
					node->data = datum;
					return node;
				}
				else
				{
					node->right = newNode(datum);
					node->next = node->right;
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

//frees trees, because memory is not unlimited
//no matter what my cs teachers say;
//on that note, I waste a bunch of memory making the nodeNanny
//structure but it's useful if I want to do other things,
//so hopefully it's not a total waste
void clean(struct node* messy)
{
	struct node *victim;
	while(messy->next != NULL)
	{
		victim = messy->next->next;
		free(messy->next);
		messy->next = victim;
	}
	free(messy);
}


//prints tree down from passed node
//probably going to wind up being very similar to
//linux tree, but a proper christmas tree appearance
//would be excellent
void treeprint(struct node* tree)
{
	tree = top(tree);
	
}




