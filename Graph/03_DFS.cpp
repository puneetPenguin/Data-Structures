#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> *adj, vector<int> &vis, vector<int> &result, int i){
    vis[i] = 1;
    result.push_back(i);
    for(auto it: adj[i]){
        if(!vis[it])
            dfs(adj, vis, result, it);
    }
}

vector<int> dfsOfGraph(vector<int> adj[], int n){
    vector<int> vis(n+1, 0);
    vector<int> result;
    for(int i=1; i<=n; i++){
        if(!vis[i])
            dfs(adj, vis, result, i);
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m; 

    vector<int> adj[n+1];

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dfs = dfsOfGraph(adj, n);

    for(auto i: dfs){
        cout << i << " ";
    } cout << endl;

    return 0;
}