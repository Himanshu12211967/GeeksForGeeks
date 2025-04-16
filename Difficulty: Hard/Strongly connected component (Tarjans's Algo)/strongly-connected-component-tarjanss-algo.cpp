//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++

class Solution
{
	public:
	
	void toplogicalsort(int node,vector<int> &visited,stack<int> &st,vector<int> adj[]){
        
        visited[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++){
            int j = adj[node][i];
            if(!visited[j]){
                toplogicalsort(j,visited,st,adj);
            }
        }
        
        st.push(node);
        
    }
    
    void dfs(int node,vector<int> &visited,vector<vector<int>> &adj,vector<int> &temp){
        
        visited[node] = 1;
        temp.push_back(node);
        
        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                dfs(adj[node][i],visited,adj,temp);
            }
        }
        
    }
  
    vector<vector<int>> tarjans(int V,vector<int> adj[]) {
        // code here
        // topological sort
        stack<int> st;
        vector<int> visited(V,0);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                toplogicalsort(i,visited,st,adj);
            }
        }
        //reverse the edges
        vector<vector<int>> adj2(V);
        
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                int u = i;
                int v = adj[i][j];
                adj2[v].push_back(u);
            }
        }
        // pop out element from stack and make dfs
        for(int i=0; i<V; i++){
            visited[i]=0;
        }
        
        vector<vector<int>> ans;
        
        while(!st.empty()){
            
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                vector<int> temp;
                dfs(node,visited,adj2,temp);
                sort(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends