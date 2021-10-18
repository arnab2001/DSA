#include <stdio.h> 
#include <time.h>
#include<math.h> 
int f1(int n)
{
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0) 
        c++;
    }
    if (c == 2) 
    printf("It is a prime number");
    else printf("Not a prime number");
}
int f2(int n) 
{
    static int i = 2;
    if (n== 0||n==1)
    {
        return 1;
    } 
    if (n == i)
    return 0; 
    if (n % i == 0)
    return 1;
    i++;
    return f2(n);
}int f3(int n)
{
    if (n <= 1)
    return 1;
    for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
    return 1;
    return 0;
}
int main()
{
    clock_t start, end;
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    start = clock();
    f1(num);
    end = clock();
    printf("\ntime taken in sec for 1st algo =%lf", ((double)end - (double)start) / CLOCKS_PER_SEC);
    start = clock();
    f2(num);
    end = clock();
    printf("\ntime taken in sec for 2nd algo =%lf", ((double)end - (double)start) / CLOCKS_PER_SEC);
    start = clock();
    f3(num); 
    end = clock();
    printf("\ntime taken in sec for 3rd algo =%lf", ((double)end-(double)start)/CLOCKS_PER_SEC);
    
}
