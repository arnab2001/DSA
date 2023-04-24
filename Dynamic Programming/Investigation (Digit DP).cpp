// https://lightoj.com/problem/investigation

#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F(w,x,y) for(ll w=x; w<y; w++)
#define endl "\n"
#define mod 1000000007
typedef int ll;
typedef long double ld;
using namespace std;

ll dp[11][90][90][2];
ll m;

ll solve(string s)
{
    memset(dp,0,sizeof(dp));

    ll n=s.length();

    dp[0][0][0][1]=dp[0][0][0][0]=1;

    for(ll i=1; i<=n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            for(ll k=0; k<m; k++)
            {
                ll ub=s[n-i]-'0';
                for(ll digit=0; digit<=9; digit++)
                {
                    if(digit<=ub)
                        dp[i][j][k][1]+=dp[i-1][(digit+j)%m][(digit+k*10)%m][1&(digit==ub)];
                    dp[i][j][k][0]+=dp[i-1][(digit+j)%m][(digit+k*10)%m][0];
                }
            }
        }
    }

    return dp[n][0][0][1];
}

void play()
{
    ll lvalue;
    string r;
    cin>>lvalue>>r>>m;
    lvalue--;
    string l=to_string(lvalue);

    if(m==0 || m>=90)
    {
        cout<<0<<endl;
        return;
    }

    cout<<solve(r)-solve(l)<<endl;
}

int main()
{
    //freopen("milkvisits.in","r",stdin);
    //freopen("milkvisits.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //pre();
    ll t;
    t=1;
    cin>>t;
    F(i,1,t+1)
    {
        cout<<"Case "<<i<<": ";
        play();
    }
    return 0;
}
