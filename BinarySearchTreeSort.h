TRI Binary_search_tree_sort_Create()
{
    TRI This;
    This.name = "Binary search tree";
    This.sort = binary_search_tree_sort; 
    return This;
}

struct node
{
    struct node *rightchild;
    int value;
    struct node *leftchild;
};

void insert(struct node **source, int value)
{
    if(*source == NULL)
    {
        *source = malloc(sizeof(struct node));
        (*source)->leftchild = NULL;
        (*source)->value = value;
        (*source)->rightchild = NULL;
        return;
    }
    else
    {
        if(value < (*source)->value)
            insert(&((*source)->leftchild), value);
        else
            insert(&((*source)->rightchild), value);
    }
    return;
}

int indexOrder = -1;

void inorder(struct node *source, int tab[])
{
    if(source != NULL)
    {
        inorder(source->leftchild, tab);
        tab[++indexOrder] = source->value;
        inorder(source->rightchild, tab);
    }
    else
        return;
}

void binary_search_tree_sort(int tab[], int size)
{
    int i;
    struct node *root;
    root = NULL;
    for (i = 0; i < size; i++) {
        insert(&root, tab[i]);
    }
    inorder(root, tab);
}
