//DFS TRAVERSAL
#include <bits/stdc++.h>

using namespace std;

bool helper(int i,int N,vector<vector <int>> adj,vector <int> &vis)
{
    queue <pair<int,int>> q;
    q.push({i,-1});
    vis[i] = 1;

    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();

        int node = curr.first;
        int prev = curr.second;

        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                q.push({it,node});
                vis[it] = 1;
            }
            else if(prev != it)
                return true;
        }
    }
    return false;
}

bool isCycle(int N,vector<vector <int> > adj)
{
    vector <int> vis(N+1,0);
    for(int i=1;i<=N;i++)
    {
        if(!vis[i])
        {
            if(helper(i,N,adj,vis))
                return true;
        }
            
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}