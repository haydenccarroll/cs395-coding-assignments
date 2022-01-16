/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * Brute force string match
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

// main function
int main(int argc, char *argv[])
{
   char* pattern = argv[1];
   char* string = argv[2];

   int i;
   printf("Matches found at locations: ");
   for (i=0; string[i] != '\0'; i++)
   {
      int j;
      int matchFound = 1;
      for (j=0; pattern[j] != '\0'; j++)
      {
         if (string[i+j] != pattern[j])
         {
            matchFound = 0;
         }
      }
      if (matchFound == 1)
      {
         printf("%d ", i);
      }
   }
   printf("\n\n");
   return EXIT_SUCCESS;
}
