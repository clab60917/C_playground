#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char ecole[] = "centralesupelec";
    char lettre_e = 'e';
    char lettre_z = 'z';
    char lettre_c = 'c';
    int compteur = 0;

    for (int i = 0; i < strlen(ecole); i++)
    {
        if (ecole[i] == lettre_e)
        {
            compteur++;
            if (ecole[i] == lettre_z)
            {
                compteur++;
                if (ecole[i] == lettre_c)
                {
                    compteur++;
                }
                printf("La lettre '%c' apparait %d fois dans la chaine \"%s\".\n", lettre_c, compteur, ecole);

                return 0;
            }
        }
    }
}