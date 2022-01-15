/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * Finds the shortest distance between any two items in an array
 * FULL DISCLOSURE: I DID NOT CODE ANY OF THE QUICKSORT CODE.
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

int recursive2ncalc(int n);
// main function that takes in command line arguments such as ./w01.exe 1 2 65 3..
int main(int argc, char *argv[])
{
   int n = atoi(argv[1]);
   printf("%d\n", recursive2ncalc(n));
   return EXIT_SUCCESS;
}

int recursive2ncalc(int n)
{
   if (n < 1)
   {
      return 1;
   }
   return (recursive2ncalc(n-1) + recursive2ncalc(n-1));
}