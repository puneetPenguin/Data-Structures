#include <bits/stdc++.h>
using namespace std;

bool colored(int color[], vector<int> adj[], int i)
{
    // Create a queue to store all adjacent items to perform bfs.
    queue<int> q;
    q.push(i);
    color[i] = 1;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if(color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n)
{
    // Color array.
    int color[n+1];
    // Initialise color array with -1. Note that 1 and 0 will denote colors.
    memset(color, -1, sizeof color); 

    // Run a loop to cover all components in order to take all disconnected graphs.
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!colored(color, adj, i))
                return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (checkBipartite(adj, n)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}