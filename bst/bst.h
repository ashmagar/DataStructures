#ifndef BST_H_
#define BST_H_

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "data.h"
#include "stack.h"
#include "queue.h"



struct leaf* createLeaf(struct data *d);
struct tree* createTree();
void insertBst(struct tree *t,struct data *d);
void insertBst_r(struct leaf* current,struct leaf* newLeaf);
void inOrderBst(struct tree *t);
void inOrderBst_r(struct leaf *current);
float totalSum(struct tree *t);
float totalSum_r(struct leaf* current);
void breathFirstBst(struct tree *t); 
float bstMaxV1(struct tree* t);
float bstMaxV1_r(struct leaf* current);
float max(float a,float b,float c);
#endif
