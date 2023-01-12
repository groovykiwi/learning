#include <stdbool.h>
#include <stdio.h>
#define LENGTH 50

char *maskify(char *masked, const char *string)
{
    int l = 0;
    int i;
    char *temp = masked;

    while (*string)
    {
        *temp = '#';
        temp++;
        string++;
        l++;
    }

    *temp = '\0';

    if (l > 4)
    {
        for (i = 0; i < 5; i++)
        {
            *temp = *string;
            temp--;
            string--;
        }
    }
    else
    {
        for (i = 0; i < l + 1; i++)
        {
            *temp = *string;
            temp--;
            string--;
        }
    }

    return masked;
}

int main()
{
    char test[LENGTH] = "";
    char masked[LENGTH];
    char *p = test;
    char *m = masked;

    char *ans = maskify(m, p);
    printf("\nNormal: ");
    while (*p)
    {
        printf("%c", *p);
        p++;
    }

    printf("\nMasked: ");
    while (*ans)
    {
        printf("%c", *ans);
        ans++;
    }
}