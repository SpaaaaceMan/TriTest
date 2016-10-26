typedef struct _TRI {                                                                                                                          
    char* name;
    void (*sort)(int tab[], int sizeOfTab);
} TRI;

void LaunchQS (int tab[], int size);
void sequentialInsertionSort (int tab[], int size);
void LaunchMS (int tab[], int size);
void SelectionSwapSort (int tab[], int size);
void bubbleSort (int tab[], int size);
void dichotomousInsertionSort (int tab[], int size);
void StackSort (int tab[], int size);
void binary_search_tree_sort(int tab[], int size);
