#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

int space_char(char c)
{
  if((c == ' ' || c == '\t') && c != 0){
    return 1;
  }return 0;
}

int non_space_char(char c)
{
  if((c != ' ' || c != '\t') && c != 0){
    return 1;
  }return 0;
}

char *word_start(char *str)
{
  int i = 0;
  while(space_char(str[i])){
    i++;
  }
  return &str[i];
}

char *word_end(char *str)
{
  int i = 0;
  while(non_space_char(str[i])){
    i++;
  }
  return &str[i];
}

int count_words(char *str)
{
  int count = 0;
  char *ptr = str;
  while(*ptr != '\0')
  {
    ptr = word_start(ptr);
    ptr = word_end(ptr);
    count++;
  }
  return count;
}

char *copy_str(char *src, short len)
{
  char *copy = malloc((len+1) * sizeof(char));
  int i;
  for(i = 0; i < len; i++){
    copy[i] = src[i];
  }
  copy[i] = 0;
  return copy;
}

char **tokenize(char* str)
{
  int words = count_words(str);
  char **tokens = malloc((words+1) * sizeof(char *));
  int i;
  char *ptr = str;
  for(i = 0; i < words; i++){
    char *start = word_start(ptr);
    char *end = word_end(ptr);
    char *ptr = start;
    int len = 0;
    while(ptr != end){
      ptr++;
      len++;
    }
    tokens[i] = copy_str(start, len);
    ptr = end;
  }
  tokens[i] = 0;
  return tokens;
}

void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != 0){
    printf("%s\n", tokens[i]);
    i++;
  }
}

void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != 0){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
 
