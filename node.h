#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct node node;
struct node
{
	int data;
	node *left;
	node *right;
	node *parent;
	pthread_cond_t nodify;
	pthread_mutex_t nodex;
};

struct node* max(struct node*);

struct node* min(struct node*);

struct node* top(struct node*);

struct node* newNode(int);

struct node* insert(struct node*, int);

struct node* find(struct node*, int);

void clean(struct node*);
