/**
 * \file tp-MAN.c
 * \brief Programme de tests.
 * \author Julien TEULLE
 * \version 1
 * \date 14/09/16
 *
 * Programme de test pour divers tri
 *
 */

#include "stdlib.h"
#include "time.h"
#include "stdio.h"
#include "QuickSort.h"
#include "SequentialInserstionSort.h"
#include "DichotomousInserstionSort.h"
#include "mergeSort.h"

#define MAX 1000000
#define numberOfSizesToUse 15
typedef int TABLEAU[MAX];

//Global variables
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
 * \fn display (int tab[], int size)
 * \author Julien TEULLE
 * \brief Show the content of a table with one element per line.
 * \param tab The table which is display.
 * \param size The size of tab.
 */
void display (int tab[], int size)
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
	
	char * Titre[23];
	
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
	
	fprintf(ResultTest, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
		Titre[0], Titre[1], Titre[2], Titre[3], Titre[4], Titre[5], Titre[6], Titre[7], Titre[8], Titre[9], 
		Titre[10], Titre[11], Titre[12], Titre[13], Titre[14], Titre[15], Titre[16], Titre[17], Titre[18], Titre[19], 
		Titre[20], Titre[21], Titre[22]);
		
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
double CalcAverage (double Time[])
{
	double Average = 0;
	int i;
	
	for (i = 0; i < 20; ++i)
		Average += Time[i];
	
	Average /= 20;
	return Average;
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
void DoSort ()
{	
	int j;
	int i;
	double TotalTime = 0;
	int size;
	double Time[20];
	FILE * Result = OpenCSV();
	
	//insertion sequentiel, insertion dichotomique, selection-permutation, bulles, fusion, quicksort, arbre binaire de recherche, tas
	//        DONE        ,         DONE          ,                      ,       ,  DONE ,   DONE   ,                           ,     

	for (j = 0; j < 15; ++j)
	{
		size = sizesUseForTests[j];
		printf ("Tri Par Insertion Séquentielle - %d\n", size);
		int tab[size];
		fprintf(Result, "Tri Par Insertion Séquentielle;%d;", size);
		for (i = 0; i < 20; ++i)
		{
			fillWithRandomNumbers(tab, size);
			begin = clock();
			sequentialInsertionSort(tab, size);
			end = clock();
			Time[i] = getTimeElapsedInMilliseconds();
			fprintf(Result, "%f;", Time[i]);
			TotalTime += Time[i];
			if (TotalTime > 300000) // 5min = 300000ms
				break;
		}//NULL quand temps > 5min
		printf("20 test fait en %f ms \n\n", TotalTime);
		fprintf(Result, "%f\n", CalcAverage(Time));
		TotalTime = 0;
		ResetTime(Time);
	}
	
	for (j = 0; j < 15; ++j)
	{
		size = sizesUseForTests[j];
		printf ("Tri Par Insertion Dichotomique - %d\n", size);
		int tab[size];
		fprintf(Result, "Tri Par Insertion Dichotomique;%d;", size);
		for (i = 0; i < 20; ++i)
		{
			fillWithRandomNumbers(tab, size);
			begin = clock();
			dichotomousInsertionSort(tab, size);
			end = clock();
			Time[i] = getTimeElapsedInMilliseconds();
			fprintf(Result, "%f;", Time[i]);
			TotalTime += Time[i];
			if (TotalTime > 300000)
				break;
		}
		printf("20 test fait en %f ms \n\n", TotalTime);
		fprintf(Result, "%f\n", CalcAverage(Time));
		TotalTime = 0;
		ResetTime(Time);
	}
	
	for (j = 0; j < 15; ++j)
	{
		size = sizesUseForTests[j];
		printf ("Tri Par Fusion - %d\n", size);
		int tab[size];
		fprintf(Result, "Tri Par Fusion;%d;", size);
		for (i = 0; i < 20; ++i)
		{
			fillWithRandomNumbers(tab, size);
			display(tab, size);
			begin = clock();
			LaunchMS(tab, size);
			end = clock();
			display(tab, size);
			Time[i] = getTimeElapsedInMilliseconds();
			fprintf(Result, "%f;", Time[i]);
			TotalTime += Time[i];
			if (TotalTime > 300000) // 5min = 300000ms
				break;
		}//NULL quand temps > 5min
		printf("20 test fait en %f ms \n\n", TotalTime);
		fprintf(Result, "%f\n", CalcAverage(Time));
		TotalTime = 0;
		ResetTime(Time);
	}
	
	for (j = 0; j < 15; ++j)
	{
		size = sizesUseForTests[j];
		printf ("Tri Rapide - %d\n", size);
		int tab[size];
		fprintf(Result, "Tri Rapide;%d;", size);
		for (i = 0; i < 20; ++i)
		{
			fillWithRandomNumbers(tab, size);
			begin = clock();
			LaunchQS(tab, size);
			end = clock();
			Time[i] = getTimeElapsedInMilliseconds();
			fprintf(Result, "%f;", Time[i]);
			TotalTime += Time[i];
			if (TotalTime > 300000) // 5min = 300000ms
				break;
		}//NULL quand temps > 5min
		printf("20 test fait en %f ms \n\n", TotalTime);
		fprintf(Result, "%f\n", CalcAverage(Time));
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
	
	DoSort();
	
    /*int i;
	for (i = 0; i < numberOfSizesToUse; i++)
	{
		int currentSizeUse = sizesUseForTests[i];
		int tab[currentSizeUse];
		
		//initialization
		fillWithRandomNumbers(tab, currentSizeUse);
		
		//test
		begin = clock();
		dichotomousInsertionSort(tab, currentSizeUse);
		end = clock();
		
		//show time
		displayTimeElapsedInMilliseconds();
	}*/
    return 0;
}
