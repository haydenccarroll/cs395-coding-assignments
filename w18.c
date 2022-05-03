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

bool searchForFullSubgraph(int** graph, int numNodes, int levelToSearch);


int main(int argc, char *argv[])
{
   int numNodes = atoi(argv[1]);
   argv += 2;
   int numToReadIn = numNodes-1;
   int i=0;
   int currSpotInArgv = 0;
   int** adjacencyMatrix = malloc(sizeof(int*) * numNodes);
   for (i=0; i < numNodes-1; i++)
   {
      adjacencyMatrix[i] = malloc(sizeof(int) * numNodes);
      adjacencyMatrix[i][i] = 1;
      int j;
      for (j=0; j < numNodes-1-i; j++)
      {
         adjacencyMatrix[i][j] = atoi(argv[currSpotInArgv]);
         currSpotInArgv++;
      }
   }

   for (i=0; i < numNodes-1; i++)
   {
      int j;
      for (j=0; j < numNodes-i-1; j++)
      {
         printf("%d ", adjacencyMatrix[i][j]);
      }
      printf("\n");
   }

   return EXIT_SUCCESS;
}

bool searchForFullSubgraph(int** graph, int numNodes, int levelToSearch)
{
   int i;
   for (i = 0; )
}