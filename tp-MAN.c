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

void sequentialInsertionSort (int tab[], int size)
{
	int i, p, x;
	for (i = 1; i < size; i++)
	{
		p = 0;
		while (tab[p] < tab[i]) p++;
		x = tab[i];
		int j;
		for (j = i - 1; p <= j; j--)
			tab[j+1] = tab[j];
		tab[p] = x;
	}
}

int main ()
{
    clock_t begin, end;
    begin = clock();
    int size = 10;
    int tab[size];
    fillWithRandomNumbers(tab, size);
    display(tab, size);
    sequentialInsertionSort(tab, size);
    display(tab, size);
    end = clock();
    printf("Execution time : %fms", (((double)(end - begin)) / CLOCKS_PER_SEC) * 1000.0);
    return 0;
}
