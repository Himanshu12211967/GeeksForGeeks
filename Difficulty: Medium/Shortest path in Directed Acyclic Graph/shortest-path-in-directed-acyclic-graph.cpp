//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        vector<int> dist(V,INT_MAX);
        dist[0] = 0;
        map<int,vector<pair<int,int>>> graph;
        
        for(int i=0; i<E; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            graph[u].push_back({v,d});
        }
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        while(!q.empty()){
            
            int node = q.front().first;
            int cost = q.front().second;
            q.pop();
            
            for(auto child : graph[node]){
                
                if(dist[child.first] > cost+child.second){
                    dist[child.first] = cost+child.second;
                    q.push({child.first,cost+child.second});
                }
                
            }
            
        }
        
        for(int i=0; i<V; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        
        return dist;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends