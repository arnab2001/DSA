#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 
    int i,j,k;
    int x,y,z;
    int n1,n2;
    int result1,result2,result;
 
    cout<<"Enter the number of elements in the first sequence ";
    cin>>n1;
 
    result=result1=result2=0;
 
    vector<int> a(n1);
    cout<<"Enter the values of the first sequence"<<endl;
    for(i=0;i<n1;i++)
    {
        cin>>a[i];
    }
 
    j=0;
 
    cout<<"Enter the number of elements in the second sequence ";
    cin>>n2;
    vector<int> b(n2);
 
    cout<<"Enter the values of the second sequence"<<endl;
    for(i=0;i<n2;i++)
    {
       cin>>b[i]; 
       result2+=b[i];
 
       while(j<n1 && a[j]<b[i])
       {
           result1+=a[j];
           j++;
       }
 
       if(j<n1 && a[j]==b[i])
       {
            result1+=a[j];
            result+=max(result1,result2);     
 
            //reset
            result1=0;
            result2=0;
            j++;
       }
    }
 
 
    while(j<n1)
    {
        result1+=a[j];
        j++;
    }
 
    result+=max(result1,result2);     
 
    cout<<"The maximum sum of data obtained by walking over them is "<<endl;
    cout<<result<<endl;
 
    return 0;
}