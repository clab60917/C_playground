#include <stdio.h>
#include <string.h>

int main()
{
    int password;
    char name[50]; 
    printf("Quel est votre nom ? Ecrire ici : ");
    scanf("%s", name); // ATTENTION, SCANF NE SUPPORTE PAS /N
    printf("Veuillez entrer le mot de passe maxi secret, %s : ", name);
    scanf("%d", &password);

    if (password == 987)
        
    {
        printf("Bienvenue monsieur %s\n", name); // METTRE EN DERNIERE LIGNE ÇA POUR PAS AVOIR LE %
        FILE *fichier = fopen("fichiertest1.txt", "w");
        fputs("Voici la note secrete agent : recupere l'oiseau dans le nid. Ce message s'autodetruira. Over. \n", fichier);
        fclose(fichier);
    }
    else
    {
        printf("Vous ne pouvez pas acceder à ce document confidentiel \n");
    }

    return 0;
}
