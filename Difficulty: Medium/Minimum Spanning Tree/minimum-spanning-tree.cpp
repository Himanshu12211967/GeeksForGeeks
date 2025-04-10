//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        
        map<int,vector<pair<int,int>>> graph;
        
        for (int i = 0; i < V; i++) {
            for (auto &edge : adj[i]) {
                int u = i;
                int v = edge[0];
                int w = edge[1];
                graph[u].push_back({v, w});
                graph[v].push_back({u, w});  // Undirected graph: Add both directions
            }
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int Cost = 0;
        vector<int> visited(V,0);
        visited[0] = true;
        
        while(!pq.empty()){
            
            int c = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(!visited[node]){
                Cost += c;
                visited[node] = true;
            }
            
            for(auto child : graph[node]){
                int neigh = child.first;
                int wt = child.second;
                if(!visited[neigh])
                pq.push({wt,neigh});
            }
            
        }
        
        return Cost;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends