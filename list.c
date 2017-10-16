#include <stdlib.h>
#include <stdio.h>

struct node{
  int i;
  struct node * next;
};

void print_list(struct node *n){
  while (n -> next){
    printf("%d\n", n->i);
    n = n->next;
  }
  printf("%d\n", n->i);
}

struct node * insert_front(struct node *n, int val){

  struct node *new = (struct node *)malloc(sizeof(struct node));

  new->i = val;
  new->next = n;
  
  return new;
}

struct node *free_list(struct node *n){

  struct node *cpy = n;
  struct node *prev = calloc(1,sizeof(struct node));
  while(n -> next){
    prev = n;
    n = prev -> next;
    free(prev);
  }
  free(n);
  return cpy;
}

int main(){

  struct node *test = (struct node *)malloc(sizeof(struct node));

  test->i = 3; //added 3 to list
  test->next = NULL;

  printf("\ntesting print_list:\n");
  
  print_list(test);
  
  printf("\nadding 5 to beginning of list:\n");
  test = insert_front(test, 5);
  print_list(test);


  printf("\ntesting free_list:\n");
  free_list(test);
  print_list(test);
  
}
