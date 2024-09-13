#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int item; // élément dans la liste
  struct list *next; // pointeur vers le reste de la liste
} list;

list * new_list(){
  return NULL;

}

list * new_node(int x){
  
  return NULL;
}

list * insert_front(int x, list * l){
  return NULL;
}

list * insert_back(list * l, int x){
  return NULL;
}

int equal(list * l1, list * l2){
  return 0;
}

int contains(list * l1, int x){
  return 0;
}

int subset(list* l1, list* l2){
  return 0;
}

int length(list* l){
  return -1;
}

void iter(list * l, void (*fct)(int)){

}

void display_int(int item){
}

void display_list(list* l){

}

void free_list(list * l){

}

list * delete(list* l, int x){
  return NULL;
}

void bubble(list * l){

}

void test(char* s, int condition){
  printf("%s ", s);
  if(condition) printf("OK\n");
  else printf("KO \n");
}

int main(){

  list * l1 = new_list();
  l1 = insert_back(l1, 2);
  l1 = insert_back(l1, -3);
  l1 = insert_back(l1, 5);
  l1 = insert_back(l1, 4);
  list * l2 = new_list();
  l2 = insert_front(4, l2);
  l2 = insert_front(5, l2);
  l2 = insert_front(-3, l2);
  l2 = insert_front(2, l2);
  test("l1 == l2 ?", equal(l1, l2));
  test("NULL == l2 ?", !equal(NULL, l2));
  test("l1 == NULL ?", !equal(l1, NULL));
  l2 = delete(l2, 5);
  test("l1 == l2 ?", !equal(l1, l2));

  test("contains(l1,3)", !contains(l1, 3));
  test("contains(l1,5)", contains(l1, 5));
  test("contains(l2,3)", !contains(l2, 3));
  test("contains(l2,5)", !contains(l2, 5));

  test("subset(l1, l2)", !subset(l1, l2));
  test("subset(l2, l1)", subset(l2, l1));
  test("subset(l1, NULL)", !subset(l1, NULL));
  test("subset(NULL, l2)", subset(NULL, l2));

  test("length(l1)", length(l1) == 4);
  test("length(l2)", length(l2) == 3);
  test("length(NULL)", length(NULL) == 0);

  printf("l1 = ");
  display_list(l1);
  printf("\n");

  bubble(l1);
  printf("l1 sorted = ");
  display_list(l1);
  printf("\n");


  free_list(l1);
  free_list(l2);

  return 0;
}
