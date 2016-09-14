#include <stdio.h>

int main ()
{
	FILE * ResultTest = fopen("ResultatTestTri.csv", "w");
	if (ResultTest == NULL)
	{
		printf("Impossible d'ouvrir le fichier\n");
		return 1;
	}
	char * NomTest = "BlaBla";
	int Temps[4];
	Temps[1] = 2;
	Temps[2] = 3;
	Temps[3] = 7;
	int Moyenne = 4;
	
	//Faire un test
	//Enreistrement de chaque temps dans un tableau Temps
	//Vérification que le temps total est < 5min (ajout du précédent temps dans une variable)
	//Calcul de la moyenne à la fin
	//Ecrire les résultats ensuite
	fprintf(ResultTest, "%s;%d;%d;%d;%d\n",NomTest, Temps[1], Temps[2], Temps[3], Moyenne);
	
	return 0;
}

//Création Tableau de taille X
int Taille = 100;
int Tab[100];
for (i = 0; i < 20; i++)
{
	RemplirTableauAleatoire(Tab, Taille);
	//Tri
	//voir au-dessus
}

//Création Tableau de taille Y
...

