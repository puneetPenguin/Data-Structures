#include <bits/stdc++.h>
using namespace std;

bool detectCycle(vector<int> visited, vector<int> adj[], int i)
{
    // Create a queue to store all adjacent items to perform bfs.
    queue<pair<int, int>> q;
    q.push({i, -1});
    visited[i] = 1;

    while (!q.empty())
    {
        auto node = q.front().first;
        auto parent = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                q.push({it, node});
                visited[it] = 1;
            }
            else if(parent != it)
            {
                return true;
            }
        }
    }
    return false;
}

bool bfs(vector<int> adj[], int n)
{
    // Create a visited array init by 0.
    vector<int> visited(n + 1, 0);

    // Run a loop to cover all components in order to take all disconnected graphs.
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (detectCycle(visited, adj, i))
                return true;
        }
    }
    return false;
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

    if (bfs(adj, n)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}