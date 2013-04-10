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

struct node* max(void *);

struct node* min(void *);

struct node* top(void *);

struct node* newNode(void *);

struct node* insert(struct node*, int);

struct node* find(struct node*, int);

void clean(struct node*);
