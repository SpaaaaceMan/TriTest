#include "man-util.h"

void bubbleSort (int tab[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (tab[i] < tab[i + 1])
            Swap(tab, i, i + 1);
    }
    bubbleSort(tab, size - 1);
}

