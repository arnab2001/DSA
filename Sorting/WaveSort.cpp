//Program to find wave sort

/*
Input :
1
7
1 2 3 6 5 4 9


Output :
2 1 6 3 5 4 9 

*/

#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    //Accepting Size 
    cin>>n;
    vector <int> vec(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    //Go to every 2nd element and try to create pick
    for(int i=0;i<n;i+=2)
    {
        //Check for left element
        if(i > 0 && vec[i-1]>vec[i])
            swap(vec[i],vec[i-1]);
        
        //Check for right element
        else if(i <= n-2 && vec[i+1] > vec[i])
            swap(vec[i],vec[i+1]);

    }

    //Print vector
    for(auto i : vec)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    //No of test cases
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}