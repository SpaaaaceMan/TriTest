TRI SelectionSwapSort_Create()
{
    TRI This;                                                                                                                                 
    This.name = "Selection-Swap Sort";
    This.sort = SelectionSwapSort;
    return This;
}

void SelectionSwapSort (int tab[], int size)
{
    int i, j;
    for (i = 0; i < size; ++i)
        for (j = i + 1; j < size; ++j)
            if (tab[i] > tab[j]) Swap (tab, i, j);
}
