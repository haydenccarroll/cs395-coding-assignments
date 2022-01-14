/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * Finds the shortest distance between any two items in an array
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

#define INTMAX 2147483647
// main function that takes in command line arguments such as ./w01.exe 1 2 65 3..
int main(int argc, char *argv[])
{
   int myArray[argc -1];
   int lowestDistance = INTMAX;

   myArray[argc-2] = atoi(argv[argc-1]);
   int i;
   for (i=0; i < argc-2; i++)
   {
      myArray[i] = atoi(argv[i+1]);
      int z;

      for (z=i+1; z < argc-1; z++)
      {
         int tempDistance = abs(myArray[i] - myArray[z]);
         if (i != z && tempDistance < lowestDistance)
         {
            lowestDistance = tempDistance;
         }
      }
   }
   printf("%d\n", lowestDistance);
   return EXIT_SUCCESS;
}
