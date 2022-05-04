/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * W18 cliques
 *********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int findConnectedSubgraph(int size, int matrix[][size], int row, int clique[], int total);
int findMaxConnectedSubgraph(int size, int matrix[][size]);

// Accepts command line arguments as elements of an array.
int main(int argc, char *argv[])
{
   int numNodes = atoi(argv[1]);
   int matrix[numNodes][numNodes];
   int i, j, k, count;

   // Read in matrix
   j = 0;
   for (k = 0; k < numNodes - 1; k++)
   {
      count = 0;
      for (i = k + 1; i < numNodes; i++)
      {
         matrix[k][i] = atoi(argv[2 + j + count]);
         count++;
      }
      j += count;
   }

    // make it a adjacency matrix
   for (i = 0; i < numNodes; i++)
   {
      for (j = 0; j < i + 1; j++)
      {
         matrix[i][j] = 0;
      }
   }
   for (i = 0; i < numNodes; i++)
   {
      for (j = 0; j < numNodes; j++)
      {
         matrix[j][i] = matrix[i][j];
      }
   }

   for (i = 0; i < numNodes; i++)
   {
      for (j = 0; j < numNodes; j++)
      {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }

   int result = findMaxConnectedSubgraph(numNodes, matrix);

   for (i = numNodes; i > 0; i--)
   {
      if (result < i)
      {
         printf("No clique found of size %d\n", i);
      }
      if (result == i)
      {
         printf("Clique found of size %d\n", i);
      }
   }
   return 0;
}

// Finds the clique from an adjacency matrix.
int findConnectedSubgraph(int numNodes, int matrix[][numNodes], int row, int clique[], int total)
{
   int i;
   int count = 0;
   for (i = 0; i < numNodes; i++)
   {
      if (clique[i] == 1 && matrix[row][i] == 1)
      {
         count++;
      }
   }

   if (total == count)
   {
      return 1;
   }
   return 0;
}

// Calculates and returns the max clique.
int findMaxConnectedSubgraph(int size, int matrix[][size])
{
   int i, j, k, a, count, maxconnSubgraph;
   int connSubgraph[size];

   maxconnSubgraph = 2;
   count = 1;
   for (a = 0; a < size; a++)
   {
      for (j = 0; j < size; j++)
      {
         connSubgraph[j] = 0;
      }

      connSubgraph[a] = 1;
      for (i = 0; i < size; i++)
      {
         k = 0;

         if (matrix[a][i] == 1)
         {
            k = findConnectedSubgraph(size, matrix, i, connSubgraph, count);
         }

         if (k == 1)
         {
            count++;
            connSubgraph[i] = 1;
         }
      }

      if (count > maxconnSubgraph)
      {
         maxconnSubgraph = count;
      }
      count = 1;
   }
   return maxconnSubgraph;
}
