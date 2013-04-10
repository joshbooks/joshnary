#include "node.h"


node* max (node* middle)
{
	while (middle->right != NULL)
		middle = middle->right;
	return middle;
}

node* top (node* bottom)
{
	while (bottom->parent != NULL)
		bottom = bottom->parent;
	return bottom;
}


node* min (node* middle)
{
	while (middle->left != NULL)
		middle = middle->left;
	return middle;
}

node* newNode(int datum)
{
	node *edon = (node *) malloc(sizeof(node));
	edon->data = datum;
	return edon;
}

//performs one extra check at the bottom, seems to alleviate the long-branch
//unbalanced tree a bit be nice to eliminate it, the zigzag is a little less
//significant, but it
//would be nice to deal with that too

node* insert(node* node, int datum)
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
				if (node->parent!=NULL && node->left==NULL && node->parent->left==NULL)
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




