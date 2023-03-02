#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"

#define MAX_LIMIT 64

int space_char(char c){
  return (c == ' ' || c == '\t');
}
int non_space_char(char c){
  if(c == '\0') return 0;
  return !space_char(c);
}

char *word_start(char *str){
  char *c = str;
  while(space_char(*c)) c++;
  return (*c=='\0')?NULL:c;
}

char *word_terminator(char *str){
  char *c = str;
  while(*c!='\0'&&non_space_char(*c)) c++;
  return c;
}

int count_words(char *str){
  int count = 0;
  char *ptr = str;
  while (*ptr != '\0') {
    while (space_char(*ptr)) {
      ptr++;
    }
    if (non_space_char(*ptr)) {
      count++;
      ptr = word_terminator(ptr);
    }
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char *word = (char*)malloc((len+1)*sizeof(char));
  for(short i = 0; i < len; i++){
    word[i]=inStr[i];
  }
  word[len]='\0';
  return word;
}
char **tokenize(char *str){
  int count = count_words(str);
  char **arr = (char**)malloc((count+1)*sizeof(char*));
  char *start = word_start(str);
  char *term = word_terminator(start);
  short len = term-start;
  for(int i = 0; i < count; i++){
    arr[i] = copy_str(start, len);
    if(i<count-1){
	start=word_start(term);
	term=word_terminator(start);
	len = term-start;
      }
  }
  arr[count]=NULL;
  return arr;
}
void print_tokens(char **tokens){
  char **arr = tokens;
  while(*arr!=NULL){
    printf("%s\n", *arr);
    arr++;
  }
}
