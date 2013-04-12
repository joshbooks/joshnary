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

typedef struct nodint nodint;
struct nodint
{
	node* tree;
	int data;
};

void* max(void *);

void* min(void *);

void* top(void *);

void* newNode(void *);

void* insert(void *);

node* find(struct node*, int);

void clean(struct node*);
