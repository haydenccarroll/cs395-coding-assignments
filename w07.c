/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * tower of hanoi - cyclic (a to b, b to c, but a to c)
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

// recurisve circular tower of hanoi
void towerOfHanoiR(int n, char starting, char ending, char other)
{
   if (n == 0)
   {
      return;
   }
   else
   {
      if (starting == 'A' && ending == 'C')
      {
         towerOfHanoiR(n, 'A', 'B', 'C');
         towerOfHanoiR(n, 'B', 'C', 'A');
      }

      else if (starting == 'B' && ending == 'A')
      {
         towerOfHanoiR(n, 'B', 'C', 'A');
         towerOfHanoiR(n, 'C', 'A', 'B');
      }
      else if (starting == 'C' && ending == 'B')
      {
         towerOfHanoiR(n, 'C', 'A', 'B');
         towerOfHanoiR(n, 'A', 'B', 'C');
      }
      else
      {
         towerOfHanoiR(n-1, starting, other, ending);
         printf("MOVE %c TO %c\n", starting, ending);
         towerOfHanoiR(n-1, other, ending, starting);
      }
   }
}
