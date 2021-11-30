#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
    if(a <= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int max(int a, int b)
{
    if(a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
 
int minProdSubset(int a[], int n)
{
    if (n == 1)
        return a[0];
    
    else
    {
        int neg_max = INT_MIN;
        int pos_min = INT_MAX;
        int count_neg = 0, count_zero = 0;
        int prod = 1;
        for (int i = 0; i < n; i++) 
        {
            if (a[i] > 0)
            {
                pos_min = min(pos_min, a[i]);
            }
            else if (a[i] < 0) 
            {
                count_neg++;
                neg_max = max(neg_max, a[i]);
            }
            else 
            {
                count_zero++;
                continue;
            }
            prod = prod * a[i];
        }

        if (count_zero == n || (count_neg == 0 && count_zero > 0))
            return 0;

        if (count_neg == 0)
            return pos_min;
    
        if (!(count_neg & 1) && count_neg != 0) 
        {
            prod = prod / neg_max;
        }
    
        return prod;
    }
}
 
int main()
{
    int num;
    printf("Enter the size of the array: ");
    scanf("%d", &num);
    int arr[num];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", minProdSubset(arr, num));
    return 0;
}
