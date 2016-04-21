#include "linkedList.h"
#include<assert.h>

void cleanLinkedList(struct linkedList*);

int main(int argc, char* argv[])
{
	if( (argc == 1) || ((argc-1)%2 != 0))
	{
		return -1;
	}
	struct data *myDta = NULL;
//	struct data *myDta = createData(1.1,2.2);
	//struct node *myNode = createNode(myDta);
	struct linkedList *myLl = createLinkedList();
//	addFront(myLl,myDta);

	int i = 0;
	for(i=1;i<argc;i+=2)
	{
		assert(i + 1 < argc);	//make sure within bound
		myDta = createData(atof(argv[i]),atof(argv[i+1]));
		addFront(myLl,myDta);
	}
//	removeFront(myLl);
//	removeBack(myLl);
	printLinkedList(myLl);
	myDta = createData(5.5,6.6);
	printf("%d\n\n",searchLinkedList(myLl,myDta));	
	free(myDta);

	cleanLinkedList(myLl);

  return 0;
}


void cleanLinkedList(struct linkedList* ll)
{
	struct node *temp = ll->head;
	while(ll->head != NULL)
	{
		temp = ll->head;
		ll->head = ll->head->next;
		free(temp->dta);
		free(temp);
	}
	free(ll);
}
