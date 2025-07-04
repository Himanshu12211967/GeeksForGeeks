class Solution {
  public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        // Code here
        if(n == 1) return 0;
        vector<int> dist(n,INT_MAX);
        int src = edges[0][0];
        dist[src] = 0;
        
        for(int i=1; i<n; i++){
            
            for(int i=0; i<edges.size(); i++){
                
                int a = edges[i][0];
                int b = edges[i][1];
                int w = edges[i][2];
                
                if(dist[a] == INT_MAX) continue;
                
                
                if(dist[b] > dist[a] + w) dist[b] = dist[a] + w;
                
            }
        }
        
        
        for(int i=0; i<edges.size(); i++){
                   
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];
                
            if(dist[a] == INT_MAX) continue;
         
            if(dist[b] > dist[a] + w) return 1;
                
        }
            
        return 0;
    }
};