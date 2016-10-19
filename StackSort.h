TRI StackSort_Create()
{
       TRI This;
       This.name = "Stack Sort";
       This.sort = StackSort;
       return This;
}

/**
 * \fn 
 * \author Kurt SAVIO
 * \brief 
 * \param 
 * \return 
 */
void AddStack (int tab[], int i, int Value)
{
	int Parent = (i - 1) / 2;
	tab[i] = Value;
	if (i > 0 && Value > tab[Parent])
	{
		tab[i] = tab[Parent];
		AddStack (tab, Parent, Value);
	}
}

void DeleteMaxStack (int tab[], int * size)
{
	int i = 0;
	int gauche = 1;
	int droite = 2;
	int max;
	
	Swap(tab, i, *size - 1);
	
	--(*size);
	
	while (gauche < *size)
	{
		if (droite < *size && tab[gauche] < tab[droite]) max = droite;
		else max = gauche;
		
		if (tab[i] < tab[max]) Swap(tab, i, max);
		else break;
		
		i = max;
		gauche = 2 * i + 1;
		droite = 2 * i + 2;
	}
}

void CreateStack (int tab[], int size)
{
	int i = 0;
	for ( ; i < size; ++i)
		AddStack(tab, i, tab[i]);
}

void StackSort (int tab[], int size)
{
	CreateStack(tab, size);
	
	int i = size;
	
	int StacksSize = size;
	
	for ( ; i > 1; --i)
		DeleteMaxStack(tab, &StacksSize);
}
