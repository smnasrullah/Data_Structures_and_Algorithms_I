#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int n;  // number of nodes
    unordered_map<int,vector<int>> adj;

    Graph(int n){
        this->n = n;
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u); // only for undirected graph
    }

    // Breadth First Search starting from node s
    void BFS(int s){
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(s);
        visited[s] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout << u << " ";

            for(int v : adj[u]){
                if(visited[v] == false){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
};

int main(){

    int n = 6;
    Graph g(n);

    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(2,3);
    g.addEdge(2,1);
    g.addEdge(3,1);
    g.addEdge(5,1);
    g.addEdge(5,4);
    g.addEdge(1,4);

    g.BFS(0);   // BFS starting from node 0

    return 0;
}
