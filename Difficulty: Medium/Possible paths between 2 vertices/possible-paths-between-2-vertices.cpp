//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  
    int count = 0;
    
    void dfs(int n,int d,vector<int> adj[],vector<int> &visited){
        
        if(n == d){
            count++;
            return;
        }
        
        visited[n] = true;
        
        for(auto x : adj[n]){
            if(!visited[x]){
                dfs(x,d,adj,visited);
            }
        }
        
        visited[n] = false;
        
    }
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        vector<int> visited(V,0);
        dfs(source,destination,adj,visited);
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends