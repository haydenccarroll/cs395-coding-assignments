/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * tower of hanoi
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void towerOfHanoiR(int n, char starting, char ending, char other);

// main function that gets a command line argument n and prints 2^n
int main(int argc, char *argv[])
{
   int n = atoi(argv[1]);
   towerOfHanoiR(n, 'A', 'C', 'B');
}

// recurisve tower of hanoi function
void towerOfHanoiR(int n, char starting, char ending, char other)
{
   if (n == 0)
   {
      return;
   }
   else
   {
      towerOfHanoiR(n-1, starting, other, ending);
      printf("moved %c to %c\n", starting, ending);
      towerOfHanoiR(n-1, other, ending, starting);
   }
}
