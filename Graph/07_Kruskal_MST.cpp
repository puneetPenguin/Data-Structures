#include <bits/stdc++.h>
using namespace std;

// Creating a node structure to store u, v, and weight.
struct node
{
    int u, v, wt;
    node(int a, int b, int c)
    {
        u = a;
        v = b;
        wt = c;
    }
};

// Disjoint set implementation - findParent and unionComponent.
int findParent(vector<int> parent, int n)
{
    if (parent[n] == n)
        return n;
    // else call recursively and apply path compression by assigning multilevel parent directly to parent.
    return parent[n] = findParent(parent, parent[n]);
}

void unionComponents(vector<int> &rank, vector<int> &parent, int u, int v)
{
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

// Comparator function to sort.
bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int main()
{
    int n, m;
    cin >> n >> m;
    // Create a linear structure to store nodes of graph in order to sort them easily.
    vector<node> adj;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj.push_back(node(u, v, w));
    }

    // Kruskal's algorithm.
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    vector<int> rank(n, 0);

    sort(adj.begin(), adj.end(), comp);

    vector<pair<int, int>> result;

    for (int i = 0; i < m; i++)
    {
        if (findParent(parent, adj[i].u) != findParent(parent, adj[i].v))
        {
            result.push_back({adj[i].u, adj[i].v});
            unionComponents(rank, parent, adj[i].u, adj[i].v);
        }
    }

    for (auto it : result)
    {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}