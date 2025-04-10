//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
    int count = 0;
  
    void solve(int parent, int node, vector<int> &low, vector<int> &disc, vector<int> &visited, vector<vector<int>> &ans, map<int,vector<int>> &list){
        
        low[node] = disc[node] = count++;
        visited[node] = true;
        
        for(auto child : list[node]){
            
            if(child == parent) continue;
            
            else if(!visited[child]){
                solve(node,child,low,disc,visited,ans,list);
                low[node] = min(low[node],low[child]);
                if(low[child] > disc[node]){
                    ans.push_back({node,child});
                }
            }
            
            else{
                low[node] = min(low[node],low[child]);
            }
            
        }
        
        
    }
  
    vector<vector<int>> criticalConnections(int v, vector<vector<int>>& edges) {
        // Code here
        vector<int> low(v);
        vector<int> disc(v);
        vector<int> visited(v,0);
        vector<vector<int>> ans;
        
        map<int, vector<int>> list;
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            list[u].push_back(v);
            list[v].push_back(u);
        }
        
        for(int i=0; i<v; i++){
            if(!visited[i]){
                solve(-1,i,low,disc,visited,ans,list);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> edges;
        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<vector<int>> ans = obj.criticalConnections(v, edges);
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i][0] > ans[i][1])
                swap(ans[i][0], ans[i][1]);
        }

        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i][0] << " " << ans[i][1] << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends