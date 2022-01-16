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

void QuickSort(int arr[], int low, int high, int arraySize);
void PrintArray(int myArray[], int low, int high, int arraySize);
int HoarePartition(int myArray[], int left, int right);


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
   QuickSort(myArray, 0, arraySize-1, arraySize);
   return EXIT_SUCCESS;
}

// divides array into 2 subarrays, with left side being less than the pivot,
// and right side greater
int HoarePartition(int arr[], int low, int high) 
{ 
   int pivot = arr[low];

   int i = low-1, j = high+1;
   while(1)
   {
      do // find index where left ptr is greater than or equal to pivot
      {
         i++;
      } while(arr[i] < pivot);
      do // find index where right ptr is less than or equal to pivot
      {
         j--;
      } while(arr[j] > pivot);

      if(i >= j)
      {
            // if ptrs touch, that means you covered the whole list, 
            // and everything to left is less than and everything to right is greater than
         return j;
      }
      int tempI = arr[i];
      arr[i] = arr[j];
      arr[j] = tempI;
   }
}

// implements quicksort
void QuickSort(int arr[], int low, int high, int arraySize) 
{ 
   if (low < high) 
   { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
      int split = HoarePartition(arr, low, high); 

        // Separately sort elements before 
        // partition and after partition 
      QuickSort(arr, low, split, arraySize);
      QuickSort(arr, split + 1, high, arraySize);
      PrintArray(arr, low, high, arraySize);
   } 
} 
// prints the array
void PrintArray(int myArray[], int low, int high, int arraySize)
{
   int i;
   for (i = 0; i < arraySize; i++)
   {
      if (i == low)
      {
         printf("[%d ", myArray[i]);
      }
      else if (i == high)
      {
         printf("%d] ", myArray[i]);
      }
      else {
         printf("%d ", myArray[i]);
     }
   }
   printf("\n");
}
