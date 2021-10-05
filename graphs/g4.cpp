//DFS TRAVERSAL
#include <bits/stdc++.h>

using namespace std;

void helper(int i,vector <int> &vis,vector <vector <int>> adj,vector <int> &traversal)
{
    traversal.push_back(i);
    vis[i] = 1;
    for(auto it:adj[i])
    {
        if(!vis[it])
            helper(it,vis,adj,traversal);
    }
}

vector <int> dfs(int n, vector<vector<int>> adj)
{
    vector<int> traversal;
    vector<int> vis(n + 1, 0);

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            helper(i,vis,adj,traversal);
    }

   
    return traversal;
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
    return 0;

    vector <int> ans;
    ans = dfs(n,adj);
}