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
    return;
  }
  displayArbre(node->fg);
  displayArbre(node->fd);
  printf("Node : %d\n", node->node);
  printf("Adresse : %p\n", node);
}

// QUESTION 6
void displaySorted(A *node)
{
  if (node == NULL)
  {
    return;
  }
  // Afficher ceux de gauche puis ceux de droite, pcq à gauche c'est plus petit d'apres enoncé
  displaySorted(node->fg);
  // En fait ça classe pas en fonction de plus ou moins, mais ça prend chaque segment de l'arbre et affiche le root. Vu que c'est le plus inf à chaque fois bingo.
  printf("Node : %d\n", node->node);
  displaySorted(node->fd);


}

int main()
{
  A d = {.node = 5, .fg = NULL, .fd = NULL};
  A c = {.node = 50, .fg = NULL, .fd = NULL};
  A b = {.node = 1, .fg = NULL, .fd = &d};
  A a = {.node = 30, .fg = &b, .fd = &c};
  displayArbre(&a);
  displaySorted(&a);

  return 0;
}
