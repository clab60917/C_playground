#include <stdio.h>

int main()
{
    int chiffre_clef;
    printf("Donne le mot de passe !\n");
    scanf("%d", &chiffre_clef);
    if (chiffre_clef == 2)
    {
        printf("Bravo rentrez");
    }
    else
    {
        printf("casse toi");
    }
    return 0;
}