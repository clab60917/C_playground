#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
        FILE *fichier = fopen("note_secrete.txt", "w");
        fputs("Voici la note secrete agent : recupere l'oiseau dans le nid. Ce message s'autodetruira. Over. \n", fichier);
        printf("Autodestruction dans 15 secondes");
        fclose(fichier);
        sleep(15);
        remove("note_secrete.txt");
    }
    else
    {
        printf("Vous ne pouvez pas acceder à ce document confidentiel \n");
    }

    return 0;
}
