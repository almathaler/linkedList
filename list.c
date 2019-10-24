#include <stdlib.h>
#include <stdio.h>
#include "list.h"
//NOTE: BASE NODE SHOULD HAVE POINTER POINTING TO NULL
//Should take a pointer to a node struct and print out all of the data in the list
void print_list(struct node *pointer){
  if (pointer == NULL){ //if it's an empty list
    printf("[]\n");
  }else{
    printf("[%d", pointer->data); //print the first value. But if the list is empty, just print "[]"
    pointer = pointer->next; //set the current node to be the next
    while(pointer != NULL){
      printf(", %d", pointer->data);
      pointer = pointer->next;
    }
    printf("]\n");
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
  //base case
  if (pointer->next == NULL){
    printf("freeing %p\n", &pointer);
    free(pointer); //empty this space
    printf("making %p null\n", &pointer);
    pointer = NULL;
    printf("pointer: %p\n", pointer);
  }else{
    printf("not yet going to free: %p\n", &pointer);
    free_list(pointer->next); //go to the next node to free it
    printf("freeing %p\n", &pointer);
    free(pointer);
    printf("making %p null\n", &pointer);
    pointer = NULL;
    printf("pointer: %p\n", pointer);
  }
  return pointer;
}
