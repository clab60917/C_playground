#include <unistd.h>
#include <stdio.h>

int recurrence_des_lettres(char lettre, char *chaine)
{
    int compteur = 0;
    char *p = chaine; // le pointeur p pointe vers le debut de la chaine

    while (*p != '\0')
    {
        if (*p == lettre)
            compteur++;
        p++;
    }
    return compteur; // ça j'ai moyen capté le del
}
int main()
{
    int n = recurrence_des_lettres('c', "centralesupppppcccc");
    printf("nb : %d\n", n);
    return 0;
}