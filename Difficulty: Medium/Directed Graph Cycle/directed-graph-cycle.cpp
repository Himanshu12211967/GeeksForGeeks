class Solution {
  public:
  
    bool dfs(int node,map<int,vector<int>> &mapp,vector<int> &visited){
        
        visited[node] = true;
        
        for(auto child : mapp[node]){
            if(!visited[child]){
                if(dfs(child,mapp,visited)) return true;
            }
            else return true;
        }
        
        visited[node] = false;
        return false;
        
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> visited(V,0);
        map<int,vector<int>> mapp;
        
        for(auto val : edges){
            int a = val[0];
            int b = val[1];
            mapp[a].push_back(b);
        }
        
        for(int i=0; i<V; i++){
            if(dfs(i,mapp,visited)) return true;
        }
        
        return false;
        
    }
};