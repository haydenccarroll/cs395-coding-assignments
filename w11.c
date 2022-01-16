/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * Insertion Sort
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

void PrintArray(int myArray[], int arraySize, int split);
void InsertionSort(int myArray[], int arraySize);

// main function
int main(int argc, char *argv[])
{
   int arraySize = argc-1;
   int myArray[arraySize];

   int i;
   for (i=0; i < arraySize; i++)
   {
      myArray[i] = atoi(argv[i+1]);
   }

   InsertionSort(myArray, arraySize);

   return EXIT_SUCCESS;
}

// prints the array
void PrintArray(int myArray[], int arraySize, int split)
{
   int i;
   for (i = 0; i < arraySize; i++)
   {
      if (i == split)
      {
         printf("| ");
      }
      printf("%d ", myArray[i]);
   }
   printf("\n");
}

//implementation of the insertion sort sorting algorithm
void InsertionSort(int myArray[], int arraySize)
{
   int i;
   for (i=1; i < arraySize; i++)
   {
      PrintArray(myArray, arraySize, i);

      int v =  myArray[i]; // current value of array
      int j = i -1;
      while (j >= 0 && myArray[j] > v)
      {
         myArray[j+1] = myArray[j];
         j--;
      }
      myArray[j+1] = v;
   }
   int z;
   for (z = 0; z < arraySize; z++)
   {
      printf("%d ", myArray[z]);
   }
   printf(" | \n");
}