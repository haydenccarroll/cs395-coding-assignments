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

// main function that takes in command line arguments such as ./w01.exe 1 2 65 3..
int main(int argc, char *argv[])
{
   if (argc <= 2)
   {
      printf("%s 4 9 6 2\n", argv[0]);
      return EXIT_FAILURE;
   }
   int myArray[argc -1];
   int n;
   for (n=1; n < argc; n++)
   {
      myArray[n-1] = atoi(argv[n]);
   }
   int lowestDistance = abs(myArray[1] - myArray[0]);

   int i;
   for (i=0; i < argc-1; i++)
   {
      int z;
      for (z=0; z < argc-1; z++)
      {
         if (i != z && abs(myArray[i] - myArray[z]) < lowestDistance)
         {
            lowestDistance = abs(myArray[i] - myArray[z]);
         }
      }
   }
   printf("%d\n", lowestDistance);
   return EXIT_SUCCESS;
}
