#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mystruct
{
  int x;
  char *name;
};
int read()
{
  FILE *f;
  if ((f = fopen("mydata.blob", "rb")) == NULL)
  {
    printf("Erreur lors de l'ouverture du fichier\n");
    return 1;
  }
  f = fopen("mydata.blob", "rb");
  struct mystruct *m2 = malloc(sizeof(struct mystruct));
  fread(m2, sizeof(struct mystruct), 1, f);
  printf("m2->x = %i\n", m2->x);
  printf("m2->name = %s\n", m2->name);
  fclose(f);
  free(m2);
  return 0;
}

int main()
{
  FILE *f;
  f = fopen("mydata.blob", "w");
  struct mystruct *m = malloc(sizeof(struct mystruct));
  m->x = 4;
  m->name = malloc(sizeof(char) * 100);
  strcpy(m->name, "coucou");

  fclose(f);
  strcpy(m->name, "bonjour");
  f = fopen("mydata.blob", "r");


  printf("m->x = %i\n", m->x);
  printf("m->name = %s\n", m->name);
  fwrite(m, sizeof(struct mystruct), 1, f); // Ici on le mets à 1 parce que 1 octet pour une lettre vu que c'est char
  fclose(f);
  read();
  return 0;
}
