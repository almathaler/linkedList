#ifndef list_h
#define list_h
//nodes
struct node{ int data;
             struct node *next;
           };
//printing list
void print_list(struct node *pointer);
//add to the front
struct node * insert_front(struct node *pointer, int data);
//free list
struct node * free_list(struct node *pointer);
//remove
struct node * remove(struct node *front, int data);
#endif
