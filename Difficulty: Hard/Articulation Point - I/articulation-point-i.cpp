//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution {
  public:
  
    int count = 0;

    void solve(int parent,int node, vector<int> &low, vector<int> &disc, vector<int> &visited, vector<int>adj[], vector<int> &ans){
        
        low[node] = disc[node] = count++;
        visited[node] = true;
        int children = 0;
        
        for(auto child : adj[node]){
            
            if(child == parent) continue;
            
            else if(!visited[child]){
                children++;
                solve(node,child,low,disc,visited,adj,ans);
                low[node] = min(low[node],low[child]);
                if( (low[child] >= disc[node] && parent != -1)  || (children > 1 && parent == -1) ){
                    ans.push_back(node);
                }
            }
            
            else{
                low[node] = min(low[node],disc[child]);
            }
            
        }
        
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        
        vector<int> low(V);
        vector<int> disc(V);
        
        vector<int> ans;
        vector<int> visited(V,0);
        
        for(int i=0; i<V; i++){
            if(!visited[i])
            solve(-1,i,low,disc,visited,adj,ans);
        }
        
        if(ans.empty()) return {-1};
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        
        return ans;
        
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends