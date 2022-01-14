/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * Finds the shortest distance between any two items in an array
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

#define INTMAX 2147483647
void quickSort(int array[], int low, int high);
// main function that takes in command line arguments such as ./w01.exe 1 2 65 3..
int main(int argc, char *argv[])
{
   int myArray[argc -1];
   int n;
   for (n=1; n < argc; n++)
   {
      myArray[n-1] = atoi(argv[n]);
   }
   quickSort(myArray, 0, argc-2);
   int lowestDistance = myArray[1] - myArray[0];


   int i;
   for (i = 0; i < argc-2; i++)
   {
      int distance = myArray[i+1] - myArray[i];
      if (distance < lowestDistance)
      {
         lowestDistance = distance;
      }
   }
   printf("%d\n", lowestDistance);
   return EXIT_SUCCESS;
}

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}
