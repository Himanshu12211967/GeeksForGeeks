//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    void dfs(int node, map<int,vector<int>> &list, vector<int> &visited){
        
        visited[node] = true;
        
        for(auto child : list[node]){
            if(!visited[child]) dfs(child,list,visited);
        }
        
    }
  
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        
        map<int,vector<int>> list;
        vector<int> visited(V,0);
        
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if((a == c && b == d) || (a == d && b == c)) continue;
            list[a].push_back(b);
            list[b].push_back(a);
        }
        
        dfs(c,list,visited);
        return !visited[d];
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends