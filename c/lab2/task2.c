#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x[3][4] = {
        {13.5, 24.88, 66.28, 30},
        {2.84, 412.15, 13.2, 9.9},
        {15.5, 38.89, 12.5, 16.18}};

    double y[12];
    int i, j;
    int count = 0;

    for (i = 0; i < 3; i++)
    {
        printf("| ");
        for (j = 0; j < 4; j++)
        {
            printf("%.2f ", x[i][j]);
            y[count] = x[i][j];
            count++;
        }
        printf("|\n");
    }

    printf("\n One dimentional array: | ");
    for (i = 0; i < 12; i++)
    {
        printf("%.2f ", y[i]);
    }
    printf("|\n");
}