#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc <= 2)
    {
        printf("%s 4 9 6 2\n", argv[0]);
        return 1;
    }

    int myArray[argc -1];
    myArray[0] = atoi(argv[1]);
    int smallestInt = myArray[0];
    int largestInt = myArray[0];

    for (int i=1; i < argc-1; i++)
    {
        myArray[i] = atoi(argv[i+1]);
        int currentInt = myArray[i];

        if (currentInt > largestInt)
        {
            largestInt = currentInt;
        }
        else if (currentInt < smallestInt)
        {
            smallestInt = currentInt;
        }
    }
    printf("%d\n", largestInt - smallestInt);
    return 0;
}
