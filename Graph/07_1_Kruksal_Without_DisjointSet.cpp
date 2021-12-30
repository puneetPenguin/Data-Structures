#include <bits/stdc++.h>
using namespace std;
#define ll long long

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

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
    vector<int> mstPart(n, 0);

    sort(adj.begin(), adj.end(), comp);

    vector<pair<int, int>> result;

    for (int i = 0; i < m; i++)
    {
        if (mstPart[adj[i].u] == 0 || mstPart[adj[i].v] == 0)
        {
            result.push_back({adj[i].u, adj[i].v});
            mstPart[adj[i].u] = 1;
            mstPart[adj[i].v] = 1;
        }
    }

    for (auto it : result)
    {
        cout << it.first << " ---- " << it.second << endl;
    }

    return 0;
}