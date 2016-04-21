#include "dlinklist.h" 
#include<assert.h>
 
void cleanList(struct dlinklist*);

int main(int argc, char* argv[])
{

	struct dlinklist* myLl = createlinklist();
	struct data* myDta;
	int i=0;

	if((argc == 1) || (argc%2==0))  //need odd number of arguments
	{
		return -1;
	}

	for(i=1;i<argc;i+=2)
	{
		assert((i+1) < argc);
		myDta = createData(atof(argv[i]),atof(argv[i+1]));
		addFront(myLl,myDta);
	}

	printList(myLl);
	printf("\n");
	printBackwards(myLl);
	cleanList(myLl);
	return 0;
}

void cleanList(struct dlinklist* ll)
{
	struct node* temp = ll->head;

	while(ll->head != NULL)
	{
		temp = ll->head;
		ll->head = ll->head->next;	
		free(temp->d);
		free(temp);
	}	
	free(ll);
}
