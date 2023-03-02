#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main(){
  char str[64];
  List* hist = init_history();
  while(1){
    printf("$");
    fgets(str, 64, stdin);
    if(*str == '!'){
      print_tokens(tokenize(get_history(hist, atoi(str+1))));
    } else{
      add_history(hist, str);
      print_tokens(tokenize(str));
    }
  }
}
