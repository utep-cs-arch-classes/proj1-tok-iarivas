#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  List *list = malloc(sizeof(List));
  list -> root = malloc(sizeof(Item));
    return list;
}

void add_history(List *list, char *str)
{
  int count = 1;
  Item *temp = list-> root;

  while(temp ->next != 0){
    temp = temp ->next;
    count++;
  }

  temp -> next = malloc(sizeof(Item));
  temp -> next -> str = copy_str(str, 5);
  temp -> next -> id = count;
}

char *get_history(List *list, int id)
{
  if(!list){ return '\0'; }
  else{
    Item *temp = list -> root;
    while(temp){
      if(temp -> id == id){ return temp -> str; }
      temp = temp -> next;
    }
  }
  return "Empty.\n";
}

void free_history(List *list)
{
  Item *temp = list -> root;
  while(temp -> next){
    Item *temp2 = temp;
    free(temp2 -> str);
    free(temp2);
  }
  free(temp -> str);
  free(temp);
  free(list);
}

void print_history(List *list)
{
  if(!list){ printf("List is empty.\n"); }
  else{
    Item *temp = list -> root;
    while(temp){
      printf("%d: %s\n", temp -> id, temp -> str);
      temp = temp -> next;
    }
    printf("\n");
  }
}







