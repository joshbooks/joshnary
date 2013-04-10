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

struct tzwrytcvhbixtzyrtuuvuxrzdc

struct node* max(struct node*);

struct node* min(struct node*);

struct node* top(struct node*);

struct node* newNode(int);

struct node* insert(struct node*, int);

struct node* find(struct node*, int);

void clean(struct node*);
