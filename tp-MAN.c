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

#include "QuickSort.h"
#include "SequentialInsertionSort.h"
#include "DichotomousInsertionSort.h"
#include "mergeSort.h"
#include "SelectionSwapSort.h"
#include "bubbleSort.h"


/***********CONSTANTS***********/
#define MAX 1000000
#define numberOfSizesToUse 15
#define numberOfTestsToDo  20
#define numberOfTitles     23

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
    srand(time(NULL));
    int i = 0;
    for (; i < size; i++)
    {
        tab[i] = (int) rand() % 100;
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
    for (; i < size; i++)
    {
        printf("%d %d\n", i, tab[i]);
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

int CalcMinute (double Time)
{
	return Time / 60000;
}

int CalcSeconde (double Time)
{
	return Time / 1000;
}

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
 * \fn DoSort ()
 * \author Kurt SAVIO
 * \brief Create, fill and sort a table for each sort and size, 20 time 
 * each. Also calculate the average time, look out for the total time.
 * Then it writes all the result in the csv file. 
 */
void DoSort (TRI * t)
{	
    int i, j, size;
    double TotalTime = 0;
    double Time[20];
    FILE * Result = OpenCSV();

    //insertion sequentiel, insertion dichotomique, selection-permutation, bulles, fusion, quicksort, arbre binaire de recherche, tas
    //        DONE        ,         DONE          ,         DONE         ,  DONE ,  DONE ,   DONE   ,                           ,ToTest   

    //Tout Doux : arbre binaire de recherche, insertion sequentielle avec liste chainée
    
    for (j = 0; j < 15; ++j)
    {
        size = sizesUseForTests[j];
        printf ("Tri par %s - %d\n", t->name, size);
        int tab[size];
        fprintf(Result, "Tri par %s;%d;",t->name, size);
        for (i = 0; i < 20; ++i)
        {
            fillWithRandomNumbers(tab, size);
            begin = clock();
            t->sort(tab, size);
            end = clock();
            Time[i] = getTimeElapsedInMilliseconds();
            fprintf(Result, "%f;", Time[i]);
            TotalTime += Time[i];
            if (TotalTime > 300000) // 5min = 300000ms
                break;
        }
        
        int Res[3];
        CalcTotalTime(TotalTime, Res);
        
        if (i != 20)
        {
			printf ("Temps limite dépassé : %d:%d.%d\n\n", Res[0], Res[1], Res[2]);
			printf ("Uniquement %d tests fait\n\n", i);			
			
		}
		else
			printf("20 test fait : %d:%d.%d\n\n", Res[0], Res[1], Res[2]);
		
		int n = i;
		
		while (n < 20)
		{
			fprintf(Result, "NULL;");
			n++;
		}
		
        fprintf(Result, "%f\n", CalcAverage(Time, i));
        TotalTime = 0;
        ResetTime(Time);
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
    for (i = 0; i < numberOfSizesToUse; i++)
        sizesUseForTests[i] /= 100;
}

int main ()
{
    CreateCSV();

    initSizesUseForTests();

    TRI Sequential;
    //TRI Dichotomous;
    TRI SelectionSwap;
    TRI Bubbles;
    TRI Merge;
    TRI Quicksort = QuickSort_Create();
    
       DoSort(&Sequential);
       //DoSort(&Dichotomous);
       DoSort(&SelectionSwap);
       DoSort(&Bubbles);
       DoSort(&Merge);
       DoSort(&Quicksort);
       
    return 0;
}
