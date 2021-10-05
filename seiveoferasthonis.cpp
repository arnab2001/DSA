#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<stdlib.h>
#include <sstream>
#include<cstdlib>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;
typedef long long int ll;
typedef long double lld;
 
/*#define debug(x);
printf(x);*/
 
void init()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt" , "r"  ,stdin); 
  freopen("output.txt" , "w" ,stdout);
  #endif
 
}
 
void  debug_()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt" , "r"  ,stdin); 
  freopen("output.txt" , "w" ,stdout);
  #endif
  #ifndef ONLINE_JUDGE
  freopen("error.txt","w",stderr);
  #endif 
  
} 


const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
int max(int a, int b) {if (a > b) return a; else return b;}
int min(int a, int b) {if (a < b) return a; else return b;}
 
 
void precision(int a) 
{
  cout << setprecision(a) << fixed;
}


  vector<int> sieve(int n) 
{
int*arr = new int[n + 1](); 
vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); 
for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1;}
return vect;
}

int main()
{
  init();
  int n;
  cin >> n;
  vector<int> v=sieve(n);

  for(int i=0;i<v.size();i++)
  {
    cout << v[i] << endl;
  }

  return 0;

}
