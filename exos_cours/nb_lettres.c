# include <stdio.h>
# include <unistd.h>
# include <ctype.h>

int nb_lettres (char *mot) {
    int compteur = 0;
    char *p = mot;

    while (*p != '\0') {
        if (isalpha(*p))
            compteur++;
        p++;
    }
    return compteur;
}
int main() {
    int n = nb_lettres("ajzodjruhyynocpoanehgivolwnqezlfg10865391ndoizbthcoabdeogbzobfhfy889221");
    printf("nb : %d\n", n);
    return 0;
}