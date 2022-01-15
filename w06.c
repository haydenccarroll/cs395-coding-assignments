/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * tower of hanoi - restricted (cant move from a to c directly or vice versa)
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

void towerOfHanoiR(int n, char starting, char ending, char other);

// main function
int main(int argc, char *argv[])
{
   int n = atoi(argv[1]);
   towerOfHanoiR(n, 'A', 'C', 'B');


   return EXIT_SUCCESS;
}

// recurisve strict tower of hanoi
void towerOfHanoiR(int n, char starting, char ending, char other)
{
   if (n == 0)
   {
      return;
   }
   else
   {
      if (starting == 'A' && ending == 'C') // if moving A to C, first move whole stack to B then B to C
      {
         towerOfHanoiR(n, starting, 'B', 'C');
         towerOfHanoiR(n, 'B', 'C', 'A');
      }

      else if (starting == 'C' && ending == 'A') // if moving C to A, first move whole stack to B then B to A
      {
         towerOfHanoiR(n, starting, 'B', 'A');
         towerOfHanoiR(n, 'B', 'A', 'C');
      }
      else
      {
         towerOfHanoiR(n-1, starting, other, ending);
         printf("MOVE %c TO %c\n", starting, ending);
         towerOfHanoiR(n-1, other, ending, starting);
      }
   }
}
