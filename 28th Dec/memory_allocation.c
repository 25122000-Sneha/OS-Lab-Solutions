/*Write a program to implement Linked List mamagement of memory. Also implement First Fit, Best FIt Worst Fit algorithms.
Try graphical implementation of the same.*/

#include <stdio.h>
#include <stdlib.h>

#define HOLE 0
#define OCC 1
#define HEAD 100
#define TRUE 1
#define FALSE 0

struct node
{
	int size;
  char name;
  int status;
	struct node *next;
};
struct node *newNode, *ptr, *start = NULL;
int i, diff;

void insertNode(struct node *previous, int size, int status, char name)
{
  newNode = (struct node *)malloc(sizeof(struct node));
  newNode->size = size;
  newNode->status = status;
  newNode->name = name;
  newNode->next = previous->next;
  previous->next = newNode;
}

void insert_end(struct node *start, int status, int size, char name)
{
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->status = status;
  newNode->size = size;
  newNode->name = name;
  newNode->next = NULL;

  if(start == NULL)
  {
    start = newNode;
  }
  else
  {
    ptr = start;
    while(ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = newNode;
  }
  
}

void createList()
{
  start = (struct node*)malloc(sizeof(struct node));
  start->size = 0;
  start->name = '#';
  start->status = HEAD;
  start->next = NULL;

  insert_end(start, OCC, 50, 'X');
  insert_end(start, HOLE, 75, '0');
  insert_end(start, OCC, 150, 'Y');
  insert_end(start, HOLE, 175, '0');
  insert_end(start, OCC, 300, 'Z');

  //return start;
  
}

void displayList()
{
  ptr = start;
  while(ptr!=NULL)
  {
    printf("%c:%d --> ", ptr->name, ptr->size);
    ptr = ptr->next;
  }
  printf("END\n");
}

void first_fit(int nodes[], int n)
{
  char name = 'A';
  for(i=0; i<n; i++)
  {
    ptr = start;
    while(ptr!=NULL)
    {
      if((ptr->status == HOLE) && (ptr->size >= nodes[i]))
      {
        diff = ptr->size - nodes[i];
        ptr->status = OCC;    //allocate process
        ptr->size = nodes[i];
        ptr->name = name++;
        //the remaining portion of block after allocating the process becomes hole
        if(diff != 0)   
        {
          insertNode(ptr, diff, HOLE, '0');  
        }
        break;
      }
      ptr = ptr->next;
    }
  }
  displayList();
}

void worst_fit(int nodes[], int n)
{
  struct node *maxNode = NULL;
  int maxSize;
  char name = 'A';
  for(i=0; i<n; i++)
  {
    maxSize = 0;
    ptr = start;
    //allocate the largest hole that is big enough
    while(ptr!=NULL)
    {
      if((ptr->status == HOLE) && (ptr->size >= nodes[i]) && (ptr->size >= maxSize))
      {
        maxSize = ptr->size;
        maxNode = ptr;
      }
      
      ptr = ptr->next;
    }
    diff = maxNode->size - nodes[i];
    maxNode->status = OCC;        //allocate process
    maxNode->name = name++;
    maxNode->size = nodes[i];
    //the remaining portion of block after allocating the process becomes hole
    if(diff != 0)
    {
      insertNode(maxNode, diff, HOLE, '0');
    }
  }
  displayList();
}

void best_fit(int nodes[], int n)
{
  char name = 'A';
  struct node *bestNode = start;
  for(i=0; i<n; i++)
  {
    ptr = start;
    while(ptr!=NULL)            
    {
      //allocate the process to the first hole that is larger than currently requesting process size
      if((ptr->status == HOLE) && (ptr->size >= nodes[i]))
      {
        bestNode = ptr;        
        break;
      }
      ptr = ptr->next;
    }
    ptr = bestNode->next;
    while(ptr!=NULL)
    {
      //then find whether any other hole is smaller than bestNode and allocate the process to that node
      if((ptr->status == HOLE) && (ptr->size >= nodes[i]) &&
      (ptr->size < bestNode->size)) 
      {
        bestNode = ptr;   
      }
      ptr = ptr->next;
    }
    diff = bestNode->size - nodes[i];
    bestNode->status = OCC;            //allocate process
    bestNode->size = nodes[i];
    bestNode->name = name++;
    //the remaining portion of block after allocating the process becomes hole
    if(diff != 0)
    {
      insertNode(bestNode, diff, HOLE, '0');
    }
  }
  displayList();

}


int main(int argc, char *argv[])
{
  //createList();
  //displayList();

  int no_of_nodes = argc - 1; //first arg is file name
  int nodes[argc - 1];       //argc for number of args
  for(i=0; i<no_of_nodes; i++)
  {
    nodes[i] = atoi(argv[i+1]); //atoi for string to int
                                //argv arg vector for storing args
  }
  int choice;
  while(1){
    createList();
    printf("\n\nInitially the linked list is:\n");
    displayList();
    printf("\n----------Main menu-----------");
		printf("\n1. First Fit");
		printf("\n2. Best Fit");
		printf("\n3. Worst Fit");
		printf("\n4. ---------EXIT-----------------");
		printf("\nEnter choice(1-4):");
		scanf("%d",&choice);
    switch(choice){
      case 1:
              printf("******First Fit*******\n");
              first_fit(nodes, no_of_nodes);
              break;
      case 2:
              printf("******Best Fit*******\n");
              best_fit(nodes, no_of_nodes);
              break;
      case 3:
              printf("******Worst Fit******\n");
              worst_fit(nodes, no_of_nodes);
              break;
      case 4:
              printf("******EXIT*******\n");
              exit(0);
      default:
              printf("Invalid Choice!!");
              break;
    }
  }

}

/*
~/OS-repo/28th Dec$ gcc memory_allocation.c -o memory1
~/OS-repo/28th Dec$ ./memory1 25 50 100 75


Initially the linked list is:
#:0 --> X:50 --> 0:75 --> Y:150 --> 0:175 --> Z:300 --> END

----------Main menu-----------
1. First Fit
2. Best Fit
3. Worst Fit
4. ---------EXIT-----------------
Enter choice(1-4):1
******First Fit*******
#:0 --> X:50 --> A:25 --> B:50 --> Y:150 --> C:100 --> D:75 --> Z:300 --> END


Initially the linked list is:
#:0 --> X:50 --> 0:75 --> Y:150 --> 0:175 --> Z:300 --> END

----------Main menu-----------
1. First Fit
2. Best Fit
3. Worst Fit
4. ---------EXIT-----------------
Enter choice(1-4):2
******Best Fit*******
#:0 --> X:50 --> A:25 --> B:50 --> Y:150 --> C:100 --> D:75 --> Z:300 --> END


Initially the linked list is:
#:0 --> X:50 --> 0:75 --> Y:150 --> 0:175 --> Z:300 --> END

----------Main menu-----------
1. First Fit
2. Best Fit
3. Worst Fit
4. ---------EXIT-----------------
Enter choice(1-4):3
******Worst Fit******
#:0 --> X:50 --> D:75 --> Y:150 --> A:25 --> B:50 --> C:100 --> Z:300 --> END


Initially the linked list is:
#:0 --> X:50 --> 0:75 --> Y:150 --> 0:175 --> Z:300 --> END

----------Main menu-----------
1. First Fit
2. Best Fit
3. Worst Fit
4. ---------EXIT-----------------
Enter choice(1-4):4
******EXIT*******
~/OS-repo$
*/
