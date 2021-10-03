//Representation of graphs as adjacency matrix
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    // n is numeber of vertices
    //m is number of edges
    cin >> n >> m;
    int adj[n+1][m+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        //u and v denote there is edge between the node u and node v
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }
}