TRI Binary_search_tree_sort_Create()
{
    TRI This;
    This.name = "Bubble Sort";
    This.sort = bubbleSort;
    return This;
}

void add_leaf(int tab[], int index, int value)       
{
    int left = index*2+1;
    int right = index*2+2;
    if (value < tab[index]) {
        add_leaf(tab, left, value);
    }
    else {
        add_leaf(tab, right, value);
    }
    tab[index] = value;
    return;
}
void build_binary_search_tree(int tab[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        add_leaf(tab, i, tab[i]);
    }
}

void binary_search_tree_sort(int tab[], int size) 
{
    build_binary_search_tree(tab, size);
}
