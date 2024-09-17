#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mystruct {
  int x;
  char * name;
};

int main(){
  FILE * f;
  f = fopen("mydata.blob", "w");
  struct mystruct * m = malloc(sizeof(struct mystruct));
  m->x = 4;
  m->name = malloc(sizeof(char)*100);
  strcpy(m->name, "coucou");
  printf("m->x = %i\n", m->x);
  printf("m->name = %s\n", m->name);
  fwrite(m, sizeof(struct mystruct), 1, f);
  fclose(f);
  return 0;
}
