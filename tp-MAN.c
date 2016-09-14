#include "stdlib.h"
#include "time.h"
#include "stdio.h"

#define MAX 1000000
typedef int TABLEAU[MAX];

void remplirTableauAleatoire (int tableau[], int taille)
{
	srand(time(NULL));
	int i = 0;
	for (; i < taille; i++)
	{
		tableau[i] = (int) rand();
	}
}

void afficherTableau (int tableau[], int taille)
{
    int i = 0;
	for (; i < taille; i++)
    {
        printf("%d %d\n", i, tableau[i]);
    }
}

int main ()
{
	int tab[100];
    clock_t debut, fin;
    debut = clock();
	remplirTableauAleatoire(tab, 100);
    fin = clock();
    printf("%d", (fin - debut) * 1.0 / CLOCKS_PER_SEC);
    afficherTableau(tab, 100);
    return 0;
}
