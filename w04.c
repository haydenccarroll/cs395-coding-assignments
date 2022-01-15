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

void printMatrix(int numRow, int numCol, float myArray[numRow][numCol]);

// main function that gets a command line argument n and prints 2^n
int main(int argc, char *argv[])
{
   int numRow = atoi(argv[1]);
   int numCol = (argc-2) / numRow;
   float myArray[numRow][numCol];
   
   // create 2D array
   int a;
   for (a=2; a < argc; a++)
   {
      myArray[(a-2) / numCol][(a-2) % numCol] = atoi(argv[a]);
   }

   printMatrix(numRow, numCol, myArray);
   int i;
   for (i=0; i < numRow-2; i++)
   {
      int j;
      for (j=i+1; j < numRow-1; j++)
      {
         float tempji = myArray[j][i];

         int k;
         for (k=i; k < numRow; k++)
         {
            myArray[j][k] = myArray[j][k] - (myArray[i][k] * tempji / myArray[i][i]);
         }
      }
      printMatrix(numRow, numCol, myArray);

   }

   return EXIT_SUCCESS;
}

// prints a matrix
void printMatrix(int numRow, int numCol, float myArray[numRow][numCol])
{
   int c, d;
   for (c = 0; c < numRow; c++)
   {
      for (d = 0; d < numCol; d++)
      {
         printf("%.2f ", myArray[c][d]);
      }
      printf("\n");
   }
   printf("\n");
}