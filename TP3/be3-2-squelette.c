#include <stdio.h>
#include <stdlib.h>

typedef struct arbre {
  int x;
  struct arbre* fg;
  struct arbre* fd;
} A;
int displayArbre(){
  if (arbre == NULL){
    return 0;
  }

}

int main(){
  A d = { .x = 5, .fg = NULL, .fd = NULL };
  A c = { .x = 50, .fg = NULL, .fd = NULL };
  A b = { .x = 1, .fg = NULL, .fd = &d };
  A a = { .x = 30, .fg = &b, .fd = &c };

  return 0;
}
