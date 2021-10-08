#include <stdio.h>
#include <conio.h>

int main()
{
  int a[1000], i, n, min, max;

  printf("Enter size of the array : ");
  scanf("%d", &n);

  printf("Enter elements in array : ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  min = max = a[0];
  for (i = 1; i < n; i++)
  {
    if (min > a[i])
      min = a[i];
    if (max < a[i])
      max = a[i];
  }
  printf("minimum of array is : %d", min);
  printf("\nmaximum of array is : %d", max);

  return 0;
}

// #include<stdio.h>
// struct pair
// {
//   int min;
//   int max;
// };

// struct pair getMinMax(int arr[], int n)
// {
//   struct pair minmax;
//   int i;

//   if (n == 1)
//   {
//      minmax.max = arr[0];
//      minmax.min = arr[0];
//      return minmax;
//   }

//   if (arr[0] > arr[1])
//   {
//       minmax.max = arr[0];
//       minmax.min = arr[1];
//   }
//   else
//   {
//       minmax.max = arr[1];
//       minmax.min = arr[0];
//   }

//   for (i = 2; i<n; i++)
//   {
//     if (arr[i] >  minmax.max)
//       minmax.max = arr[i];

//     else if (arr[i] <  minmax.min)
//       minmax.min = arr[i];
//   }

//   return minmax;
// }

// int main()
// {
//   int arr[] = {1000, 11, 445, 1, 330, 3000};
//   int arr_size = 6;
//   struct pair minmax = getMinMax (arr, arr_size);
//   printf("nMinimum element is %d", minmax.min);
//   printf("nMaximum element is %d", minmax.max);
//   getchar();
// }
