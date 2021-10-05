//DFS TRAVERSAL
#include <bits/stdc++.h>

using namespace std;

bool helper(int i,vector <int> &vis,vector <vector <int>> adj,int prev)
{
    vis[i] = 1;
    for(auto it:adj[i])
    {
        if(!vis[it])
            if(helper(it,vis,adj,it))
                return true;
        else if(prev != it)
            return true;
    }
}

bool checkCycle(int n, vector<vector<int>> adj)
{
    vector<int> traversal;
    vector<int> vis(n + 1, 0);
    int prev(-1);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            if(helper(i,vis,adj,prev))
                return true;
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