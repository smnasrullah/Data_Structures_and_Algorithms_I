#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int n;  // number of nodes
    unordered_map<int,vector<int>> adj;
    vector<int> indegree;

    Graph(int n){
        this->n = n;
        indegree.resize(n, 0);
    }

    // Add edge u → v
    void addEdge(int u, int v){
        adj[u].push_back(v);
        indegree[v]++;    // update indegree of v
    }

    // Topological Sort (Kahn's Algorithm)
    void topological_sort(){
        queue<int> q;

        // push all nodes with indegree 0
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout << u << " ";

            // reduce indegree of adjacent nodes
            for(int v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
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

    g.topological_sort();

    return 0;
}
