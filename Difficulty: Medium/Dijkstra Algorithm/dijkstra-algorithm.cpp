//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int V = adj.size();
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        
        queue<pair<int,int>> q;
        q.push({src,0});
        
        while(!q.empty()){
            
            int node = q.front().first;
            int wt = q.front().second;
            q.pop();
            
            for(int i=0; i<adj[node].size(); i++){
                
                pair<int,int> p = adj[node][i];
                int neighbour = p.first;
                int neighcost = p.second;
                
                if(dist[neighbour] > wt+neighcost){
                    dist[neighbour] = wt+neighcost;
                    q.push({neighbour,wt+neighcost});
                }
                
            }
            
        }
        
        return dist;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends