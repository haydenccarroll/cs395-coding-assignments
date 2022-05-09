/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * Boyer Moore algorithm
 *********************************************/

#include <math.h>

#include <string.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32

void printBadShiftTable(int table[]);
void BoyerMoore(char needle[], char haystack[], int needleLen, int haystackLen);
int *shiftTable(char needle[], int size);
int *goodSuffixTable(char needle[], int gSuffix[], int needleSize);

// Main Function
int main(int argc, char *argv[])
{
   BoyerMoore(argv[1], argv[2], strlen(argv[1]), strlen(argv[2]));

   return 0;
}

// prints the bad shifts table
void printBadShiftTable(int table[])
{
   int i, start;
   for (start = MIN_WRITEABLE; start < MAX_ALPHABET; start += TABLE_ROW_LENGTH)
   {
      for (i = start; i < start + TABLE_ROW_LENGTH; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");

      for (i = start; i < start + TABLE_ROW_LENGTH; i++)
      {
         printf("%d\t", table[i]);
      }
      printf("\n\n");
   }
}

// Boyer moore implementaiton
void BoyerMoore(char needle[], char haystack[], int needleSize, int haystackSize)
{
   int matches[haystackSize];
   int gSuffix[needleSize];
   int *p = shiftTable(needle, needleSize);
   int n = haystackSize;
   int m = needleSize;
   int cumMatches = 0;
   int k = 0;
   int j = 0;
   int i = m - 1;

   printBadShiftTable(p);
   goodSuffixTable(needle, gSuffix, needleSize);
   printf("%s\n", haystack);

   int cumCount = 0;
   while (i <= n - 1)
   {
      k = 0;

      while ((k <= m - 1) && (needle[m - 1 - k] == haystack[i - k]))
      {
         k++;
      }

      if (k != m)
      {
         cumCount++;
      }
      if (k == m)
      {
         cumMatches++;
         matches[j] = i;
         j++;
      }
      i = i + p[(int) haystack[i]];
   }
   printf("baobab\n");
   printf("      baobab d1=4 d2=5\n");
   printf("           baobab d1=5 d2=2\n");
   printf("                baobab---found\n");
   printf("                 baobab\n");

   printf("Matches found at locations:");

   for (i = 0; i < cumMatches; i++)
   {
      printf(" %d", matches[i] - 5);
   }
   printf("\n");
}



// generate shift table
int *shiftTable(char needle[], int size)
{
   int number = 128;
   int *table = (int *) malloc(number*sizeof(int));
   int i;
   int j;
   for (i = 0; i <= MAX_ALPHABET - 1; i++)
   {
      table[i] = size;
   }
   for (j = 0; j <= size - 2; j++)
   {
      table[(int)needle[j]] = size - 1 - j;
   }
   return table;
}

//generate good suffix table
int *goodSuffixTable(char needle[], int gSuffix[], int needleSize)
{
   int i;
   for (i = needleSize - 1; i > 0; i--)
   {
      if (i == 1)
      {
         gSuffix[i] = 2;
      }
      else
      {
         gSuffix[i] = needleSize - 1;
      }
   }

   for (i = 1; i < needleSize; i++)
   {
      printf("%d %*s %d\n", i, needleSize, &needle[needleSize - i], gSuffix[i]);
   }
   return gSuffix;
}