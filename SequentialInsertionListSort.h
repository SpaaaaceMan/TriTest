#ifndef _SEQUENTIALINSERTIONLISTSORTH_
#define _SEQUENTIALINSERTIONLISTSORT_
#include "list.h"

TRI SequentialInsertionListSort_Create()
{
    TRI This;
    This.name = "Sequential Insertion List Sort";
    This.sortList = sequentialInsertionListSort;
    return This;
}

void sequentialInsertionListSort (List *list) {

    if (list->top == NULL || list->top->next == NULL) {
        return;
    } 

    Node *currentNode = list->top->next;
    Node *currentSortedNode = list->top;
    Node *kNode;

    int tmp;

    while (currentNode->next != NULL) {

        while (currentNode->value > currentSortedNode->value) {
            currentSortedNode = currentSortedNode->next;
        }

        tmp = currentNode->value;

        for (kNode = currentSortedNode; kNode != currentNode; kNode = kNode->next) {
            kNode->next->value = kNode->value;
        }

        currentSortedNode->value = tmp;

        currentNode = currentNode->next;
        currentSortedNode = list->top;
    }
}

#endif
