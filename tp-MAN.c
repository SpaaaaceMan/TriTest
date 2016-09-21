/**
 * \file tp-MAN.c
 * \brief Programme de tests.
 * \author Julien TEULLE
 * \version 1
 * \date 14/09/16
 *
 * Programme de test pour divers tri
 *
 */

#include "stdlib.h"
#include "time.h"
#include "stdio.h"

#define MAX 1000000
typedef int TABLEAU[MAX];

clock_t begin, end;

/**
 * \fn fillWithRandomNumbers (int tab[], int size)
 * \brief Fill a table with numbers randomly generated.
 * \param tab The table which is filled.
 * \param size The size of tab.
 */
void fillWithRandomNumbers (int tab[], int size)
{
	srand(time(NULL));
	int i = 0;
	for (; i < size; i++)
	{
		tab[i] = (int) rand() % 100;
	}
}

/**
 * \fn display (int tab[], int size)
 * \author Julien TEULLE
 * \brief Show the content of a table with one element per line.
 * \param tab The table which is display.
 * \param size The size of tab.
 */
void display (int tab[], int size)
{
    int i = 0;
	for (; i < size; i++)
    {
        printf("%d %d\n", i, tab[i]);
    }
}

/**
 * \fn getSequentialPosition (int i, int tab[])
 * \author Julien TEULLE
 * \brief obtain the index of the table where a value must be insert
 * with a sequential way.
 * \param tab The table which is concern.
 * \param size The size of tab.
 */
int getSequentialPosition (int i, int tab[])
{
	int p = 0;
	while (tab[p] < tab[i]) 
		p++;
	return p;
}

/**
 * \fn getDichotomousPosition (int i, int tab[])
 * \author Julien TEULLE
 * \brief obtain the index of the table where a value must be insert 
 * with a dichotomous way.
 * \param tab The table which is concern.
 * \param size The size of tab.
 */
int getDichotomousPosition (int i, int tab[])
{
	int left, right, middle;
	left = 0;
	right = i;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (tab[i] <= tab[middle]) 
			right = middle;
		else
			left = middle + 1;
	}
	return left;
}
	
/**
 * \fn sequentialInsertionSort (int tab[], int size)
 * \author Julien TEULLE
 * \brief Sort a table
 * \param tab The table which is sort.
 * \param size The size of tab.
 */
void sequentialInsertionSort (int tab[], int size)
{
	int i, p, x;
	for (i = 1; i < size; i++)
	{
		p = getSequentialPosition(i, tab);
		x = tab[i];
		int j;
		for (j = i - 1; p <= j; j--)
			tab[j+1] = tab[j];
		tab[p] = x;
	}
}

/**
 * \fn dichotomousInsertionSort (int tab[], int size)
 * \author Julien TEULLE
 * \brief Sort a table
 * \param tab The table which is sort.
 * \param size The size of tab.
 */
void dichotomousInsertionSort (int tab[], int size)
{
	int i, p, x;
	for (i = 1; i < size; i++)
	{
		p = getDichotomousPosition(i, tab);
		x = tab[i];
		int j;
		for (j = i - 1; p <= j; j--)
			tab[j+1] = tab[j];
		tab[p] = x;
	}
}

void CreateCSV ()
{
	FILE * ResultTest = fopen("ResultatTestTri.csv", "w");
	
	if (ResultTest == NULL)
	{
		printf("Impossible d'ouvrir le fichier\n");
		exit(1);
	}
	
	char * Titre[23];
	
	Titre[0]  = "Nom du tri";
	Titre[1]  = "Taille Tableau";
	Titre[2]  = "Temps Test 1";
	Titre[3]  = "Temps Test 2";
	Titre[4]  = "Temps Test 3";
	Titre[5]  = "Temps Test 4";
	Titre[6]  = "Temps Test 5";
	Titre[7]  = "Temps Test 6";
	Titre[8]  = "Temps Test 7";
	Titre[9]  = "Temps Test 8";
	Titre[10] = "Temps Test 9";
	Titre[11] = "Temps Test 10";
	Titre[12] = "Temps Test 11";
	Titre[13] = "Temps Test 12";
	Titre[14] = "Temps Test 13";
	Titre[15] = "Temps Test 14";
	Titre[16] = "Temps Test 15";
	Titre[17] = "Temps Test 16";
	Titre[18] = "Temps Test 17";
	Titre[19] = "Temps Test 18";
	Titre[20] = "Temps Test 19";
	Titre[21] = "Temps Test 20";
	Titre[22] = "Moyenne";
	
	fprintf(ResultTest, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
		Titre[0], Titre[1], Titre[2], Titre[3], Titre[4], Titre[5], Titre[6], Titre[7], Titre[8], Titre[9], 
		Titre[10], Titre[11], Titre[12], Titre[13], Titre[14], Titre[15], Titre[16], Titre[17], Titre[18], Titre[19], 
		Titre[20], Titre[21], Titre[22]);
		
	fclose(ResultTest);
}

FILE* OpenCSV ()
{
	FILE * ResultTest = fopen("ResultatTestTri.csv", "a");
	
	if (ResultTest == NULL)
	{
		printf("Impossible d'ouvrir le fichier\n");
		exit(1);
	}
	return ResultTest;
}

void CloseCSV (FILE * ResultTest)
{
	fclose(ResultTest);
}

/**
 * \fn getTimeElapsedInMilliseconds()
 * \author Julien TEULLE
 * \brief Calculate the time elapsed between begin and end in 
 * milliseconds.
 * \return The value of this time
 */
double getTimeElapsedInMilliseconds()
{
	return (((double)(end - begin)) / CLOCKS_PER_SEC) * 1000.000;
}

/**
 * \fn displayTimeElapsedInMilliseconds()
 * \author Julien TEULLE
 * \brief Show the time elapsed between begin and end.
 */
void displayTimeElapsedInMilliseconds()
{
	 printf("Execution time : %fms", getTimeElapsedInMilliseconds());
}

int main ()
{
    begin = clock();
    
    int size = 10;
    
    int tab[size];
    //initialization
    fillWithRandomNumbers(tab, size);
    display(tab, size);
    
    //test
    dichotomousInsertionSort(tab, size);
    display(tab, size);
    
    end = clock();
    
    //show time
    displayTimeElapsedInMilliseconds();
    return 0;
}
