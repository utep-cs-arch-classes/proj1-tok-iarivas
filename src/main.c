#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#define LIMIT 100
char arr[LIMIT];


int main()
{
  char input[LIMIT];
  List *History = init_history();
  goto Options;
 Options:
  printf("Select an option below.\n");
  printf("Input 'i' to input a sentence.\n");
  printf("Input 'h' to view history.\n");
  printf("Input '!' and a number to get a specific token from history.\n");
  printf("Input 'q' to exit program.\n");
  printf(">");
  fgets(input, LIMIT, stdin);
  if(input[0] == 'i'){ goto input; }
  else if(input[0] == 'h'){ goto History; }
  else if(input[0] == '!'){ goto gHistory; }
  else if(input[0] == 'q'){ goto quit; }
  else{
    printf("Error please try again.\n");
    goto Options;
  }
 input:
  printf("Input sentence below. \n>");
  fgets(input, LIMIT, stdin);
  char **tokens = tokenize(input);
  print_tokens(tokens);
  add_history(History, input);
  free_tokens(tokens);
  goto Options;
 History:
  print_history(History);
  goto Options;
 gHistory: ;
  char *spec = get_history(History, atoi(input+1));
  printf("%s\n", spec);
  goto Options;
 quit:
  printf("Thank you. Goodbye.\n");
  return 0;
}
