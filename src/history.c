#include "history.h"
#include <stdlib.h>
#include <stdio.h>

struct s_List* init_history(){
  struct s_List* head = (struct s_List*) malloc(sizeof(struct s_List*));
  head->root = NULL;
  return head;
}
void add_history(List* list, char* str){
  struct s_Item* new_item = (struct s_Item*) malloc(sizeof(struct s_Item));
  new_item->str = str;
  new_item->next = NULL;
  if (list->root == NULL) {
    new_item->id = 0;
    list->root = new_item;
    return;
  }
  struct s_Item* last_item = list->root;
  while (last_item->next != NULL) {
    last_item = last_item->next;
  }
  new_item->id = (last_item->id)+1;
  last_item->next = new_item;
}
char *get_history(List* list, int id){
  struct s_Item* search = list->root;
  if(search->id==id){
    return search->str;
  }
  while (search->next != NULL){
    if(search->id == id){
      return search->str;
    }
    search=search->next;
  }
  return "NULL";
}
void print_history(List* list){
  if(list->root==NULL) return;
  struct s_Item* node = list->root;
  printf("%s\n", node->str);
  while(node->next != NULL){
    node = node->next;
    printf("%s\n", node->str);
  }
  return;
}
int main(){
  List* hist = init_history();
  char* str = "hello world";
  add_history(hist, str);
  printf("%s\n", get_history(hist, 1));
  print_history(hist);
}
