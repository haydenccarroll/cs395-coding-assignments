/********************************************************
 * Id: carr5440
 *
 * Permutations assignment w21
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>

void permutations(int *array, int n, int a);
void swap(int *array, int i, int j);
void printArray(int *array, int len);

// main function
int main(int argc, char *argv[])
{
   int len = atoi(argv[1]);
   int array[len];
   
   int i;
   for (i = 1; i <= len; i++)
   {
      array[i] = i;
   }
   
   permutations(array, len, 1);

   return EXIT_SUCCESS;

   
}

// prints all permutations of array, recursive
void permutations(int *array, int len, int a)
{
   int j;
   if(a == len)
   {
      int i;
      for (i = 1; i <= len; i++)
      {
         printf("%d", array[i]);
      }
      printf("\n");
   }
   for (j = a; j <= len; j++)
   {
      int temp; // swap
      temp = array[j];
      array[j] = array[a];
      array[a] = temp;
      permutations(array, len, a + 1);
      temp = array[j]; // swap again
      array[j] = array[a];
      array[a] = temp;
   }
}