//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
  
    void dfs(int node, map<int,vector<int>> &graph, vector<int> &visited){
        
        visited[node] = true;
        
        for(auto child : graph[node]){
            if(!visited[child]){
                dfs(child,graph,visited);
            }
        }
    
    }
  
    int isCircle(vector<string> &arr) {
        // code here
        
        map<int,vector<int>> graph;
        vector<int> degree(26,0);
        
        for(int i=0; i<arr.size(); i++){
            
            string str = arr[i];
            int u = str[0]-'a';
            int v = str[str.length()-1]-'a';
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        
        for(int i=0; i<26; i++){
            if(degree[i]%2 != 0) return 0;
        }
        
        vector<int> visited(26,0);
        int node = arr[0][0]-'a';
        dfs(node,graph,visited);
        
        for(int i=0; i<26; i++){
            if(!visited[i] && degree[i] != 0) return 0;
        }
        
        return 1;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends