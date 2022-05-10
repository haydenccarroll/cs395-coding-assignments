


//Finds a maximum matching in a bipartite graph by a BFS-like traversal
//Input: A bipartite graph G = Adjacenty Matrix
//Output: A maximum-cardinality matching M (array of (V,U) edges in the input graph

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
int getULoc(int M[MAX_BOARD][2], int u);
int isElemOfM(int M[MAX_BOARD][2], int w, int u);
int reInitializeQ(int Q[MAX_BOARD], int M[MAX_BOARD][2], int VVertices);
int** MaximumBipartiteMatching(int G[MAX_BOARD][MAX_BOARD], int VVertices, int UVertices);


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

   MaximumBipartiteMatching(G, numVVertices, numUVertices);
   return EXIT_SUCCESS;

   
}

int** MaximumBipartiteMatching(int G[MAX_BOARD][MAX_BOARD], int VVertices, int UVertices)
{
   printGraph(G, VVertices);
   int M[MAX_BOARD][2];
   int startM = 0;
   int endM = 0;
   int i;
   for (i=0; i < MAX_BOARD; i++) // initialize matches with -1s
   {
      M[i][0] = BCEMPTY;
      M[i][1] = BCEMPTY;
   }
   int Q[MAX_BOARD]; // initalize Q;
   reInitializeQ(Q, M, VVertices);

   while (isEmpty(Q) == 0)
   {
      printQueue(Q, qStart, qEnd);
      int w; 
      w = top(Q);
      dequeue(Q);
      // W is a member of V
      if (w < VVertices) 
      {
         printf("W IS A MEMBER OF V\n");
         i=0;
         while (G[w][i] != BCEMPTY) // loop through all u connections for a given v
         {
            int u = G[w][i];
            int v;
            // if u is free
            if (isUFree(M, u) == 1)
            {
               printf("U IS FREE\n");

               // augment
               M[endM][0] = w;
               M[endM][1] = u;
               endM++;
               v = w;
               // while (vIsLabeled(M, v))
               // {
               //    // u = vertex indicated by vs label; M <- M - (v,u)
               //    // v = vertex indicated by us label; M <- M U (v,u)
               // }
               // remove all vertex labels
               // reinitialize q with available vertices
               reInitializeQ(Q, M, VVertices);
               break;
            }
            else // u is already matched.
            {
               if (isElemOfM(M, w, u)) // AND U IS UNLABELED
               {
                  // label u with w
                  enqueue(Q, u);
                  break;
               }
               else if (!isElemOfM(M, w, u)) // AND U IS UNLABELED
               {
                  // label u with w
                  enqueue(Q, u);
                  break;
               }

            }
            i++;
         }
      }
      
      else // is a member of U (and matched)
      {
         int loc = getULoc(M, w);
         int v = M[loc][0];
         // enqueue(Q, v);

      }
      
      printM(M, startM, endM);
   }
   // initialize set M of edges with some valid matching (e.g., the empty set)
   // initialize queue Q with all the free vertices in V (in any order)
   // while not Empty(Q) do
   //    printQueue(Q)
   //    w←Front(Q); Dequeue(Q)
   //    if w is an element of V
   //       for every vertex u adjacent to w do
   //          if u is free
   //             //augment
   //             M ←M ∪ (w, u)
   //             v←w
   //             while v is labeled do
   //                u←vertex indicated by v’s label; M ←M − (v, u)
   //                v←vertex indicated by u’s label; M ←M ∪ (v, u)
   //             remove all vertex labels
   //             reinitialize Q with all free vertices in V
   //             break //exit the for loop
   //          else //u is matched
   //             if (w, u) is not an element of M and u is unlabeled
   //                label u with w
   //                Enqueue(Q, u)
   //     else //w is an element of U (and matched)
   //       label the mate v of w with w
   //       Enqueue(Q, v)
   //    printM(M)
   // return M //current matching is maximum
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

int getULoc(int M[MAX_BOARD][2], int u)
{
   int i;
   for (i=0; i < MAX_BOARD; i++)
   {
      if (M[i][1] == BCEMPTY)
      {
         return -1;
      }

      if (M[i][1] == u)
      {
         return i;
      }
   }

   return -1;
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