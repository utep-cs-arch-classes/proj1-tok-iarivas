\#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#define LIMIT 100
char arr[LIMIT];

void buffer(){
  int i = 0;
  for(char temp; ((temp = getchar()) != '\n' && i < LIMIT); i++){
    arr[i] = temp;
  }
<<<<<<< HEAD
=======
  printf("yes");
  return 1;
>>>>>>> 485f36dcc4ba30c2310ada6abbfa1176d24c8754
}

int main()
{
  List *History = init_history();
  goto Options;
 Options:
  printf("Select an option below.\n");
  printf("Input 'i' to input a sentence.\n");
  printf("Input 'h' to view history.\n");
  printf("Input '!' and a number to get a specific token from history.\n");
  printf("Input 'q' to exit program.\n");
  printf(">");
  buffer();
  if(arr[0] == 'i'){ goto input; }
  else if(arr[0] == 'h'){ goto History; }
  else if(arr[0] == '!'){ goto gHistory; }
  else if(arr[0] == 'q'){ goto quit; }
  else{
    printf("Error please try again.\n");
    goto Options;
  }
 input:
  printf("Input sentence below. \n>");
  buffer();
  char **tokens = tokenize(&(arr[0]));
  print_tokens(tokens);
  add_history(History, &(arr[0]));
  free_tokens(tokens);
  goto Options;
 History:
  print_history(History);
  goto Options;
 gHistory: ;
  char *spec = get_history(History, atoi(arr+1));
  printf("%s\n", spec);
  goto Options;
 quit:
  printf("Thank you. Goodbye.\n");
  return 0;

}
