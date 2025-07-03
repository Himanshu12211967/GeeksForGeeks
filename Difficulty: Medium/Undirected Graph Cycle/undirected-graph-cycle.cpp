class Solution {
  public:
  
    bool dfs(int parent,int node,unordered_map<int,vector<int>> &mapp,vector<int> &visited){
        
        visited[node] = true;
        
        for(auto neigh : mapp[node]){
            if(!visited[neigh]){
                if(dfs(node,neigh,mapp,visited)) return true;
            }
            else if(visited[neigh] && neigh != parent) return true;
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>> mapp;
        
        for(auto val : edges){
            int a = val[0];
            int b = val[1];
            mapp[a].push_back(b);
            mapp[b].push_back(a);
        }
        
        vector<int> visited(V,0);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && dfs(-1,i,mapp,visited)) return true;
        }
        
        return false;
        
    }
};