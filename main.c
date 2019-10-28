#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(){
  struct node *p = NULL; //empty
  printf("made an empty list, here is how it looks: \n");
  print_list(p);
  //
  printf("now going to add numbers 12 to 18: \n");
  int i;
  //shouldn't reassign p everytime, then you'll lose it. so make a new placeholder POINTER
  //actually, just need pointer to front. so no need for iterator
  struct node *iterator = p;
  for (i = 12; i<19; i++){
    printf("adding %d\n", i);
    iterator = insert_front(iterator, i);
  }
  //print list again
  printf("printing list again, should look like: [18, 17, 16, 15, 14, 13, 12]: \n");
  print_list(iterator);
  //now remove the number 16 and print
  printf("now going to remove 16\n");
  iterator = listRemove(iterator, 16);
  printf("just removed 16, reprinting: \n");
  print_list(iterator);
  printf("going to try removng 10:\n");
  iterator = listRemove(iterator, 10);
  printf("'removed' 10, reprinting:\n");
  print_list(iterator);
  //now free the list and reprint
  printf("freeing the list, then will reprint: \n");
  iterator = free_list(iterator);
  print_list(iterator);
  printf("going to try rebuilding list w same pointer:\n");
  for (i = 20; i<27; i++){
    printf("adding %d\n", i);
    iterator = insert_front(iterator, i);
  }
  printf("the list now: ");
  print_list(iterator);
  printf("removing 20:\n");
  iterator = listRemove(iterator, 20);
  print_list(iterator);
  printf("removing 26:\n");
  iterator = listRemove(iterator, 26);
  print_list(iterator);
  printf("freeing all\n");
  iterator=free_list(iterator);
  return 0;
}
