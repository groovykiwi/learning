#include <stdio.h>

int main()
{

    int find_max(int a[], int n) // n is the number of elements in the a[]
    {
        int max;
        if (n == 1)
            return a[0];

        max = find_max(a, n - 1);
        if (a[n - 1] > max)
            max = a[n - 1];

        return max;
    };

    int find_min(int a[], int n) // n is the number of elements in the a[]
    {
        int min;
        if (n == 1)
            return a[0];

        min = find_min(a, n - 1);
        if (a[n - 1] < min)
            min = a[n - 1];

        return min;
    };

    int find_sum(int a[], int n)
    {
        if (n == 1)
            return a[0];
        return find_sum(a, n - 1) + a[n - 1];
    };

    int find_product(int a[], int n)
    {
        if (n == 1)
            return a[0];
        return find_sum(a, n - 1) * a[n - 1];
    };

    double find_average(int a[], int n)
    {
        if (n == 1)
            return a[n - 1];
        else
            return (find_average(a, n - 1) * (n - 1) + a[n - 1]) / n;
    }

    int arr[] = {1, 3, 2, 4};
    printf("Maximum: %d\n", find_max(arr, 4));
    printf("Minimum: %d\n", find_min(arr, 4));
    printf("Sum: %d\n", find_sum(arr, 4));
    printf("Product: %d\n", find_product(arr, 4));
    printf("Average: %.2f\n", find_average(arr, 4));
}