// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        
        int src = 0;
        int dst = n-1;
        long long count = 0;
        vector<long long int> dist(n,INT_MAX);
        dist[src] = 0;
        int mini = INT_MAX;
        
        map<int,vector<pair<int,int>>> mapp;
        
        for(int i=0; i<roads.size(); i++){
            int a = roads[i][0];
            int b = roads[i][1];
            int w = roads[i][2];
            mapp[a].push_back({b,w});
            mapp[b].push_back({a,w});
        }
        
        queue<pair<int,long long int>> q;
        q.push({src,0});
        
        while(!q.empty()){
            
            int node = q.front().first;
            long long int cost = q.front().second;
            q.pop();
            
            
            for(auto neigh : mapp[node]){
                
                if(neigh.first == dst){
                    if(dist[neigh.first] > cost+neigh.second){
                        dist[neigh.first] = cost+neigh.second;
                        count = 1;
                    }
                    else if(dist[neigh.first] == cost+neigh.second){
                        count++;
                    }
                }
                else{
                    if(dist[neigh.first] >= cost+neigh.second){
                        dist[neigh.first] = cost+neigh.second;
                        q.push({neigh.first,cost+neigh.second});
                    }
                }
            }
            
        }
        
        return count%1000000007;
    }
};