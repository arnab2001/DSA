#include<bits/stdc++.h>
#define ll long long
#define mod 1e9+7
using namespace std;

int main()
{
    
    string s="aaaabbaa";
        int len=s.size();
    if(len<2)
       cout<<s;
    else
    {
        int maxi=0,start=0;
        for(int i=0;i<len-maxi/2;i++)
        {
            int j=i;
            int k=i;
            while(k<len-1 && s[k]==s[k+1])
            k++;
            while(j>0 && k<len-1 && s[j-1]==s[k+1])
            {
                j--;
                k++;
            }
            int newl=k-j+1;
            if(newl>maxi)
            {
                maxi=newl;
                start=j;
            }
        }
         string res="";
        while(maxi--)
        {
            res=res+s[start];
            start++;
        }
        cout<< res;
    }
      
    
    return 0;
}
