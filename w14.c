/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * Horspools algorithm
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

int* ShiftTable(char needle[], int m);
int HorspoolMatching(char needle[], char haystack[], int m, int n);
void printShiftTable(int table[]);

// main function
int main(int argc, char *argv[])
{
   int i=0;
   while (1)
   {
      if (argv[1][i] == '\0')
      {
         break;
      }
      i++;
   }

   int z=0;
   while (1)
   {
      if (argv[2][z] == '\0')
      {
         break;
      }
      z++;
   }
   HorspoolMatching(argv[1], argv[2], i, z);
   return EXIT_SUCCESS;
}


//Fills the shift table used by Horspool’s and Boyer-Moore algorithms
//Input: Pattern P[0..m − 1] and an alphabet of possible characters
//       For your assignment the set of characters are the ASCII characters 0-127
//Output: Table[0..size − 1] indexed by the alphabet’s characters and
// filled with shift sizes computed by formula (7.1)
int* ShiftTable(char needle[], int m)
{
   int size = 128; 
   int i;
   int* Table = (int *) malloc(size*sizeof(int));
   for (i=0; i < size; i++)
   {
      Table[i] = m;
   }
   int j;
   for (j=0; j < m-1; j++)
   {
      Table[(int) needle[j]] = m-1-j;
   }
   printShiftTable(Table);
   return Table;
}

//Implements Horspool’s algorithm for string matching
//Input: Pattern needle[0..m − 1] and text haystack[0..n − 1]
//Output: The index of the left end of the first matching substring
// or −1 if there are no matches
int HorspoolMatching(char needle[], char haystack[], int m, int n)
{
   int* Table = ShiftTable(needle, m); //generate Table of shifts
   int matches[n];
   int matchNum = 0;
   printf("%s\n", haystack);
   int i = m-1; //position of the pattern’s right end
   while (i <= n-1)
   {
      int k = 0; //number of matched characters
      while (k <= m-1 && needle[m-1-k] == haystack[i-k])
      {
         k++;
      }
      if (k == m)
      {
         printf("%*s%s---found\n", i-m+1,"", needle);
         matchNum++;
         matches[matchNum] = i-m+1;
      }
      else
      {
         printf("%*s%s\n", i-m+1, "", needle);
      }
      i += Table[(int) haystack[i]];
   }
   printf("Matches found at locations:");
   for(i = 0; i < matchNum; i++)
   {
      printf(" %d", matches[i]);
   }
   printf("\n");
   return -1;
}

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32
//Print out the shift table starting at the first writable character (space)
void printShiftTable(int table[])
{
   int i, start;
   for(start = MIN_WRITEABLE; start < MAX_ALPHABET; start+=TABLE_ROW_LENGTH)
   {
      for(i = start; i < start+TABLE_ROW_LENGTH; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");

      for(i = start; i < start+TABLE_ROW_LENGTH; i++)
      {
         printf("%d\t", table[i]);
      }
      printf("\n\n");

   }
}
