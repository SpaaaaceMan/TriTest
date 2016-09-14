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
    clock_t debut, fin;
    debut = clock();
    int taille = 1000;
    int tab[taille];
    remplirTableauAleatoire(tab, taille);
    //afficherTableau(tab, taille);
    fin = clock();
    printf("%f", (((double)(fin - debut)) / CLOCKS_PER_SEC) * 1000.0);
    return 0;
}
