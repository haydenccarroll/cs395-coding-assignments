/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * Quick sort
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

void QuickSort(int myArray[], int n);
void PrintArray(int myArray[], int n);

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

   QuickSort(myArray, arraySize);

   return EXIT_SUCCESS;
}

// does selection sort and sorts the array
void QuickSort(int myArray[], int left, int right)
{
   int i;
   int min;
   for (i=0; i < n-1; i++)
   {
      min = i;
      int j;
      for (j=i+1; j < n; j++)
      {
         if (myArray[j] < myArray[min])
         {
            min = j;
         }
      }
      if (min != i)
      {
         int tempI = myArray[i];
         myArray[i] = myArray[min];
         myArray[min] = tempI;
      }
      PrintArray(myArray, n);
   }
}

// prints the array
void PrintArray(int myArray[], int n)
{
   int i;
   for (i=0; i < n; i++)
   {
      printf("%d ", myArray[i]);
   }
   printf("\n");
}