#include <bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int src, vector<int> adj[], int color[])
{
    queue<int> q;
    q.push(src);
    color[src]=1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
                return false;
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n)
{
    int color[n];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteBfs(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}
void addedge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{

    vector<int> adj[6];
    addedge(adj, 0, 1);
    addedge(adj, 1, 2);
    addedge(adj, 1, 4);
    addedge(adj, 1, 5);
    addedge(adj, 2, 3);
    addedge(adj, 3, 4);
    addedge(adj, 3, 5);

    if (checkBipartite(adj, 6))
    {
        cout << "It is a Bipartite Graph";
    }
    else
    {
        cout << "It is not a Bipartite Graph";
    }
    return 0;
}