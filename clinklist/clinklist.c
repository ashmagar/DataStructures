#include "clinklist.h"

struct clinklist* createlinklist()
{
  struct clinklist* ll = malloc(sizeof(struct clinklist));
  ll->head = NULL;
  return ll;
}

struct node* createNode(struct data *d)
{
  struct node* n = malloc(sizeof(struct node));
  n->d = d;
  n->next = NULL;
  return n;
}

void addFront(struct clinklist *ll,struct data *d)
{
	struct node *tNode = createNode(d);
	if(ll->head==NULL)
	{
		ll->head = tNode;
		tNode->next = ll->head;
	}
	else
	{
		struct node* temp = ll->head;
		tNode->next = ll->head;
		while(temp->next!=ll->head)
		{
			temp = temp->next;
		}
		temp->next = tNode;
		ll->head = tNode;
	}
}

void addBack(struct clinklist *ll,struct data* d)
{
	struct node* n = createNode(d);
	struct node* temp = ll->head->next;
	while(temp->next != ll->head)
	{
		temp = temp->next;
	}
	temp->next  = n;
	n->next = ll->head;
}

void printList(struct clinklist *ll)
{
	if(ll->head == NULL) return;

	printData(ll->head->d);
	if(ll->head->next!=NULL)
	{
		struct node* temp = ll->head->next;
		while(temp!=ll->head)
		{
			printData(temp->d);
			temp=temp->next;
		}
	}
}
