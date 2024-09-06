#include <stdio.h>
#include <string.h>

int nombre_lettres(char lettre, char *chaine)
{
    int compteur = 0;
    char *p = chaine;

    while (*p != '\0')
    {
        if (*p == lettre)
            compteur++;
        p++;
    }
    return compteur;
}

int main()
{
    int n = nombre_lettres('c', "centralesupelec");
    printf("Nombre de c : %d\n", n);
    n = nombre_lettres('e', "centralesupelec");
    printf("Nombre de e : %d\n", n);
    n = nombre_lettres('z', "centralesupelec");
    printf("Nombre de z : %d\n", n);
    return 0;
}
