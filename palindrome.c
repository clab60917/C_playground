#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// En 1 on fait une fonctionne palindrome
// En 2 on fait un main() qui donne l'argument à la fonction palindrome

int palindrome(char *s) // C'est ça une signature de fonction (******signature****)
{ 
    int debut = 0;
    int fin = strlen(s) - 1;

    // Ensuite on compare les 2 pour voir si palindrome oui / non
    while (debut < fin)
    {
        if (s[debut] != s[fin]) // ça verifie juste si c'est les memes lettres au debut et à la fin au fur et à mesure
        {
            return 0; // Si c'est différent alors c'est pas un palindrome => RETURN 0 
        }
        debut++;
        fin--;
    }
    return 1; // C'est pas différent => donc c'est pareil => palindrome => RETURN 1
}

int main(int argc, char *argv[])
{
    // La on verifie que on a le bon nombre d'arguments (en gros que le user a bien rempli le terminal)
    if (argc < 2)
    { // ici c'est un argument en+ du programme donc minimum 2 pcq avec la fonction ça fait deja 1
        printf("Donne un mot connard\n");
        return 1;
    }
    if (palindrome(argv[1]))
    {
        printf("%s est un palindrome\n", argv[1]);
    }
    else
    {
        printf("%s n'est pas un palindrome\n", argv[1]);
    }
    return 0;
}
