#include "dlinklist.h"


struct dlinklist* createlinklist()
{
  struct dlinklist* ll = malloc(sizeof(struct dlinklist));
  ll->head = NULL;
  ll->tail = NULL;
  return ll;
}


struct node* createNode(struct data *d)
{
  struct node *n = malloc(sizeof(struct node));
  n->d = d;
  n->next = NULL;
  n->prev = NULL;
  return n;
}


void addFront(struct dlinklist *ll,struct data *d)
{
	struct node *nTemp = createNode(d);
	if(ll->head==NULL && ll->tail==NULL)
	{
		ll->head = nTemp;
		ll->tail = nTemp;
	}
	else
	{
		nTemp->next = ll->head;
		ll->head->prev = nTemp;
		ll->head = nTemp;
	}
}

void printList(struct dlinklist *ll)
{
	struct node* temp = ll->head;
	while(temp!=NULL)
	{
		printData(temp->d);
		temp = temp->next;
	}
}

void printBackwards(struct dlinklist *ll)
{
	struct node* temp = ll->tail;
	while(temp != NULL)
	{
		printData(temp->d);	
		temp = temp->prev;
	}
}
