#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int item;            // L'élément (un entier) contenu dans ce nœud
    struct list *next;   // Pointeur vers le prochain nœud
} list;

int main() {
    // Créons deux nœuds
    list* node1 = malloc(sizeof(list));
    list* node2 = malloc(sizeof(list));

    // Initialisons les nœuds
    node1->item = 10;    // Le premier nœud contient 10
    node2->item = 20;    // Le deuxième nœud contient 20

    // Le pointeur du premier nœud pointe vers le deuxième nœud
    node1->next = node2;

    // Le pointeur du deuxième nœud pointe vers NULL (fin de la liste)
    node2->next = NULL;

    // Affichage des éléments de la liste
    printf("Premier élément: %d\n", node1->item);  // Affiche 10
    printf("Deuxième élément: %d\n", node1->next->item);  // Affiche 20

    // Libération de la mémoire allouée
    free(node1);
    free(node2);

    return 0;
}
