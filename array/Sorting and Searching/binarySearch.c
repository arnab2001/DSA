#include <stdio.h>

int main()
{
    int arr[100], i = 0, mid, high, low, x, n, swap, c, d;

    printf("Enter the size of array\n");
    scanf("%d", &n);
    printf("Enter the numbers of the array \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (c = 0; c < n - 1; c++)
    {
        for (d = 0; d < n - c - 1; d++)
        {
            if (arr[d] > arr[d + 1]) 
            {
                swap = arr[d];
                arr[d] = arr[d + 1];
                arr[d + 1] = swap;
            }
        }
    }

    printf("Enter the number you want to find \n");
    scanf("%d", &x);

    low = 0;
    high = n - 1;
    mid = (high + low) / 2;

    while (low <= high)
    {
        if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else if (arr[mid] == x)
        {
            printf("Element Found In the Array at %d position", mid + 1);
            break;
        }
        else
        {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    if (low > high)
    {
        printf("Element not found the array");
    }

    return 0;
}