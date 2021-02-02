#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   (' ', '\t', or '\n').
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c == ' ' || c == '\t' || c == '\n'){
    return 1;
  }return 0;
}

/* Return true (non-zero) if c is a non-whitespace
   character (not space, tab, or newline).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  if(c != ' ' || c != '\t' || c != '\n'){
    return 1;
  }return 0;
}

/* Returns a pointer to the first character of the next
   space-separated word in zero-terminated str.  Return a zero pointer if
   str does not contain any words.
   str is assumed to be pointing to a space character */
char *word_start(char *str){
  if(str[0] == '\0') { return '\0'; }
  int i = 0;
  while(space_char(str[i])){
    i++;
  }
  return &str[i];
}

/* Returns a pointer terminator to the first space character or string-terminator
   following str in a zero terminated string.
   str is assumed to be pointing to a non-space character*/
char *word_end(char *str){
  if(str[0] == '\0') { return '\0'; }
  int i = 0;
  while(non_space_char(str[i])){
    i++;
  }
  return &str[i];
}

/* Counts the number of space seperated words in the string argument. */
int count_words(char *str){
  int count = 0;
  char *p = word_start(str[0]);
  if(p[0] == '\0'){ return 0; }
  while(p[i] != '\0'){
    count++;
    p = word_end(p[0]);
    p = word_start(p[0]);
  }
}

/* Returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len);

/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens);

#endif
