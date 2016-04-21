#ifndef _CLINKLIST_H_
#define _CLINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "data.h"


struct node
{
  struct node *next;
  struct data *d;
};

struct clinklist
{
  struct node *head;
};

//reserve space for a new clinklist, set initial variables, and return clinklist
struct clinklist* createlinklist();
//reserve space for new node, set variables and return
struct node* createNode(struct data *d);
//create a new node, set the data pointer, and add to front of clinklist
void addFront(struct clinklist *ll,struct data *d);
//create a new node, set the data pointer, and add to back of clinklist
void addBack(struct clinklist *ll,struct data *d);
//print values in the data structures in the clinklist
void printList(struct clinklist *ll);

#endif
