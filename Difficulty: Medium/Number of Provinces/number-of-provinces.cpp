//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
  public:
 
    
    void solve(int node, vector<vector<int>> &adj, vector<bool> &visited){
        
        visited[node] = true;
        
        for(int i=0; i<adj[node].size(); i++){
            
            if(visited[i]) continue; 
            
            int isconnected = adj[node][i];
            
            if(isconnected){
                solve(i,adj,visited);
            }
            
        }
   
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> visited(V,false);
        int provinces = 0;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                solve(i,adj,visited);
                provinces++;
            }
        }

        return provinces;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends