class Solution {
  public:
  
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        
        int kx = knightPos[0]-1;
        int ky = knightPos[1]-1;
        int tx = targetPos[0]-1;
        int ty = targetPos[1]-1;
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{kx,ky},0});
        int dx[] = {-2,-2,-1,1,2,2,1,-1};
        int dy[] = {1,-1,2,2,-1,1,-2,-2};
        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[kx][ky] = 1;
        
        
        while(!q.empty()){
            
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            
            if(x == tx && y == ty) return steps;
            
            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]){
                    visited[nx][ny] = 1;
                    q.push({{nx,ny},steps+1});
                }
            }
            
        }
        
        return -1;
    }
};