TRI DichotomousSort_Create()
{
       TRI This;
       This.name = "Dichotomous Sort";
       This.sort = dichotomousInsertionSort;
       return This;
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
