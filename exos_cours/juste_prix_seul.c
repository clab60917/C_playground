#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int chiffre_banco = rand() % 6 + 1; // de 1 à 5

    int chiffre_donné = 0;
    printf("Bienvenu dans le jeu du juste prix. Devine le prix.\n");

    while (1)
    {
        printf("Entre un chiffre entre 1 et 5 :\n");
        scanf("%d", &chiffre_donné);

        if (chiffre_banco == chiffre_donné)
        {
            printf("Bravo tu as gagné !!\n");
            return 0;
        }
        else if (chiffre_banco > chiffre_donné)
        {
            printf("C'est plus ! Recommence.\n");
        }
        else
        {
            printf("C'est moins ! Recommence.\n");
        }
    }
    return 0;
}