#include <stdio.h>
#include<assert.h>
#include "structures.h"
#include "bst.h"

int main(int argc,char* argv[])
{
	if(argc==1 || argc%2==0)
	{
		return -1;
	}
	int i=0;
	struct data* myDta = NULL;
	struct tree* myT = createTree();
	for(i=1;i<argc;i+=2)
	{
		assert(i+1<argc);
		myDta = createData(atof(argv[i]),atof(argv[i+1]));
		insertBst(myT,myDta);
	}
	inOrderBst(myT);
	printf("%f\n",totalSum(myT));
	printf("%f\n",bstMaxV1(myT));

  return 0;

}
