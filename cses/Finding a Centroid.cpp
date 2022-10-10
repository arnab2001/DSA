// Centroid of a tree is a node such that when it is appointed the root of the tree, each subtree has at most floor(n/2) nodes (n = number of nodes in the graph).
// A vertex is a centroid of a tree only when you cut this vertex (remove it and remove all edges from this vertex),
// the size of the largest connected component of the remaining graph is the smallest possible (which is at most floor(n/2))
// A tree may have one centroid or may have two centroids. If it has two centroids, they are always connected.

#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F(w,x,y) for(ll w=x; w<y; w++)
#define endl "\n"
#define mod 1000000007
typedef long long ll;
typedef long double ld;
using namespace std;
 
ll n;
vector <ll> adj[200001];
ll subtreeSize[200001];
int vis[200001];
 
void dfs(ll node)
{
    subtreeSize[node]=1;
 
    for(auto x:adj[node])
    {
        if(subtreeSize[x]==-1)
        {
            dfs(x);
            subtreeSize[node]+=subtreeSize[x];
        }
    }
}
 
ll centroid(ll node)
{
    vis[node]=1;
 
    for(auto x:adj[node])
    {
        if(!vis[x])
        {
            if(subtreeSize[x]>(n/2))
                return centroid(x);
        }
    }
 
    return node;
}
 
void play()
{
    memset(subtreeSize,-1,sizeof(subtreeSize));
    ll a,b;
    cin>>n;
    F(i,1,n)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
 
    dfs(1);
 
    cout<<centroid(1);
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
    //cin>>t;
    F(i,1,t+1)
    {
        //cout<<"Case #"<<i<<": ";
        play();
    }
    return 0;
}
