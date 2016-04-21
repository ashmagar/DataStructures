
#include "linkedList.h"

struct node* createNode(struct data *dta)
{
	struct node* nod = malloc(sizeof(struct node));
	nod->dta = dta;
	nod->next = NULL;
	return nod;
}

struct linkedList* createLinkedList()
{
	struct linkedList *ll = malloc(sizeof(struct linkedList));
	ll->head = NULL;
	return ll;
}

void addFront(struct linkedList *ll,struct data *dta)
{
	struct node* tempNode = createNode(dta);
	if(ll->head == NULL)
	{
		ll->head = tempNode;
	}
	else
	{
		tempNode->next = ll->head;
		ll->head = tempNode;
	}

}

void removeFront(struct linkedList *ll)
{
//case 1: Linked list is empty
        if(ll->head == NULL) return;

//case 2: linked list contains only 1 element
	struct node *temp  = ll->head;
	 if(temp->next==NULL)
        {
                free(temp->dta);
                free(temp);
                ll->head = NULL;
                return;
        }

//case 3: Linked list contains more than 1 elements
	if(ll->head->next!=NULL)
	{
		 ll->head = ll->head->next;
	}
	free(temp->dta);
	free(temp);

}

void removeBack(struct linkedList *ll)
{
//case 1: Linked list is empty
	if(ll->head == NULL) return;

//case 2: linked list contains only 1 element
	struct node *temp = ll->head;
	if(temp->next==NULL)
	{
		free(temp->dta);
		free(temp);
		ll->head = NULL;
		return;
	}

//case 3: Linked list contains more than 1 elements
	while(temp->next->next!=NULL)
	{
		temp = temp->next;
	}

	free(temp->next->dta);
	free(temp->next);
	temp->next = NULL;
}

int searchLinkedList(struct linkedList *ll,struct data *dta)
{
//case 1: Linked list is empty
        if(ll->head == NULL) return 0;
//else
	struct node* temp = ll->head;
	while(temp->next!=NULL)
	{
		if(compareData(dta,temp->dta) == 1)
		{
			return 1;
		}
		temp = temp->next;
	}
	return 0;


}


void printLinkedList(struct linkedList *ll)
{
	struct node *nodeTemp = ll->head;
	while(nodeTemp != NULL)
	{
		printData(nodeTemp->dta);
		nodeTemp = nodeTemp->next;
	}

}
