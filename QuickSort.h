TRI QuickSort_Create()
{
       TRI This;
       This.name = "Quick Sort";
       This.sort = LaunchQS;
       return This;
}

/**
 * \fn PlacePivot (int left, int right, int tab[], int * pivot)
 * \author Kurt SAVIO
 * \brief Place the value at pivot to its right place in the table
 * \param left : left index of the table
 * \param right : right index of the table
 * \param tab[] : table
 * \param pivot : position of the wanted value to be sort
 */
void PlacePivot (int left, int right, int tab[], int * pivot)
{
	*pivot = left;
	int i;
	for (i = left + 1; i <= right; ++i)
		if (tab[i] < tab[left])
		{
			++(*pivot);
			Swap (tab, i, *pivot);
		}
	Swap (tab, left, *pivot);
}

/**
 * \fn QuickSort (int left, int right, int tab[])
 * \author Kurt SAVIO
 * \brief Sort a table
 * \param left : left index of the table
 * \param right : right index of the table
 * \param tab[] : table to sort
 * \FirstUse QuickSort(0, size - 1, tab); 
 */
void QuickSort (int left, int right, int tab[])
{
	int pivot;
	if (right > left)
	{
		PlacePivot (left, right, tab, &pivot);
		if (pivot - left >= 1)
		{
			QuickSort (left, pivot - 1, tab);
			QuickSort (pivot + 1, right, tab);
		}
	}
}

/**
 * \fn LaunchQS (int tab[], int size)
 * \author Kurt SAVIO
 * \brief Launch Quicksort while using the same profile then every other sort
 * \param tab[] : table to sort
 * \param size : size of the table
 */
void LaunchQS (int tab[], int size)
{
	QuickSort(0, size - 1, tab);
}
