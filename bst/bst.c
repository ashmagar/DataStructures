#include "bst.h"
#include<float.h>

struct leaf* createLeaf(struct data *d)
{
  struct leaf* maple = malloc(sizeof(struct leaf));
  maple->right = NULL;
  maple->left = NULL;
  maple->dta = d;
  return maple;
}

struct tree* createTree()
{
  struct tree* oak = malloc(sizeof(struct tree));
  oak->root = NULL;
  return oak;
}


void insertBst(struct tree *t,struct data *d)
{
  	struct leaf *l = createLeaf(d);
  	if(t->root == NULL)
	{
		 t->root = l;	
		 return;
	}

	insertBst_r(t->root,l);
}

void insertBst_r(struct leaf* current,struct leaf* newLeaf)
{
	if(sumData(newLeaf->dta) <= sumData(current->dta))
	{
		if(current->left==NULL)
		{
			current->left = newLeaf;
		}
		else
		{
			insertBst_r(current->left,newLeaf);
		}
	}
	else if(sumData(newLeaf->dta) > sumData(current->dta))
	{
		if(current->right==NULL)
		{
			current->right = newLeaf;
		}
		else
		{
			insertBst_r(current->right,newLeaf);
		}
	}
}

void inOrderBst(struct tree *t)
{
	inOrderBst_r(t->root);
}
void inOrderBst_r(struct leaf *current)
{
	if (current->left != NULL)
	{
		inOrderBst_r(current->left);
	}
	printData(current->dta);
	if(current->right != NULL)
	{
		inOrderBst_r(current->right);
	}
}

float totalSum(struct tree *t)
{
	return totalSum_r(t->root);
}

float totalSum_r(struct leaf* current)
{
	if(current==NULL)
	{
		return 0;
	}
	return ( totalSum_r(current->left) + totalSum_r(current->right) + sumData(current->dta) );

}


float bstMaxV1(struct tree *t)
{
	return (bstMaxV1_r(t->root));
}

float bstMaxV1_r(struct leaf *current)
{
	if(current==NULL)
	{
		return -(FLT_MAX);
	}

	return max( (current->dta->v1) , bstMaxV1_r(current->left) , bstMaxV1_r(current->right) );

}

float max(float a, float b, float c)
{

	if(a>b && a>c)
	{
		return a;
	}

	return b > c ? b : c;

}
