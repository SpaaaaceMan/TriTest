#include "list.h"

TRI SequentialInsertionSort_Create()
{ 
    TRI This;                                                                                                                                 
    This.name = "Sequential Insertion Sort";
    This.sort = sequentialInsertionSort;
    return This;
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
