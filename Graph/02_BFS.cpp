#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> adj[], int n)
{
    vector<int> bfsGraph;
    // Create a visited array init by 0.
    vector<int> visited(n + 1, 0);
    // Create a queue to store all adjacent items to perform bfs.
    queue<int> q;

    // Run a loop to cover all components in order to take all disconnected graphs.
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = 1;

            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                bfsGraph.push_back(temp);

                for (auto it : adj[temp])
                {
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
    return bfsGraph;
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

    vector<int> bfsGraph = bfs(adj, n);

    for(auto i: bfsGraph){
        cout << i << " ";
    } cout << endl;

    return 0;
}