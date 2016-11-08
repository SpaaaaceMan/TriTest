/**
 * \file tp-MAN.c
 * \brief Programme de tests.
 * \author Julien TEULLE, Kurt SAVIO
 * \version 1
 * \date 14/09/16
 *
 * Programme de test pour divers tri
 *
 */

#include "man-util.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "stdio.h"
#include "Tri.h"
#include "list.h"

#include "QuickSort.h"
#include "SequentialInsertionSort.h"
#include "DichotomousInsertionSort.h"
#include "mergeSort.h"
#include "SelectionSwapSort.h"
#include "bubbleSort.h"
#include "StackSort.h"
#include "BinarySearchTreeSort.h"
#include "SequentialInsertionListSort.h"

/***********CONSTANTS***********/
#define MAX 1000000
#define numberOfSizesToUse 15
#define numberOfTestsToDo  20
#define numberOfTitles     23
#define sizeOfCheckTab     10

/***********TYPES***********/
typedef int TABLEAU[MAX];

/***********GLOBAL VARIABLES***********/
clock_t begin, end;
int sizesUseForTests[numberOfSizesToUse];

/**
 * \fn fillWithRandomNumbers (int tab[], int size)
 * \brief Fill a table with numbers randomly generated.
 * \param tab The table which is filled.
 * \param size The size of tab.
 */
void fillWithRandomNumbers (int tab[], int size)
{
    int i = 0;
    for (; i < size; i++)
    {
        tab[i] = (int) rand() % 101;
    }
}

void fillListWithRandomNumbers (List *list, int size) 
{
    int i = 0;
    for (; i < size; ++i) 
    {
        list->push(list, (int) rand() % 101);
    }
}

/**
 * \fn displayTab (int tab[], int size)
 * \author Julien TEULLE
 * \brief Show the content of a table with one element per line.
 * \param tab The table which is display.
 * \param size The size of tab.
 */
void displayTab (int tab[], int size)
{
    int i = 0;
    printf("=====AFFICHAGE=====\n");
    printf("Indice | Valeur\n");
    for (; i < size; i++)
    {
        printf("%d      | %d\n", i, tab[i]);
    }
}

/**
 * \fn CreateCSV ()
 * \author Kurt SAVIO
 * \brief Create a csv file named "ResultatTestTri.csv" and include 
 * titles at the begining of the file for better undrestanding
 */
void CreateCSV ()
{
    FILE * ResultTest = fopen("ResultatTestTri.csv", "w");

    if (ResultTest == NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }

    char* Titre[numberOfTitles];
    Titre[0]  = "Nom du tri";
    Titre[1]  = "Taille Tableau";
    Titre[2]  = "Temps Test 1";
    Titre[3]  = "Temps Test 2";
    Titre[4]  = "Temps Test 3";
    Titre[5]  = "Temps Test 4";
    Titre[6]  = "Temps Test 5";
    Titre[7]  = "Temps Test 6";
    Titre[8]  = "Temps Test 7";
    Titre[9]  = "Temps Test 8";
    Titre[10] = "Temps Test 9";
    Titre[11] = "Temps Test 10";
    Titre[12] = "Temps Test 11";
    Titre[13] = "Temps Test 12";
    Titre[14] = "Temps Test 13";
    Titre[15] = "Temps Test 14";
    Titre[16] = "Temps Test 15";
    Titre[17] = "Temps Test 16";
    Titre[18] = "Temps Test 17";
    Titre[19] = "Temps Test 18";
    Titre[20] = "Temps Test 19";
    Titre[21] = "Temps Test 20";
    Titre[22] = "Moyenne";
    int i; 
    for (i = 0; i < numberOfTitles - 1; i++) {
        fprintf(ResultTest, "%s;", Titre[i]);
    }
    fprintf(ResultTest, "%s\n", Titre[22]);
    fclose(ResultTest);
}

/**
 * \fn OpenCSV()
 * \author Kurt SAVIO
 * \brief Open the csv file called "ResultatTestTri.csv" in append mode 
 * in order to add data after titles
 * \return the opened file
 */
FILE* OpenCSV ()
{
    FILE * ResultTest = fopen("ResultatTestTri.csv", "a");

    if (ResultTest == NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }
    return ResultTest;
}

/**
 * \fn CloseCSV()
 * \author Kurt SAVIO
 * \brief close the csv file given in param (that should be "ResultatTestTri.csv")
 * \param ResultTest : The file to close
 */
void CloseCSV (FILE * ResultTest)
{
    fclose(ResultTest);
}

/**
 * \fn getTimeElapsedInMilliseconds()
 * \author Julien TEULLE
 * \brief Calculate the time elapsed between begin and end in 
 * milliseconds.
 * \return The value of this time
 */
double getTimeElapsedInMilliseconds()
{
    return (((double)(end - begin)) / CLOCKS_PER_SEC) * 1000.000;
}

/**
 * \fn displayTimeElapsedInMilliseconds()
 * \author Julien TEULLE
 * \brief Show the time elapsed between begin and end.
 */
void displayTimeElapsedInMilliseconds()
{
    printf("Execution time : %fms\n", getTimeElapsedInMilliseconds());
}

/**
 * \fn CalcAverage (double Time[])
 * \author Kurt SAVIO
 * \brief Calculate the average time of a pool of sort
 * \param Time[] : An array containing the 20 time (max) of a sort
 * \return The average of the 20 time.
 */
double CalcAverage (double Time[], int Done)
{
    double Average = 0;
    int i;

    for (i = 0; i < Done; ++i)
        Average += Time[i];

    Average /= Done;
    return Average;
}

/**
 * \fn CalcMinute (double Time)
 * \author Kurt SAVIO
 * \brief Calculate how many minute there are in "Time" milliseconds
 * \param Time : a time in milliseconds
 * \return minutes in "Time" ms.
 */
int CalcMinute (double Time)
{
    return Time / 60000;
}

/**
 * \fn CalcSeconde (double Time)
 * \author Kurt SAVIO
 * \brief Calculate how many second there are in "Time" milliseconds
 * \param Time : a time in milliseconds
 * \return seconds in "Time" ms.
 */
int CalcSeconde (double Time)
{
    return Time / 1000;
}

/**
 * \fn CalcTotalTime (double Time, int Result[])
 * \author Kurt SAVIO
 * \brief Convert a time in milliseconds to minute, seconds and milliseconds
 * \param Time : a time in milliseconds
 * \param Result[] : an array in which one minute, second and milliseconds will be stocked
 */
void CalcTotalTime (double Time, int Result[])
{
    int Minute = CalcMinute(Time);
    Time -= Minute * 60000;

    int Seconde = CalcSeconde(Time);
    Time -= Seconde * 1000;

    Result[0] = Minute;
    Result[1] = Seconde;
    Result[2] = Time;
}

/**
 * \fn ResetTime (double Time[])
 * \author Kurt SAVIO
 * \brief Reset the array of the 20 time
 * \param Time[] : An array containing the 20 time (max) of a sort
 */
void ResetTime(double Time[])
{
    int i;
    for (i = 0; i < 20; ++i)
        Time[i] = 0;		
}

/**
 * \fn IsSort (int tab[], int size)
 * \author Kurt SAVIO
 * \brief Check if a table is sort. If not, it shows where and the said values
 * \param tab[] : a table contianing random numbers
 * \param size : size of the table
 */
void IsSort (int tab[], int size)
{
    int i = 0;
    for ( ; i < size - 1; ++i)
        if (tab[i] > tab[i + 1])
            printf("Tableau Non Trié en %d ! \nValeur : %d > %d \n", i, tab[i], tab[i + 1]);
}

/**
 * \fn DoSort ()
 * \author Kurt SAVIO
 * \brief Create, fill and sort a table for each sort and size, 20 time 
 * each. Also calculate the average time, look out for the total time.
 * Then it writes all the result in the csv file. 
 */
void DoSort (TRI * t, int useList)
{	
    int i, j, size;
    double TotalTime = 0;
    double Time[20];
    FILE * Result = OpenCSV();
    List *list = new_List();

    for (j = 0; j < numberOfSizesToUse; ++j)
    {
        size = sizesUseForTests[j];
        printf ("Tri par %s - %d\n", t->name, size);
        int tab[size];
        fprintf(Result, "Tri par %s;%d;",t->name, size);
        for (i = 0; i < numberOfTestsToDo; ++i)
        {
             if (useList) {
                 fillListWithRandomNumbers(list, size); 
                 begin = clock();
                 t->sortList(list);
             }
             else {
                 fillWithRandomNumbers(tab, size);
                 begin = clock();
                 t->sort(tab, size);
             }
            end = clock();
            IsSort(tab, size);
            Time[i] = getTimeElapsedInMilliseconds();
            fprintf(Result, "%f;", Time[i]);
            TotalTime += Time[i];
            if (TotalTime > 300000) // 5min = 300000ms
                break;
            if (useList) {
               list->free(list); 
            }
        }

        int Res[3];
        CalcTotalTime(TotalTime, Res);
		int echec = 0;

        if (i != 20)
        {
            printf ("Temps limite dépassé : %02d:%02d.%03d ms\n", Res[0], Res[1], Res[2]);
            printf ("Uniquement %d tests fait\n\n", i + 1);
			echec = 1;

        }
        else
            printf("20 test fait : %02d:%02d.%03d ms\n\n", Res[0], Res[1], Res[2]);

        int n = i + 1;

        while (n < 20)
        {
            fprintf(Result, "NULL;");
            n++;
        }

        fprintf(Result, "%f\n", CalcAverage(Time, i));
        TotalTime = 0;
        ResetTime(Time);

		if (echec) break;
    }
    CloseCSV(Result);
}


/**
 * \fn initSizesUseForTests ()
 * \author Julien TEULLE
 * \brief Initialize the values of sizesUseForTests for the tests.
 */
void initSizesUseForTests ()
{
    sizesUseForTests[0]  = 100;
    sizesUseForTests[1]  = 500;
    sizesUseForTests[2]  = 5000;
    sizesUseForTests[3]  = 10000;
    sizesUseForTests[4]  = 50000;
    sizesUseForTests[5]  = 100000;
    int i;
    for (i = 6; i < numberOfSizesToUse; i++)
        sizesUseForTests[i] = sizesUseForTests[i-1] + 100000;
    /*for (i = 0; i < numberOfSizesToUse; i++)
      sizesUseForTests[i] /= 100;*/
}

void check_sort(TRI * tri)
{
    int tab[sizeOfCheckTab];
    fillWithRandomNumbers(tab, sizeOfCheckTab);
    displayTab(tab, sizeOfCheckTab);
    tri->sort(tab, sizeOfCheckTab);
    displayTab(tab, sizeOfCheckTab);
}

int main ()
{
    srand(time(NULL));
    CreateCSV();

    initSizesUseForTests();

    TRI Sequential = SequentialInsertionSort_Create();
    TRI Dichotomous = DichotomousSort_Create();
    TRI SelectionSwap = SelectionSwapSort_Create();
    TRI Bubbles = BubbleSort_Create();
    TRI Merge = MergeSort_Create();
    TRI Quick = QuickSort_Create();
    TRI Stack = StackSort_Create();
    TRI ABR   = Binary_search_tree_sort_Create();
    TRI SequentialList = SequentialInsertionSort_Create();

    DoSort(&Sequential, 0);
    DoSort(&Dichotomous, 0);
    DoSort(&SelectionSwap, 0);
    DoSort(&Bubbles, 0);
    DoSort(&Merge, 0);
    DoSort(&Quick, 0);
    DoSort(&Stack, 0);
    DoSort(&ABR, 0);
    DoSort(&SequentialList, 1); 
    return 0;
}
