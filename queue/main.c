#include "queue.h"
#include<assert.h>

int main(int argc, char* argv[])
{
	if( (argc==1)|| (argc-1)%2!=0 ) 
	{
		return -1;
	}
	struct queue *myQ = createQueue();
	struct data* myDta = NULL;
	int i=0;
	for(i=1;i<argc;i+=2)
	{
		assert(i+1<argc);
		myDta = createData( atof(argv[i]), atof(argv[i+1]) );
		pushQueue(myQ,myDta);
		printf("\npush()\n");
	}
	printQueue(myQ);

	popQueue(myQ);
	printf("\npop()\n");
	printQueue(myQ);

	popQueue(myQ);
	printf("\npop()\n");
	printQueue(myQ);

	myDta= createData(44.44,55.55);
	pushQueue(myQ,myDta);
	printf("\npush()\n");
	printQueue(myQ);

	cleanQueue(myQ);

  
  return 0;
}
