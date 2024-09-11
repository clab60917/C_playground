#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char name[50];
    int age;
    printf("Quel est votre nom ? Ecrire ici : ");
    scanf("%s", name);
    printf("coucou %s", name);
    //return 1;

    int tableau_nombres[7]={1,2,3,4,5,6,7};
    printf("le deuxieme nombre est %d", tableau_nombres[1]);
    free(name);
    printf("coucou %s", name);


   

    return 0;
}