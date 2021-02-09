#include "tokenizer.h"
#include <stdio.h>
#define LIMIT 100
char arr[LIMIT];


int main(){
  int i = 0;
  for(char input_char; ((input_char = getchar()) != '\n') && (i < LIMIT); i++){
    arr[i] = input_char;
    putchar(input_char);
  }
  printf("\n");

  for(int j = 0; j < i; j++){
    if(space_char(arr[j])){ printf("Space Char \n"); }
    else if(non_space_char(arr[j])){ printf("Non Space Char \n"); }
    else{ printf("Error \n"); }
  }
  return 1;
}


