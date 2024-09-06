#include <stdio.h>
#include <string.h>
#include <unistd.h>

int facto(int n)
{
    if (n ==0 || n==1){
        return 1;
    } else {
        return n * facto(n-1);
        }
}

int main()
{
    int nombre;
    printf("Donne un nombre pour calculer son factoriel : ");
    scanf("%d", &nombre);
    printf("Le factoriel de %d est %d\n", nombre, facto(nombre));
    return 0;
}