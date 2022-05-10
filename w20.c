

/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * W20 is bipartite
 *********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_BOARD 1000
#define BCEMPTY -1

void printM(int M[][2], int start, int end);
void printQueue(int Queue[], int start, int end);
void printGraph(int G[MAX_BOARD][MAX_BOARD], int Vverticies);

void enqueue(int Q[MAX_BOARD], int val);
void dequeue(int Q[MAX_BOARD]);
int top(int Q[MAX_BOARD]);
int isEmpty(int Q[MAX_BOARD]);

int isUFree(int M[MAX_BOARD][2], int u);
int isVFree(int M[MAX_BOARD][2], int v);
int isElemOfM(int M[MAX_BOARD][2], int w, int u);
int reInitializeQ(int Q[MAX_BOARD], int M[MAX_BOARD][2], int VVertices);
int isBipartite(int G[MAX_BOARD][MAX_BOARD], int VVertices);

int qStart = 0;
int qEnd = 0;

// main function
int main(int argc, char *argv[])
{
   // initialize V vertices size and U Vertices size
   int numVVertices = atoi(argv[1]);
   int numUVertices = atoi(argv[2]);

   // initialize Graph
   int G[MAX_BOARD][MAX_BOARD];
   int i;
   for (i=0; i < MAX_BOARD; i++)
   {
      int j;
      for (j=0; j < MAX_BOARD; j++)
      {
         G[i][j] = BCEMPTY;
      }
   }

   // Read in graph
   argv += 2;
   argc -= 2;
   for (i=0; i < numVVertices; i++)
   {
      int j;
      for (j=0; j < numUVertices; j++)
      {
         argv++;
         argc--;
         if (argc == 0 || (*argv)[0] == 'X')
         {
            break;
         }

         G[i][j] = atoi(*argv);
      }
   }

   printGraph(G, numVVertices);

   isBipartite(G, numVVertices);
   return EXIT_SUCCESS;

   
}

int isBipartite(int G[MAX_BOARD][MAX_BOARD], int VVertices)
{
   int colorArr[MAX_BOARD];
   int i;
   for (i=0; i < MAX_BOARD; ++i)
   {
      colorArr[i] = 1;
   }
 
   // Assign first color to source
   colorArr[0] = 0;
 
   // Create a queue (FIFO) of vertex
   // numbers and enqueue source vertex
   // for BFS traversal
   int Q[MAX_BOARD];
   enqueue(Q, 0);

   while (!isEmpty(Q))
   {
      // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
      int u = top(Q);
      dequeue(Q);
      printf("HERE IS U: %d\n", u);

 
      // Return false if there is a self-loop
      if (G[u][u] == 1)
      {
         printf("THERE IS A SELF LOOP\n");
         return 0;
      }
                    
      // Find all non-colored adjacent vertices
      int v;
      for (v=0; v < MAX_BOARD; ++v)
      {
         // An edge from u to v exists and
         // destination v is not colored
         if (G[u][v] && colorArr[v] == -1)
         {
            // Assign alternate color to this adjacent v of u
            colorArr[v] = 1 - colorArr[u];
            enqueue(Q, v);
         }
 
         // An edge from u to v exists and destination
         // v is colored with same color as u
         else if (G[u][v] && colorArr[v] == colorArr[u])
         {
            printf("ITS COLORED SAME\n");
            return 0;
         }
      }
   }
 
   printf("YAY\n");
   // If we reach here, then all adjacent 
   // vertices can be colored with alternate color
   return 1;
}
   

// Note: These are my print functions. Your may vary if you have different data structures.
// Print the adjacentcy matrix.
void printGraph(int G[MAX_BOARD][MAX_BOARD], int Vverticies) {
   int i, j;
   for(i=0; i<Vverticies; i++)
   {
      printf("%d ->", i);
      j=0;
      while(G[i][j] != BCEMPTY)
      {
         printf(" %d", G[i][j]);
         j++;
      }
      printf("\n");
   }
}

// Print out the current contents of the queue for debugging
void printQueue(int Queue[], int start, int end) {
   int i;
   printf("Queue:");
   for(i=start; i<end; i++)
   {
      printf(" %d", Queue[i]);
   }
   printf("\n");
}

// Print out the currenlty found matchings
void printM(int M[][2], int start, int end) {
   int i;
   for(i=start; i<end; i++)
   {
      printf("\tV%d", M[i][0]);
   }
   printf("\n");

   for(i=start; i<end; i++)
   {
      printf("\t|");
   }
   printf("\n");

   for(i=start; i<end; i++)
   {
      printf("\tU%d", M[i][1]);
   }
   printf("\n");
}



int isUFree(int M[MAX_BOARD][2], int u)
{
   int i;
   for (i=0; i < MAX_BOARD; i++)
   {
      if (M[i][1] == BCEMPTY)
      {
         return 1;
      }

      if (M[i][1] == u)
      {
         return 0;
      }
   }

   return 1;
}

int isVFree(int M[MAX_BOARD][2], int v)
{
   int i;
   for (i=0; i < MAX_BOARD; i++)
   {
      if (M[i][0] == BCEMPTY)
      {
         return 1;
      }

      if (M[i][0] == v)
      {
         return 0;
      }
   }

   return 1;
}

int reInitializeQ(int Q[MAX_BOARD], int M[MAX_BOARD][2], int VVertices)
{
   int i;
   qStart = 0;
   qEnd = 0;
   for (i=0; i < VVertices; i++)
   {
      if (isVFree(M, i))
      {
         enqueue(Q, i);
      }

   }
   return 1;
}

int isElemOfM(int M[MAX_BOARD][2], int w, int u)
{
   int i;
   for (i=0; i < MAX_BOARD; i++)
   {
      if (M[i][0] == BCEMPTY)
      {
         return 0;
      }
      if (M[i][0] == w && M[i][1] == u)
      {
         return 1;
      }
   }
   return 0;
}

void enqueue(int Q[MAX_BOARD], int val)
{
   Q[qEnd] = val;
   qEnd++;


}
void dequeue(int Q[MAX_BOARD])
{
   qStart++;
}
int top(int Q[MAX_BOARD])
{
   return Q[qStart];
}
int isEmpty(int Q[MAX_BOARD])
{
   if (qStart >= qEnd)
   {
      return 1;
   }
   return 0;
}