//BFS TRAVERSAL
#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(int n, vector<vector<int>> adj)
{
    vector<int> traversal;
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)        // this for loop is simply for graph with diffrent components
    {
        if (vis[i] == 0)
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();

                traversal.push_back(curr);

                for (auto it : adj[curr])
                {
                    if (vis[it] == 0)
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
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
    ans = bfs(n,adj);
}