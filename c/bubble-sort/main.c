#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numbers[150];
    int num, counter = 0;

    while (counter <= 150)
    {
        num = rand() % 600 + 1;
        int add = 1;
        for (int i = 0; i < 150; i++)
        {
            if (num == numbers[i])
            {
                counter--;
                add = 0;
            }
        }
    }
};