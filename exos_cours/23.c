#include <unistd.h>
#include <ctype.h>
#include <stdio.h> // Ajout de stdio.h pour printf

int nombre_occurence(char lettre, char *chaine)
{
    int compteur = 0;
    char *p = chaine; // p pointe vers le début de la chaîne

    while (*p != '\0') // Parcourt la chaîne jusqu'au caractère nul
    {
        if (*p == lettre)
        p++; // Avance le pointeur au caractère suivant
    }
    return compteur; // Retourne le nombre d'occurrences
}

int main() {
    int n = nombre_occurence('c', "CentraleSupelec"); // Recherche du caractère 'c'
    printf("Nombre de c = %d\n", n);
    n = nombre_occurence('z', "CentraleSupelec"); // Recherche du caractère 'z'
    printf("Nombre de z = %d\n", n);
    n = nombre_occurence('e', "CentraleSupelec"); // Recherche du caractère 'e'
    printf("Nombre de e = %d\n", n);
    return 0;
}