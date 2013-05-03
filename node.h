/*Copyright 2013 Joshua Hight
* Kopimi*/
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


node* max(struct node*);

node* min(struct node*);

node* top(struct node*);

node* newNode(int);

node* insert(struct node*, int);

node* find(struct node*, int);

void clean(struct node*);
