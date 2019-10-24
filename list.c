#include <stdlib.h>
#include <stdio.h>
#include "list.h"
void printNode(struct node *pointer){
  printf("{at: %p, next: %p, data: %d}\n", pointer, pointer->next, pointer->data);
}
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
  printf("added this node: ");
  printNode(first);
  return first; //return node
}
/*
Should take a pointer to a list as a parameter and then go through the entire list
freeing each node and return a pointer to the beginning of the list (which should be NULL by then).
*/
struct node * free_list(struct node *pointer){
  //base case
  if (pointer->next == NULL){
    printf("freeing base: ");
    printNode(pointer);
    free(pointer); //empty this space
    pointer = NULL;
  }else{
    printf("not yet at bottom, am here: ");
    printNode(pointer);
    free_list(pointer->next); //go to the next node to free it
    printf("freeing: ");
    printNode(pointer);
    free(pointer);
    pointer = NULL;
  }
  return pointer;
}
/*
Remove the node containing data from the list pointed to by front.
If data is not in the list, nothing is changed.
Returns a pointer to the beginning of the list.
*/
struct node * listRemove(struct node *front, int data){
  //go thru list to find data, keep previous node in a POINTER/
  //once you find the first instance of data, assign previous node.next = this.next
  //then free current POINTER
  //return front, which should be untouched
  struct node *iterator = front;
  struct node *behindIterator;
  while(iterator != NULL){
    if(iterator->data == data){
      printf("found data! removing at ");
      printNode(iterator);
      behindIterator->next = iterator->next;
      free(iterator);
      iterator = NULL; //so the while loop stops
      printf("now the surrounding pointers look like: ");
      printNode(behindIterator);
      printNode(behindIterator->next);
    }else{
      behindIterator = iterator;
      iterator = iterator->next;
    }
  }
  return front;
}
