//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Position this line where user code will be pasted.
class Solution {
  public:
  
    void toplogicalsort(int node,vector<int> &visited,stack<int> &st,vector<vector<int>> &adj){
        
        visited[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++){
            int j = adj[node][i];
            if(!visited[j]){
                toplogicalsort(j,visited,st,adj);
            }
        }
        
        st.push(node);
        
    }
    
    void dfs(int node,vector<int> &visited,vector<vector<int>> &adj){
        
        visited[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                dfs(adj[node][i],visited,adj);
            }
        }
        
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        // topological sort
        int vertex = adj.size();
        stack<int> st;
        vector<int> visited(vertex,0);
        for(int i=0; i<vertex; i++){
            if(!visited[i]){
                toplogicalsort(i,visited,st,adj);
            }
        }
        //reverse the edges
        vector<vector<int>> adj2(vertex);
        
        for(int i=0; i<vertex; i++){
            for(int j=0; j<adj[i].size(); j++){
                int u = i;
                int v = adj[i][j];
                adj2[v].push_back(u);
            }
        }
        // pop out element from stack and make dfs
        for(int i=0; i<vertex; i++){
            visited[i]=0;
        }
        
        int ans = 0;
        
        while(!st.empty()){
            
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                dfs(node,visited,adj2);
                ans++;
            }
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends