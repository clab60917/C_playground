#include <stdio.h>
#include <string.h>

int main()
{
    struct Chien { // Ici on definit une structure
        int age;
        char name[50];
        char race[50];
    };

    struct Chien Vico; // Ici on utilise la structure

        // stpcpyc parce que c'est des chaines de caracteres et impossible de race = Bichon
        stpcpy(Vico.name, "Vico"); // strcpy(Vico.name, "Vico"); copie "Vico" dans le tableau de caractères Vico.name.
        stpcpy(Vico.race, "Bichon");

        // Vu que c'est un int on a le droit de faire age = 1
        Vico.age = 1;

        // Print des valeurs renseignées
        printf("Nom du chien : %s\n", Vico.name);
        printf("Age du chiot : %d\n", Vico.age);

        printf("Race : %s\n", Vico.race);


    return 0;
}