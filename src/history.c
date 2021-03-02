#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  List *list = malloc(sizeof(List));
  list -> root = malloc(sizeof(Item))
    return list;
}

List add_History()
{
  int id = 1;
  Item *temp = list-> root;

  while(temp -> next != 0){
    temp = temp ->next;
    id++;
  }
}
