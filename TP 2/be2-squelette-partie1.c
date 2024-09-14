#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
  int item;          // élément dans la liste
  struct list *next; // pointeur vers le reste de la liste
} list;

list *new_list()
{
  return NULL;
}

list *new_node(int x)
{
  list *node = malloc(sizeof(list));
  node->item = x;
  node->next = NULL;
  return node;
}

list *insert_front(int x, list *l)
{
  list *node = new_node(x);
  node->next = l;
  return node;
}

list *insert_back(list *l, int x)
{
  list *temp = l; // ici l c'est ma liste. Temp est la copie temmporaire de la liste
  if (l != NULL)
  {
    while (temp->next != NULL)
    {
      temp = temp->next; // je parcours la liste
    }
    temp->next = new_node(x); // je rajoute un nouveau noeud à la fin de la liste.
    // En fait je remplace le dernier noeud NULL par un nouveau noeud
  }
  return l;
}

int equal(list *l1, list *l2)
{
  list *temp1 = l1; // ici obligé de paser par une copie temporaire de la liste car je vais parcourir la liste et sinon ça renvoie le dernier élément de la liste pour la suite du programme
  list *temp2 = l2;
  while (l1 != NULL && l2 != NULL)
  {
    if (l1->item = l2->item)
    {
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
    else
    {
      printf("Les listes ne sont pas égales\n");

      return 0;
    }
  }
  return 0;
}
// QUESTION 6
int contains(list *l1, int x)
{
  list *temp1 = l1;
  while (l1 != NULL)
  {
    if (l1->item = x)
    {
      temp1 = temp1->next;
      printf("Il est dans la liste\n");
    }
    else
    {
      printf("Il n'est pas dans la liste\n");
      return 0;
    }
  }
  return 0;
}
// QUESTION 7
int subset(list *l1, list *l2)
{
  list *temp1 = l1;
  list *temp2 = l2;

  while (l1 != NULL && l2 != NULL)
  {
    if (l1->item == temp2->item) // ATTENTION : ici on a temp2 et pas l2 car on va parcourir la liste 2
    {
      temp1 = temp1->next;
      temp2 = temp2->next;
      printf("La liste 1 est un sous ensemble de la liste 2\n");
      return 1;
    }
    else
    {
      printf("La liste 1 n'est pas un sous ensemble de la liste 2\n");
      return 0;
    }
  }
}

int length(list *l)
{
  list *temp = l;
  int compteur = 0;

  while (temp != NULL)
  {
    if (temp->next)
    {
      temp = temp->next;
    }
    compteur++;
  }
  return compteur;
}

void iter(list *l, void (*fct)(int))
{
}

void display_int(int item)
{
}

void display_list(list *l)
{
}

void free_list(list *l)
{
}

list *delete(list *l, int x)
{
  return NULL;
}

void bubble(list *l)
{
}

void test(char *s, int condition)
{
  printf("%s ", s);
  if (condition)
    printf("OK\n");
  else
    printf("KO \n");
}

int main()
{

  list *l1 = new_list();
  l1 = insert_back(l1, 2);
  l1 = insert_back(l1, -3);
  l1 = insert_back(l1, 5);
  l1 = insert_back(l1, 4);
  list *l2 = new_list();
  l2 = insert_front(4, l2);
  l2 = insert_front(5, l2);
  l2 = insert_front(-3, l2);
  l2 = insert_front(2, l2);
  test("l1 == l2 ?", equal(l1, l2));
  test("NULL == l2 ?", !equal(NULL, l2));
  test("l1 == NULL ?", !equal(l1, NULL));
  l2 = delete (l2, 5);
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
  list *clement = new_list(); // QUESTION 1
  // Test null QUESTION 1
  printf("QUESTION 1\n");
  if (clement == NULL)
  {
    printf("clement est NULL\n");
  }
  else
  {
    printf("clement n'est pas NULL\n");
  }
  // FIN QUESTION 1
  printf("QUESTION 2\n");
  new_node(42);
  // QUESTION 3
  printf("QUESTION 3\n");

  clement = insert_front(2, clement);
  clement = insert_front(3, clement);
  clement = insert_front(4, clement);
  clement = insert_front(5, clement);

  // QUESTION 7
  list *liste1 = new_list();
  liste1 = insert_front(2, liste1);
  liste1 = insert_front(4, liste1);
  liste1 = insert_front(5, liste1);

  list *liste2 = new_list();
  liste2 = insert_front(1, liste2);
  liste2 = insert_front(2, liste2);
  liste2 = insert_front(3, liste2);
  liste2 = insert_front(4, liste2);
  liste2 = insert_front(5, liste2);

  // Tester la fonction subset
  printf("QUESTION 7\n");
  if (subset(liste1, liste2))
  {
    printf("La liste 1 est un sous-ensemble de la liste 2\n");
  }
  else
  {
    printf("La liste 1 n'est pas un sous-ensemble de la liste 2\n");
  }
  ///////////////////////
  // QUESTION 8
  printf("QUESTION 8\n");
  int longueur_liste1 = length(liste1);
  printf("La longueur de la liste 1 est : %d\n", longueur_liste1);
  ////////////
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
