/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * calculates 2^n
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

int recursive2ncalc(int n);

// main function that gets a command line argument n and prints 2^n
int main(int argc, char *argv[])
{
   int n = atoi(argv[1]);
   printf("%d\n", recursive2ncalc(n));
   return EXIT_SUCCESS;
}

// recursive function to calculate 2^n
int recursive2ncalc(int n)
{
   if (n < 1)
   {
      return 1;
   }
   return (recursive2ncalc(n-1) + recursive2ncalc(n-1));
}