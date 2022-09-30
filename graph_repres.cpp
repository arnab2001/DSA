#include <stdio.h>
 
int linear_search(int a[], int n, int find) {
   int c;
 
   for (c = 0 ;c < n ; c++ ) {
      if (a[c] == find)
         return c;
   }
 
}
 
int main()
{
   long array[100], search, c, n, position;
 
   printf("Input number of elements in array\n");
   scanf("%ld", &n);
 
   printf("Input %d numbers\n", n);
 
   for (c = 0; c < n; c++)
      scanf("%ld", &array[c]);
 
   printf("Input a number to search\n");
   scanf("%ld", &search);
 
   position = linear_search(array, n, search);
 
   if (position == -1)
      printf("%d isn't present in the array.\n", search);
   else
      printf("%d is present at location %d.\n", search, position+1);
 
   return 0;
}
 
