#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studinfo
{
    int stnr;
    char name[10];
    int grade;
};
void main()
{
    struct studinfo s[10];
    int counter = 0;
    FILE *file;
    file = fopen("first.txt", "r");
    int stnr, grade;
    char current_name[12];
    while (!feof(file))
    {
        fscanf(file, "%d %s %d", &stnr, current_name, &grade);
        strcpy(s[counter].name, current_name);
        s[counter].stnr = stnr;
        s[counter].grade = grade;

        counter++;
    }

    fclose(file);

    int bot, top, mid, num;
    printf("Enter student number to search for: ");
    scanf("%d", &num);

    counter = 0;
    top = 10;
    bot = 0;

    do
    {
        mid = (top + bot) / 2;
        printf("mid: %d top: %d bot: %d %d %s %d\n", mid, top, bot, s[mid].stnr, s[mid].name, s[mid].grade);
        if (num == s[counter].stnr)
        {
            printf("found");
            break;
        }
        else if (num > s[counter].stnr)
        {
            bot = mid + 1;
        }
        else
        {
            top = mid - 1;
        }

        counter++;
    } while (1);
}
