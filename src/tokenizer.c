#include "tokenizer.h"
#include <stdio.h>

int main(){
  printf("start\n");
}

int space_char(char c){
  if(c == ' ' || c == '\t' || c == '\n' ){
    return 1;
  }return 0;
}

int non_space_char(char c){
  if(c != ' ' || c != '\t' || c != '\n'){
    return 1;
  }return 0;
}

char *word_start(char *str){
  if(str[0] == '\0') { return 0; }
  int i = 0;
  while(space_char(str[i])){
    i++;
  }
  return &str[i];
}

char *word_end(char *str){
  if(str[0] == '\0') { return 0;}
  int i =0;
  while(non_space_char(str[0])){
    i++;
  }
  return &str[i]
}

int count_words(char *str){
  int count = 0;
  char *p = word_start(str[0]);
  if(p[0] == '\0') { return 0;}
  while(p[0] != '\0'){
    p = word_end(p[0]);
    p = word_start(p[0]);
    count++;
  }
}

char *copy_str(char *instr, short len){}

char **tokenize(char* str){}

void print_tokens(char **tokens){}

void free_tokens(char **tokens){}

