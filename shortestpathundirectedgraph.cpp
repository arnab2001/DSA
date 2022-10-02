//BFS
#include <bits/stdc++.h>
using namespace std;
vector<int> BFS(int n, int src, vector<int> adj[])
{
    vector<int> Dist(n, INT_MAX);
    queue<int> q;
    q.push(src);
    Dist[src] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (Dist[it] > 1 + Dist[node])
            {
                Dist[it] = 1 + Dist[node];
                q.push(it);
            }
        }
    }
    return Dist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src;
    cout << "Enter Source\n";
    cin >> src;
    vector<int> res = BFS(n, src, adj);
    cout << "Shortest Distances of various Nodes from the source are:\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << "->" << res[i] << endl;
    }
}