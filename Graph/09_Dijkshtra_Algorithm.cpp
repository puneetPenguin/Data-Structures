#include <bits/stdc++.h>
using namespace std;

// DIJKSHTRA'S ALGORITHM.
vector<int> shortestPath(vector<pair<int, int>> adj[], int n, int src)
{
    vector<int> distance(n, INT_MAX);
    set<pair<int, int>> s;

    distance[src] = 0;
    s.insert({0, src});

    while(!s.empty()){
        auto ele = s.begin();
        int dist = ele->first;
        int node = ele->second;
        s.erase(ele);

        for(auto it: adj[node]){
            int val = it.first;
            int weight = it.second;

            if(weight+dist < distance[val]){
                auto chk = s.find({distance[val], val});
                if(chk!=s.end()){
                    s.erase(chk);
                }
                distance[val] = dist+weight;
                s.insert({distance[val], val});
            }
        }
    }
    return distance;
}

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

    vector<int> shortest = shortestPath(adj, n, 0);

    for(auto it: shortest){
        cout << it << " ";
    } cout << endl;

    return 0;
}