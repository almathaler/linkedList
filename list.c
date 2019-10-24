#include <stdlib.h>
#include <stdio.h>
#include "list.h"
//NOTE: BASE NODE SHOULD HAVE POINTER POINTING TO NULL
//Should take a pointer to a node struct and print out all of the data in the list
void print_list(struct node *pointer){
  if (pointer == 0){ //if it's an empty list
    printf("[]");
  }else{
    printf("[%d", pointer->data); //print the first value. But if the list is empty, just print "[]"
    pointer = pointer->next; //set the current node to be the next
    while(pointer != 0){
      printf(", %d", pointer->data);
      pointer = pointer->next;
    }
    printf("]");
  }
}
/*
Should take a pointer to the existing list and the data to be added, create a new node and put it at the beginning of the list.
The second argument should match whatever data you contain in your nodes.
Returns a pointer to the beginning of the list.
*/
struct node * insert_front(struct node *pointer, int data){
  struct node *first;
  first = malloc(sizeof(struct node)); //make a space for this new node
  first->data = data; //fill up this new node
  first->next = pointer;
  return first; //return node
}
/*
Should take a pointer to a list as a parameter and then go through the entire list
freeing each node and return a pointer to the beginning of the list (which should be NULL by then).
*/
struct node * free_list(struct node *pointer){
  while (pointer->next != 0){ //while there is a node next to it
    free_list(pointer->next); //go to the next node to free it
  }
  //base case
  free(pointer); //empty this space
  return pointer;
}
