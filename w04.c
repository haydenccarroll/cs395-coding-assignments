/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * gaussian elimination
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int n, float myArray[n][n+1]);

// main function that gets a command line argument n and prints 2^n
int main(int argc, char *argv[])
{
   int n = atoi(argv[1]);
   float myArray[n][n+1];
   
   // create 2D array
   int a;
   for (a=2; a < argc; a++)
   {
      myArray[(a-2) / (n+1)][(a-2) % (n+1)] = atoi(argv[a]);
   }

   // 1  2  3  4
   // 5  6  7  8
   // 9 10 11 12

   printMatrix(n, myArray);
   int j;
   for (j=0; j < n+1; j++) // LOOP THRU EVERY COLUMN
   {
      int i;
      for (i=j+1; i < n; i++) // LOOP THRU EVERY ROW
      {
         float multiplier = myArray[i][j] / myArray[j][j];
         int k;
         for (k=j; k < n+1; k++) // LOOP THRU EVERY COL LEFT IN THIS ROW
         {
            myArray[i][k] = myArray[i][k] - (multiplier * myArray[j][k]);
         }
      }
      printMatrix(n, myArray);
   }

   return EXIT_SUCCESS;
}

// prints a matrix
void printMatrix(int n, float myArray[n][n+1])
{
   int c, d;
   for (c = 0; c < n; c++)
   {
      for (d = 0; d < n+1; d++)
      {
         printf("%.2f ", myArray[c][d]);
      }
      printf("\n");
   }
   printf("\n");
}