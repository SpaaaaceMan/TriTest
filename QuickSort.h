void PlacePivot (int left, int right, int tab[], int * pivot)
{
	*pivot = left;
	int i = left + 1;
	for ( ; i < right; ++i)
		if (tab[i] < tab[left])
			Swap (tab, i, ++(*pivot));
	Swap (tab, left, ++(*pivot));
}

/**
 * \fn QuickSort (int left, int right, int tab[])
 * \author Kurt SAVIO
 * \brief 
 * \param 
 * \param 
 */
void QuickSort (int left, int right, int tab[])
{
	int pivot;
	if (right > left)
	{
		PlacePivot (left, right, tab, &pivot);
		QuickSort (left, pivot - 1, tab);
		QuickSort (pivot + 1, right, tab);
	}
}

void LaunchQS (int tab[], int size)
{
	QuickSort(0, size - 1, tab);
}
