#include <stdio.h>
#include <stdlib.h>

typedef struct arbre
{
  int node;
  struct arbre *fg;
  struct arbre *fd;
} A;

// QUESTION 5 : on veut afficher l'arbre et la valeur de chaque noeud + adresse de chaque noeud
void displayArbre(A *node)
{
  if (node == NULL)
  {
    printf("Arbre vide\n");
    return 1;
  }
  printf("Node : %d\n", node->node);
  printf("Adresse : %p\n", node);
}

int main()
{
  A d = {.node = 5, .fg = NULL, .fd = NULL};
  A c = {.node = 50, .fg = NULL, .fd = NULL};
  A b = {.node = 1, .fg = NULL, .fd = &d};
  A a = {.node = 30, .fg = &b, .fd = &c};
  displayArbre(&a);

  return 0;
}
