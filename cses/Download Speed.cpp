// The Edmonds-Karp algorithm is an implementation of the Ford-Fulkerson method for computing a maximal flow in a flow network.

#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int c[501][501];
int flowPassed[501][501];
vector <int> g[501];
int parList[501];
 
bool bfs(int sNode, int eNode)
{
    memset(parList,-1,sizeof(parList));
    queue <int> q;
    q.push(sNode);
    parList[sNode]=-1;
    while(!q.empty())
    {
        int currNode=q.front();
        q.pop();
        for(int i=0; i<g[currNode].size(); i++)
        {
            int to=g[currNode][i];
            if(parList[to]==-1 && c[currNode][to]>flowPassed[currNode][to])
            {
                parList[to]=currNode;
                if(to==eNode)
                {
                    return true;
                }
                q.push(to);
            }
        }
    }
    return false;
}

int edmondsKarp(int sNode, int eNode)
{
    int maxFlow=0;
    while(bfs(sNode, eNode))
    {
        int flow=LONG_LONG_MAX;
        int currNode=eNode;
        while(currNode!=sNode)
        {
            int prevNode=parList[currNode];
            flow=min(flow, c[prevNode][currNode]-flowPassed[prevNode][currNode]);
            currNode=prevNode;
        }
        maxFlow+=flow;
        currNode=eNode;
        while(currNode!=sNode)
        {
            int prevNode=parList[currNode];
            flowPassed[prevNode][currNode]+=flow;
            flowPassed[currNode][prevNode]-=flow;
            currNode=prevNode;
        }
    }
    return maxFlow;
}
 
signed main()
{
    int n,m;
    cin>>n>>m;
    int source=1, sink=n;
    for(int i=0; i<m; i++)
    {
        int u,v,cap;
        cin>>u>>v>>cap;
        c[u][v]+=cap;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int maxFlow=edmondsKarp(source,sink);
    cout<<maxFlow<<endl;
}
