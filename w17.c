/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * Modified Robot Coin Collecting
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int**  RobotCoinCollection(char** board, int** table);


int main(int argc, char *argv[])
{
   int numRows = atoi(argv[1]);
   int numCols = atoi(argv[2]);

   // create the board and the coin collecting table
   int** board = malloc(sizeof(int*) * numRows);
   int** table = malloc(sizeof(int*) * numRows);
   int a;
   for (a=0; a < numRows; a++)
   {
   board[a] = malloc(sizeof(char) * numCols);
   table[a] = malloc(sizeof(int) * numCols);
   }

   printf("Board Inputed:\n");
   int b;
   for (b=0; b < numRows; b++)
   {
      int j;
      for (j=0; j < numCols; j++)
      {
         char* val = argv[b*numCols + j + 3];
         if (val[0] == 'X')
         {
            board[b][j] = -10000;
            printf("X\t");
         }
         else
         {
            board[b][j] = atoi(val);
            printf("%s\t", val);
         }

      }
      printf("\n");
   }
   
   printf("\nCoin Collecting Table:\n");

   table[0][0] = board[0][0];
   printf("%d\t", table[0][0]);
   int j;
   for (j=1; j < numCols; j++)
   {
      if (table[0][j-1] < 0 || board[0][j] < 0)
      {
         table[0][j] = -10000;
         printf("0\t");
         continue;
      }
      else
      {
         table[0][j] = table[0][j-1] + board[0][j];
         if (table[0][j] < 0)
         {
            printf("0\t");
         }
         else
         {
            printf("%d\t", table[0][j]);
         }
      }

   }
   printf("\n");
   int i;
   for (i=1; i < numRows; i++)
   {
      table[i][0] = table[i-1][0] + board[i][0];
      if (table[i][0] < 0)
      {
         printf("0\t");
      }
      else
      {
         printf("%d\t", board[i][0]);
      }
      int j;
      for (j=1; j < numCols; j++)
      {
         int max;
         if (table[i-1][j] > table[i][j-1])
         {
             max = table[i-1][j]  + board[i][j];
         }
         else
         {
            max = table[i][j-1] + board[i][j];
         }
         table[i][j] = max;
         if (table[i][j] < 0)
         {
            printf("0\t");
         }
         else
         {
            printf("%d\t", table[i][j]);
         }
      }
      printf("\n");
   }

   printf("\nThe optimal path with this board is: %d\n", table[numRows-1][numCols-1]);
   return EXIT_SUCCESS;
}