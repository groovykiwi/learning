#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studinfo
{
    int stnr;
    char name[10];
    int grade;
};

// Returns index of entry or -1 if not found
int binarySearch(struct studinfo arr[], int num, int bot, int top)
{
    while (top != bot)
    {
        int mid = (top + bot) / 2;

        // Debugging purposes
        printf("top: %d bot: %d mid: %d     [%d %s %d]\n", top, bot, mid, arr[mid].stnr, arr[mid].name, arr[mid].grade);

        if (num == arr[mid].stnr)
            return mid;
        else if (num > arr[mid].stnr)
            bot = mid + 1;
        else
            top = mid - 1;
    }
    return -1;
}

int main()
{
    struct studinfo s[10];
    int entries = 0;
    char current_name[12];
    FILE *file = fopen("first.txt", "r");

    while (!feof(file))
    {
        fscanf(file, "%d %s %d", &s[entries].stnr, current_name, &s[entries].grade);
        strcpy(s[entries].name, current_name);
        entries++;
    }
    fclose(file);

    int std_num;
    printf("\nEnter student number to search for: ");
    scanf("%d", &std_num);

    int std_index = binarySearch(s, std_num, 0, 9);

    if (std_index != -1)
        printf("\nThe student was found at index %d: %s %d/100\n", std_index, s[std_index].name, s[std_index].grade);
    else
        printf("\nThe student was not found\n");

    // system("pause");
    return 0;
}
