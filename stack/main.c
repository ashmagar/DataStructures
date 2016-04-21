#include "stack.h"
#include<assert.h>

int main(int argc, char* argv[])
{
	if( (argc==1)|| (argc-1)%2!=0 ) 
	{
		return -1;
	}

	struct stack *myS = createStack();
	struct data* myDta = NULL;
	int i=0;
	for(i=1;i<argc;i+=2)
	{
		assert(i+1<argc);
		myDta = createData( atof(argv[i]), atof(argv[i+1]) );
		pushStack(myS,myDta);
		printf("\npush()\n");
	}
	printStack(myS);

	popStack(myS);
	printf("\npop()\n");
	printStack(myS);

	popStack(myS);
	printf("\npop()\n");
	printStack(myS);

	myDta= createData(44.44,55.55);
	pushStack(myS,myDta);
	printf("\npush()\n");
	printStack(myS);

	cleanStack(myS);
  return 0;
}
