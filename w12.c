/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * Sorting comparisons
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>


// does selection sort and sorts the array
void SelectionSort(int myArray[], int n)
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
   }
}

// divides array into 2 subarrays, with left side being less than the pivot,
// and right side greater
int HoarePartition(int myArray[], int low, int high) 
{ 
   int pivot = myArray[low];

   int i = low, j = high+1;
   while(1)
   {
      do // find index where left ptr is greater than or equal to pivot
      {
         i++;
      } while(myArray[i] < pivot);
      do // find index where right ptr is less than or equal to pivot
      {
         j--;
      } while(myArray[j] > pivot);

      int tempI = myArray[i];
      myArray[i] = myArray[j];
      myArray[j] = tempI;
      if(i >= j)
      {
         // if ptrs touch, that means you covered the whole list, 
         // and everything to left is less than and everything to right is greater than
         break;
      }
   }

   int tempI = myArray[i];
   myArray[i] = myArray[j];
   myArray[j] = tempI;

   int tempJ = myArray[j];
   myArray[j] = myArray[low];
   myArray[low] = tempJ;

   // printf("%d %d %d %d %d\n", i,j,low,high,pivot);
   return j;
}

// implements quicksort
void QuickSort(int myArray[], int low, int high, int arraySize) 
{ 
   if (low < high) 
   {
      int split = HoarePartition(myArray, low, high); 

      // Separately sort elements before 
      // partition and after partition 
      QuickSort(myArray, low, split -1, arraySize);
      QuickSort(myArray, split +1, high, arraySize);
   } 
} 

//implementation of the insertion sort sorting algorithm
void InsertionSort(int myArray[], int arraySize)
{
   int i;
   for (i=1; i < arraySize; i++)
   {

      int v =  myArray[i]; // current value of array
      int j = i -1;
      while (j >= 0 && myArray[j] > v)
      {
         myArray[j+1] = myArray[j];
         j--;
      }
      myArray[j+1] = v;
   }
}

// main function
int main(int argc, char *argv[])
{
   srand(0);

   int powerSize = atoi(argv[1]);
   int y;
   int arraySize = 1;
   for (y=0; y < powerSize; y++)
   {
      arraySize *= 10;
   }
   int array1[arraySize];
   int array2[arraySize];
   int array3[arraySize];

   int i;
   // create 1 array
   for (i=0; i < arraySize; i++)
   {
      array1[i] = rand() % 10;
   }

   int z;
   // copy first array to 2 other arrays
   for (z=0; z < arraySize; z++)
   {
      array2[z] = array1[z];
      array3[z] = array1[z];
   }

   struct timeval start, stop;
   gettimeofday(&start, NULL);
   SelectionSort(array1, arraySize);
   gettimeofday(&stop, NULL);
   double SelectionTime = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;


   gettimeofday(&start, NULL);
   InsertionSort(array2, arraySize);
   gettimeofday(&stop, NULL);
   double InsertionTime = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   QuickSort(array3, 0, arraySize-1, arraySize);
   gettimeofday(&stop, NULL);
   double QuickTime = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   printf("Selection Sort Time: %f\nInsertion Sort Time: %f\nQuick Sort Time: %f\nNumber of Elements: %d\n", SelectionTime, InsertionTime, QuickTime, arraySize);

   return EXIT_SUCCESS;
}

//+-----------------------+-----------------+----------------+------------+
//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
//+-----------------------+-----------------+----------------+------------+
//|                    100|            0.007|           0.004|       0.003|
//|                   1000|            0.568|           0.332|       0.027|
//|                  10000|           47.569|          30.304|       0.292|
//+-----------------------+-----------------+----------------+------------+