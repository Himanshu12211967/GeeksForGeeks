class Solution {
  public:
  
    int ispossible(int node, int n,map<int,vector<int>> &mapp, vector<int> &visited, int count){
        
        count++;
        visited[node] = true;
        if(count == n) return true;
        
        for(auto neigh : mapp[node]){
            if(!visited[neigh]){
                if(ispossible(neigh,n,mapp,visited,count)) return true;
            }
        }
        
        count--;
        visited[node] = false;
        return false;
        
    }
  
    bool check(int n, int m, vector<vector<int>> edges) {
        // code here
        
        map<int,vector<int>> mapp;
        
        for(int i=0; i<m; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            mapp[a].push_back(b);
            mapp[b].push_back(a);
        }
    
        
        for(int i=1; i<=n; i++){
            vector<int> visited(n+1,0);
            if(ispossible(i,n,mapp,visited,0)) return true;
        }
        
        return false;
        
    }
};
