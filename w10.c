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

void QuickSort(int myArray[], int low, int high, int arraySize);
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
   PrintArray(myArray, 0, arraySize-1, arraySize);

   return EXIT_SUCCESS;
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
      PrintArray(myArray, low, high, arraySize);
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
