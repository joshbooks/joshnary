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

void* max(void *);

void* min(void *);

void* top(void *);

node* newNode(void *);

node* insert(struct node*, int);

node* find(struct node*, int);

void clean(struct node*);
