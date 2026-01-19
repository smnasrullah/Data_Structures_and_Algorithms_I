#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int vertices;
    vector<vector<int>> adj;
public:
    Graph(int v)
    {
        vertices = v;
        adj.resize(v);
    }

    void addEdge(int u, int v)
    {
        if(u >= 0 && u < vertices && v >= 0 && v < vertices)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else
        {
            cout << "Invalid edge: " << u << " " << v << endl;
        }
    }

    void display()
    {
        cout << "\nAdjacency List: \n";
        for(int i = 0; i < vertices; i++)
        {
            cout << i << " -> ";
            for(int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j];
                if(j < adj[i].size() - 1) cout << " -> ";
            }
            cout << endl;
        }
    }

    void Depth(int node, vector<bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        for(int neighbor : adj[node])
        {
            if(!visited[neighbor])
            {
                Depth(neighbor, visited);
            }
        }
    }

    void DFS(int start)
    {
        if(start < 0 || start >= vertices)
        {
            cout << "Invalid start node!" << endl;
            return;
        }

        vector<bool> visited(vertices, false);
        cout << "DFS starting from node " << start << ": ";
        Depth(start, visited);
        cout << endl;
    }
};

int main()
{
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    Graph g(n);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.display();

    int start;
    cout << "\nEnter starting node for DFS: ";
    cin >> start;
    g.DFS(start);

    return 0;
}
