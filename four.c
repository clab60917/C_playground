#include <stdio.h>
#include <string.h>

int main()
{
    int password;

    printf("Veuillez entrer le mot de passe maxi secret : %s\n");
    scanf("%d", &password);

    if (password == 987)
        
    {
        printf("Bienvenue monsieur %d");
        FILE *fichier = fopen("fichiertest1.txt", "w");
        fputs("Voici la note secrete agent : recupere l'oiseau dans le nid. Ce message s'autodetruira. Over. %s\n", fichier);
        fclose(fichier);
    }
    else
    {
        printf("Vous ne pouvez pas acceder à ce document confidentiel %s\n");
    }

    return 0;
}
