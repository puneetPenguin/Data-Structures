#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m; 

    vector<pair<int, int>> adj[n];

    int u, v, w;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Prim's algorithm (0 based value of graphs node)
    int key[n];
    bool mst[n];
    int parent[n];

    for(int i=0; i<n; i++)
        key[i] = INT_MAX, mst[i] = false;
    
    // Taking 0 as starting vertex of MST.
    key[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < n-1; i++){
        int mini = INT_MAX, u;
        // Choosing minimum cost edge for node and storing its value in u.
        for(int v=0; v<n; v++)
            if(mst[v]==false && key[v] < mini)
                mini = key[v], u = v;
        
        mst[u] = true;

        for(auto it: adj[u]){
            int val = it.first;
            int weight = it.second;

            if(mst[val]==false && weight < key[val]){
                key[val] = weight;
                parent[val] = u;
            }
        }
    }

    cout << "MST is: " << endl;
    for(int i=1; i<n; i++){
        cout << parent[i] << " --- " << i << endl;
    }

    return 0;
}