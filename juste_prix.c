#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int chiffre_banco = rand() % 5 + 1; // de 1 à 5
    int chiffre_donné = 0;

    printf("Devine le chiffre\n");

    while (1)
    {
        printf("Donne le chiffre : \n");
        scanf("%d", &chiffre_donné);
        if (chiffre_banco == chiffre_donné)
        {
            printf("Bravo c'est gagné\n");
            return 0;
        }
        else if (chiffre_banco > chiffre_donné)
        {
            printf("C'est plus\n");
        }
        else
        {
            printf("C'est moins\n");
        }
    }
    return 0;
}