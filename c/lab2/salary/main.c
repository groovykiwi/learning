#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persalary
{
    int month;
    long salary;
};

struct employee
{
    int emp;
    char name[12];
    struct persalary salaries[3];
    long sum;
    float avg;
};

void listEmployees(struct employee a[])
{
    char *months[12] =
        {"January", "February", "March", "April", "May", "June", "July",
         "August", "September", "October", "November", "December"};

    // Print data
    printf("Employee Number         Name        Month       Salary\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%15d", a[i].emp);
        printf("%13s", a[i].name);
        printf("%13s %12u\n", months[a[i].salaries[0].month - 1], a[i].salaries[0].salary);
        printf("%41s %12u\n", months[a[i].salaries[1].month - 1], a[i].salaries[1].salary);
        printf("%41s %12u\n\n", months[a[i].salaries[2].month - 1], a[i].salaries[2].salary);
    }
}

void showAverage(struct employee a[])
{
    // Calculations
    int i, j;
    for (i = 0; i < 4; i++)
    {
        a[i].sum = 0;
        for (j = 0; j < 3; j++)
            a[i].sum = a[i].sum + a[i].salaries[j].salary;
        a[i].avg = (float)a[i].sum / 3;
    }

    // Output
    printf("Employee Number    Name      Average         Sum\n");
    for (i = 0; i < 4; i++)
    {
        printf("%15d", a[i].emp);
        printf("%8s", a[i].name);
        printf("%13.0f", a[i].avg);
        printf("%12u\n", a[i].sum);
    }
}

int main()
{
    struct employee a[4];
    int emp, m1, m2, m3;
    long s1, s2, s3;
    char current_name[12];
    int p;

    FILE *f = fopen("emp.txt", "r");

    if (f == NULL)
    {
        perror("File does not exist.\n");
        return 1;
    }

    p = 0; // People Counter

    while (feof(f) == 0)
    {
        fscanf(f, "%d %s %d %ld %d %ld %d %ld", &emp, current_name, &m1, &s1, &m2, &s2, &m3, &s3);
        a[p].emp = emp;
        strcpy(a[p].name, current_name);
        a[p].salaries[0].month = m1;
        a[p].salaries[0].salary = s1;
        a[p].salaries[1].month = m2;
        a[p].salaries[1].salary = s2;
        a[p].salaries[2].month = m3;
        a[p].salaries[2].salary = s3;

        p++;
    }

    listEmployees(a);

    showAverage(a);

    return 0;
}