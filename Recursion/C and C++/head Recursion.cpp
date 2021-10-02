#include<iostream>
using namespace std;
void func(int n)
{
    if (n>0)
    {
        func(n-1);
        cout<<" "<<n;
    }
}

int main()
{
    int x= 3;
    func(x);
    return 0;
}
