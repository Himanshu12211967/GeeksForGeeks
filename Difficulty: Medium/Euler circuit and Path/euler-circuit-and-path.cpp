//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    
    void dfs(int node,vector<int> &visited,vector<int>adj[]){
        
        visited[node] = true;
        
        for(auto child : adj[node]){
            if(!visited[child]){
                dfs(child,visited,adj);
            }
        }
        
    }

	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    vector<int> degree(V,0);
	    int odd_degree = 0;
	    
	    for(int i=0; i<V; i++){
	        degree[i] = adj[i].size();
	        if(degree[i]%2 != 0) odd_degree++;
	    }
	    
	    if(odd_degree != 0 && odd_degree != 2) return 0;
	    
	    vector<int> visited(V,0);
	    dfs(0,visited,adj);
	    
	    for(int i=0; i<V; i++){
	        if(!visited[i] && degree[i] != 0) return 0;
	    }
	    
	    if(odd_degree == 0) return 2;
	    return 1;
	    
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends