#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        cout<<ch;
        cout<<endl;
    }
        return 0;
}

// } Driver Code Ends



//return the address of the string
char* reverse(char *S, int len)
{
    stack<char> stack;
    for (int i=0;i<len;i++){
        stack.push(S[i]);
    }
    int i=0;
    while (!stack.empty()){
        S[i]=stack.top();
        stack.pop();
        i++;
    }
    return S;
}