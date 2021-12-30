#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<int> adj[], int src, int n){
    vector<int> distance(n, INT_MAX);
    queue<int> q;

    distance[src] = 0;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(distance[node]+1 < distance[it]){
                distance[it] = distance[node]+1;
                q.push(it);
            }
        }
    }
    return distance;
}

int main()
{
    int n, m;
    cout << "Enter values of n and m:" << endl;
    cin >> n >> m; 

    vector<int> adj[n+1];

    cout << "Enter items of graph:" << endl;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src;
    cout << "Enter source node:";
    cin >> src; 

    vector<int> shortestDistance = shortestPath(adj, src, n);

    cout << "Shortest distance from source node " << src << " are:" << endl;
    for(int i=0; i<n; i++){
        cout << i << " --> " << shortestDistance[i] << endl;
    }

    return 0;
}