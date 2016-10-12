#include <stdio.h>
#include <stdlib.h>

TRI MergeSort_Create()
{
    TRI This;                                                                                                                                 
    This.name = "Merge Sort";
    This.sort = LaunchMS;
    return This;
}

void merge (int left, int middle, int right, int tab[])
{
    int *tmp = (int*)malloc((right - left + 1) * sizeof(int));
    int i;
    int l = left;
    int r = middle + 1;
    for (i = left; i <= middle; ++i)
    {
        tmp[i - left] = tab[i];
    }
    for (i = left; i <= right; ++i)
    {
        if (l == middle + 1) break;
        else if (r == right + 1 || tmp[l - left] <= tab[r])
        {
            tab[i] = tmp[l - left];
            ++l;
        }
        else
        {
            tab[i] = tab[r];
            ++r;
        }
    }
    free (tmp);
}

void mergeSort (int left, int right, int tab[])
{
    if (left < right)
    {
        int middle = (left + right) / 2;
        mergeSort(left, middle, tab);
        mergeSort(middle + 1, right, tab);
        merge(left, middle, right, tab);
    }
}

void LaunchMS (int tab[], int size)
{
    mergeSort(0, size - 1, tab);
}
