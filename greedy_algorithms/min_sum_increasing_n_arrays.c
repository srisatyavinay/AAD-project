#include <stdio.h>
#define m 4

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        swap(&array[min_idx], &array[step]);
    }
}

int maximumSum(int a[][m], int n)
{
    for (int i = 0; i < n; i++)
        selectionSort(a[i], m);

    int sum = a[n - 1][m - 1];
    int prev = a[n - 1][m - 1];
    int i, j;

    for (i = n - 2; i >= 0; i--)
    {
        for (j = m - 1; j >= 0; j--)
        {
            if (a[i][j] < prev)
            {
                prev = a[i][j];
                sum += prev;
                break;
            }
        }

        if (j == -1)
            return 0;
    }

    return sum;
}

int main()
{
    int n;
    printf("Enter no.of 4 length arrays you want to input: ");
    scanf("%d", &n);

    int arr[n][m];

    printf("Enter %d 4-length arrays\n", n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    
    printf("%d\n", maximumSum(arr, n));
    return 0;
}